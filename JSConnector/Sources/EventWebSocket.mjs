import { eventParseMethod, eventCreateMessage } from './EventMessageParser.mjs';

export class EventWebSocket {
  constructor(host) {
    this.host = host;
    this.onOpen = null;
    this.onReceive = null;
    this.onClose = null;
    this.onError = null;
  }

  _onOpen(parent) {
    if(parent.onOpen) {
      parent.onOpen();
    }
  }

  _onReceive(parent, message) {
    if(parent.onReceive) {
      console.log(new Uint8Array(message));
      parent.onReceive(eventParseMethod(new Uint8Array(message)));
    }
  }

  _setMethods_Node() {
    let parent = this;
    this.ws.on('open', () => this._onOpen(parent));
    this.ws.on('message', (msg) => this._onReceive(parent, msg));
    this.ws.on('error', (err) => this._onError(err));
  }

  _setMethods_Browser() {
    let parent = this;
    this.ws.onopen = () => this._onOpen(parent);
    this.ws.onmessage = (event) => this._onReceive(parent, event.data);
    this.ws.onerror = (err) => this._onError(err);
  }

  _setMethods() {
    if(!this._isOnBrowser()) {
      this._setMethods_Node();
      return ;
    }
    this._setMethods_Browser();
  }

  _onError(err) {
    if(this.onError) {
      this.onError(err)
    }
  }

  send(data) {
    const dt = eventCreateMessage(data);
    if(!dt) {
      return ;
    }
    this.ws.send(dt);
  }

  _isOnBrowser() {
    return typeof window !== "undefined";
  }

  async connect() {
    let WSImpl;
    if (this._isOnBrowser()) {
      WSImpl = WebSocket;
    } else {
      WSImpl = (await import('ws')).default;
    }
    try {
      this.ws = new WSImpl(this.host);
      this._setMethods();
    } catch (err) {
      console.log(err)
      return false
    }
    return true;
  }
}

export default EventWebSocket;