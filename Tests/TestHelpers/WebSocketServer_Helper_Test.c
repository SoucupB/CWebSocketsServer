#include "WebSocketServer_Helper_Test.h"
#include "Socket_Helper_test.h"
#include "WebSocketsTranslator.h"

PConnection test_Wss_Util_Connect(PWebSocketServer wssServer, char *input) {
  PConnection connection = test_Util_Connect(wssServer->socketServer);
  test_Util_SendMessage(wssServer->socketServer, connection, input, strlen(input));
  return connection;
}

PConnection test_Wss_Util_ExchangeConnection(PWebSocketServer wssServer) {
  char *handshakeMessage = "\
GET /chat HTTP/1.1\r\n\
Host: example.com:80\r\n\
Upgrade: websocket\r\n\
Connection: Upgrade\r\n\
Sec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\n\
Sec-WebSocket-Version: 13\r\n\
\r\n";
char *handshakeAccepted = "\
HTTP/1.1 101\r\n\
Connection: Upgrade\r\n\
Content-Length: 0\r\n\
Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=\r\n\
Upgrade: websocket\r\n\
\r\n";
  PConnection connection = test_Wss_Util_Connect(wssServer, handshakeMessage);
  test_Util_Expect(connection, handshakeAccepted, strlen(handshakeAccepted));
  return connection;
}

void test_Wss_RepeatFramesDiff(PWebSocketServer self, uint64_t deltaMS, uint32_t repeats) {
  while(repeats--) {
    wss_OnFrame(self, deltaMS);
  }
}

void test_Wss_SendMessage(PWebSocketServer wssServer, PConnection conn, char *buffer, size_t sz) {
  WebSocketObject wssObj = (WebSocketObject) {
    .buffer = buffer,
    .sz = sz
  };
  char *message = wbs_Masked_ToWebSocket(wssObj);
  test_Util_SendMessage(wssServer->socketServer, conn, message, wbs_FullMessageSize(message));
  free(message);
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