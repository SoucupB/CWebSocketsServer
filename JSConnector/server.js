import EventWebSocket from './Sources/EventWebSocket.mjs'

let a = new EventWebSocket('ws://localhost:8080');
a.onOpen = function () {
  console.log("Connected!");
  a.send("PULLLAAAA")
}
a.onReceive = function(msg) {
  console.log(msg)
}
a.connect();