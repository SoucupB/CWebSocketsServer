import WebSocket from 'ws';
import { eventParseMethod, eventCreateMessage } from './EventMessageParser.mjs';

export default class EventWebSocket {
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
      parent.onReceive(new Uint8Array(message));
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
    this.ws.send(data);
  }

  connect() {
    try {
      this.ws = new WebSocket(this.host);
      this._setMethods();
    } catch (err) {
      return false
    }
    return true;
  }
}