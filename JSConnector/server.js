import EventWebSocket from './build/bundle.node.min.js'

let a = new EventWebSocket('ws://localhost:8080');
a.onOpen = function () {
  let obj = {
    size: "Ana are 2 mere si 2 pere!".length,
    code: 143,
    authCode: "02454352",
    payload: "Ana are 2 mere si 2 pere!"
  };

  a.send(obj)
}
a.onReceive = function(msg) {
  console.log(msg)
}
a.connect();