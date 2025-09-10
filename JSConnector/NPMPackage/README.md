# EventWebSocket

A lightweight library for **network message parsing** over WebSocket connections.  
Designed to work in both **Node.js** and **browser environments**, it provides utilities to encode, decode, and send structured messages efficiently.

---

## Features

- Cross-platform: Node.js and browser support.
- Automatic message parsing and construction.
- Handles binary payloads with optional authentication codes.
- Easy-to-use WebSocket wrapper with events:
  - `onOpen`
  - `onReceive`
  - `onClose`
  - `onError`
- Minimal dependency (`ws` only for Node.js).

---

## Installation

```bash
npm install event-websocket
```

Code example
import EventWebSocket from 'event-websocket';

const ws = new EventWebSocket('ws://localhost:8080');

ws.onOpen = () => {
  console.log('Connected!');
};

ws.onReceive = (obj) => {
  console.log('Received:', obj);

  // obj.size -> number, the length of the message (Not neccesar since the output buffer is an array)
  // obj.code -> number, An abstract code used to describe what type of message it is.
  // obj.authCode -> Uint8Array | null, depending on the connection if it sends the 8 bytes code.
  // obj.payload -> Uint8Array The payload sent from the server.
};

ws.connect();

The C server that goes along with this package is implemented and documented here.
https://github.com/SoucupB/CWebSocketsServer/tree/main