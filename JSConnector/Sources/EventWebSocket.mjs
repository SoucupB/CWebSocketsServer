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
      parent.onReceive(eventParseMethod(new Uint8Array(message)));
    }
  }

  _setMethods() {
    let parent = this;
    this.ws.on('open', () => this._onOpen(parent));
    this.ws.on('message', (msg) => this._onReceive(parent, msg));
    this.ws.on('error', (err) => this._onError(err));
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

  async connect() {
    let WSImpl;
    if (typeof window !== "undefined") {
      WSImpl = WebSocket;
    } else {
      WSImpl = (await import('ws')).default;
    }
    try {
      this.ws = new WSImpl(this.host);
      this._setMethods();
    } catch (err) {
      return false
    }
    return true;
  }
}

export default EventWebSocket;