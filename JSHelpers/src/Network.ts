export default class Network {
  url: string;
  jwt: string | null;
  onReceive: any;
  onDisconnect: any;
  opened: boolean;
  loggedIN: boolean;
  ws: WebSocket | null;

  constructor(url: string) {
    this.url = url;
    this.jwt = null;
    this.onReceive = null;
    this.onDisconnect = null;
    this.opened = false;
    this.loggedIN = false;
    this.ws = null;
  }

  connect() {
    this.ws = new WebSocket(`ws://${this.url}`);
    this.setMethods();
  }

  _ftypeOf(value: any) {
    if (typeof value === "string") { 
      return "string";
    }
    if (Array.isArray(value)) { 
      return "array";
    }
    if (value !== null && typeof value === "object") { 
      return "object";
    }
    return "other";
  }

  _getBytes_String(payload: any) {
    return new TextEncoder().encode(payload);
  }

  _getBytes_Array(payload: any) {
    return new Uint8Array(payload)
  }

  _getBytes_Object(payload: any) {
    return this._getBytes_String(JSON.stringify(payload))
  }

  _getBytes(payload: any) {
    const type = this._ftypeOf(payload);
    switch(type) {
      case "string": {
        return this._getBytes_String(payload)
      }
      case "array": {
        return this._getBytes_Array(payload)
      }
      case "object": {
        return this._getBytes_Object(payload)
      }
    }
    return null;
  }

  send(data: any) {
    const bytes = this._getBytes(data)
    if(!bytes) {
      return ;
    }
    if(this.ws) {
      this.ws.send(bytes);
    }
  }

  extractData(response: any) {
    const decoder = new TextDecoder("utf-8");
    const code = JSON.parse(decoder.decode(response))
    return code['status'] === 200
  }

  setMethods() {
    let parent = this;
    if(!this.ws) {
      return ;
    }
    this.ws.binaryType = "arraybuffer";
    this.ws.onopen = () => {
      parent.opened = true;
      this.login();
    };

    this.ws.onmessage = (event) => {
      if(!parent.loggedIN && parent.extractData(event.data)) {
        parent.loggedIN = true;
        return ;
      }
      if(parent.ws && !parent.loggedIN) {
        parent.ws.close();
      }
      if(!parent.onReceive) {
        return ;
      }
      parent.onReceive(event.data);
    };

    this.ws.onerror = (err) => {
      console.error("WebSocket error", err);
    };

    this.ws.onclose = (event) => {
      console.log("Disconnected!")
      if(!parent.onDisconnect) {
        return ;
      }
      parent.onDisconnect(event.code, event.reason);
    };
  }

  addJWTAuth(jwt: string) {
    this.jwt = jwt;
  }

  login() {
    if(!this.jwt || !this.opened || !this.ws) {
      return ;
    }
    const encoder = new TextEncoder(); 
    const bytes = encoder.encode(JSON.stringify({
      "token": this.jwt
    }));
    this.ws.send(bytes)
  }
}