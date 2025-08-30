#include "WebSocketServer_Helper_Test.h"
#include "Socket_Helper_test.h"

PConnection test_Util_ExchangeConnection(PWebSocketServer wssServer) {
  PConnection connection = test_Util_Connect(wssServer->socketServer);
  char *handshakeMessage = "\
GET /chat HTTP/1.1\r\n\
Host: example.com:80\r\n\
Upgrade: websocket\r\n\
Connection: Upgrade\r\n\
Sec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\n\
Sec-WebSocket-Version: 13\r\n\
\r\n";
  test_Util_SendMessage(wssServer->socketServer, connection, handshakeMessage, strlen(handshakeMessage));
char *handshakeAccepted = "\
HTTP/1.1 101\r\n\
Connection: Upgrade\r\n\
Content-Length: 0\r\n\
Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=\r\n\
Upgrade: websocket\r\n\
\r\n";
  test_Util_Expect(connection, handshakeAccepted, strlen(handshakeAccepted));
  return connection;
}

void test_Wss_Util_Delete(PWebSocketServer self) {
  if(self->onConnect) {
    sock_Method_Delete(self->onConnect);
  }
  if(self->onReceiveMessage) {
    sock_Method_Delete(self->onReceiveMessage);
  }
  if(self->onRelease) {
    sock_Method_Delete(self->onRelease);
  }
  wss_Delete(self);
}