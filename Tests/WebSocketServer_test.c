#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include "SocketClient.h"
#include "SocketServer.h"
#include "WebSocketServer.h"
#include <string.h>
#include <stdio.h>
#include "Socket_Helper_test.h"

uint16_t port = 20000;

PWebSocketServer newServer() {
  return wss_Create(port--);
}

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

static void test_connect_to_wss_server(void **state) {
  PWebSocketServer wssServer = newServer();
  PConnection connection = test_Util_ExchangeConnection(wssServer);
  wss_Delete(wssServer);
  sock_Client_Free(connection);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_connect_to_wss_server),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}