import EventWebSocket from './build/EventWebSocket.js'

let a = new EventWebSocket('ws://localhost:8080');
a.onOpen = function () {
  let obj = {
    size: "This is a test message".length,
    code: 143,
    authCode: "02454352",
    payload: "This is a test message"
  };

  a.send(obj)
}
a.onReceive = function(msg) {
  console.log(msg)
}
a.connect();