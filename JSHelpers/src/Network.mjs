class Network {
  constructor(url) {
    this.url = url;
    this.jwt = null;
    this.onReceive = null;
    this.onDisconnect = null;
    this.opened = false;
    this.loggedIN = false;
  }

  connect() {
    this.ws = new WebSocket(`ws://${this.url}`);
    this.setMethods();
  }

  _ftypeOf(value) {
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

  _getBytes_String(payload) {
    return new TextEncoder().encode(payload);
  }

  _getBytes_Array(payload) {
    return new Uint8Array(payload)
  }

  _getBytes_Object(payload) {
    return this._getBytes_String(JSON.stringify(payload))
  }

  _getBytes(payload) {
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

  send(data) {
    const bytes = this._getBytes(data)
    if(!bytes) {
      return ;
    }
    this.ws.send(bytes)
  }

  extractData(response) {
    const decoder = new TextDecoder("utf-8");
    const code = JSON.parse(decoder.decode(response))
    return code['status'] === 200
  }

  setMethods() {
    let parent = this;
    this.ws.binaryType = "arraybuffer";
    this.ws.onopen = () => {
      parent.opened = true;
      this.login();
    };

    this.ws.onmessage = (event) => {
      if(!this.loggedIN && this.extractData(event.data)) {
        this.loggedIN = true;
        return ;
      }
      if(!this.loggedIN) {
        this.ws.close();
      }
      if(!this.onReceive) {
        return ;
      }
      this.onReceive(event.data);
    };

    this.ws.onerror = (err) => {
      console.error("WebSocket error", err);
    };

    this.ws.onclose = (event) => {
      console.log("Disconnected!")
      if(!this.onDisconnect) {
        return ;
      }
      this.onDisconnect(event.code, event.reason);
    };
  }

  addJWTAuth(jwt) {
    this.jwt = jwt;
  }

  login() {
    if(!this.jwt || !this.opened) {
      return ;
    }
    const encoder = new TextEncoder(); 
    const bytes = encoder.encode(JSON.stringify({
      "token": this.jwt
    }));
    this.ws.send(bytes)
  }
}