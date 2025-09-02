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
#include "WebSocketServer_Helper_Test.h"

uint16_t port = 20000;

PWebSocketServer newServer() {
  return wss_Create(port--);
}

static void test_connect_to_wss_server(void **state) {
  PWebSocketServer wssServer = newServer();
  PConnection connection = test_Wss_Util_ExchangeConnection(wssServer);
  wss_Delete(wssServer);
  sock_Client_Free(connection);
}

static void test_connect_on_connect_callback(void **state) {
  uint32_t onConnectCount = 0;
  void onConnect(Connection conn, void *buffer) {
    if(!buffer) {
      return ;
    }
    uint32_t *number = buffer;
    (*number)++;
  }
  PWebSocketServer wssServer = newServer();
  PSocketMethod onConnectMethod = sock_Method_Create(
    onConnect,
    &onConnectCount
  );
  wssServer->onConnect = onConnectMethod;
  PConnection connection = test_Wss_Util_ExchangeConnection(wssServer);
  assert_true(onConnectCount == 1);
  test_Wss_Util_Delete(wssServer);
  sock_Client_Free(connection);
}

static void test_connect_on_connect_multiple_connections(void **state) {
  uint32_t onConnectCount = 0;
  void onConnect(Connection conn, void *buffer) {
    if(!buffer) {
      return ;
    }
    uint32_t *number = buffer;
    (*number)++;
  }
  PWebSocketServer wssServer = newServer();
  PSocketMethod onConnectMethod = sock_Method_Create(
    onConnect,
    &onConnectCount
  );
  wssServer->onConnect = onConnectMethod;
  PConnection connections[10];
  for(size_t i = 0; i < 10; i++) {
    connections[i] = test_Wss_Util_ExchangeConnection(wssServer);
  }
  assert_true(onConnectCount == 10);
  test_Wss_Util_Delete(wssServer);
  for(size_t i = 0; i < 10; i++) {
    sock_Client_Free(connections[i]);
  }
}

static void test_connect_on_connect_faulty_http_handshake_missing_key(void **state) {
  uint32_t onConnectCount = 0;
  void onConnect(Connection conn, void *buffer) {
    if(!buffer) {
      return ;
    }
    uint32_t *number = buffer;
    (*number)++;
  }
  char *handshakeMessage = "\
GET /chat HTTP/1.1\r\n\
Host: example.com:80\r\n\
Upgrade: websocket\r\n\
Connection: Upgrade\r\n\
Sec-WebSocket-Version: 13\r\n\
\r\n";
  PWebSocketServer wssServer = newServer();
  PSocketMethod onConnectMethod = sock_Method_Create(
    onConnect,
    &onConnectCount
  );
  wssServer->onConnect = onConnectMethod;
  PConnection connection = test_Wss_Util_Connect(wssServer, handshakeMessage);
  assert_true(onConnectCount == 0);
  test_Wss_Util_Delete(wssServer);
  sock_Client_Free(connection);
}

static void test_connect_on_connect_faulty_http_handshake_malformed_request(void **state) {
  uint32_t onConnectCount = 0;
  void onConnect(Connection conn, void *buffer) {
    if(!buffer) {
      return ;
    }
    uint32_t *number = buffer;
    (*number)++;
  }
  char *handshakeMessage = "\
GET /chat HTTP/1.1\r\n\
Host: example.com:80\r\n\
Upgrade: websocket\n\
Connection: Upgrade\r\n\
Sec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\n\
Sec-WebSocket-Version: 13\r\n\
\r\n";
  PWebSocketServer wssServer = newServer();
  PSocketMethod onConnectMethod = sock_Method_Create(
    onConnect,
    &onConnectCount
  );
  wssServer->onConnect = onConnectMethod;
  PConnection connection = test_Wss_Util_Connect(wssServer, handshakeMessage);
  assert_true(onConnectCount == 0);
  test_Wss_Util_Delete(wssServer);
  sock_Client_Free(connection);
}

static void test_connect_on_send_messages(void **state) {
  void onReceiveMessages(PDataFragment dt, void *buffer) {
    assert_true(dt->size == sizeof("some_test_message") - 1);
    assert_memory_equal(dt->data, "some_test_message", dt->size);
  }
  PWebSocketServer wssServer = newServer();
  PSocketMethod onReceiveMethod = sock_Method_Create(
    onReceiveMessages,
    NULL
  );
  wssServer->onReceiveMessage = onReceiveMethod;
  PConnection connection = test_Wss_Util_ExchangeConnection(wssServer);
  test_Wss_SendMessage(wssServer, connection, "some_test_message", sizeof("some_test_message") - 1);
  test_Wss_Util_Delete(wssServer);
  sock_Client_Free(connection);
}

static void test_connect_and_send_back_messages(void **state) {
  void onReceiveMessages(PDataFragment dt, void *buffer) {
    PWebSocketServer self = buffer;
    DataFragment fragment = {
      .conn = dt->conn,
      .data = "dadadada",
      .size = sizeof("dadadada") - 1
    };
    wss_SendMessage(self, &fragment);
  }
  PWebSocketServer wssServer = newServer();
  PSocketMethod onReceiveMethod = sock_Method_Create(
    onReceiveMessages,
    wssServer
  );
  wssServer->onReceiveMessage = onReceiveMethod;
  PConnection connection = test_Wss_Util_ExchangeConnection(wssServer);
  test_Wss_SendMessage(wssServer, connection, "sender", sizeof("sender") - 1);
  test_Wss_RepeatFramesDiff(wssServer, 32, 10);
  test_Wss_Expect(connection, "dadadada", sizeof("dadadada") - 1);
  test_Wss_Util_Delete(wssServer);
  sock_Client_Free(connection);
}

static void test_connect_and_send_back_multiple_messages(void **state) {
  uint32_t receivedCount = 0;
  void onReceiveMessages(PDataFragment dt, void *buffer) {
    uint32_t *msg = buffer;
    (*msg)++;
  }
  uint8_t checkerMethod(void *buffer) {
    uint32_t *msg = buffer;
    return *msg == 5;
  }
  PWebSocketServer wssServer = newServer();
  PSocketMethod onReceiveMethod = sock_Method_Create(
    onReceiveMessages,
    &receivedCount
  );
  wssServer->onReceiveMessage = onReceiveMethod;
  PConnection connection = test_Wss_Util_ExchangeConnection(wssServer);
  for(size_t i = 0; i < 5; i++) {
    test_Wss_SendMessage(wssServer, connection, "sender", sizeof("sender") - 1);
  }
  test_Wss_WaitAndRunUntil(wssServer, 5000, checkerMethod, &receivedCount);
  assert_true(receivedCount == 5);
  sock_Client_Free(connection);
  test_Wss_Util_Delete(wssServer);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_connect_to_wss_server),
    cmocka_unit_test(test_connect_on_connect_callback),
    cmocka_unit_test(test_connect_on_connect_multiple_connections),
    cmocka_unit_test(test_connect_on_connect_faulty_http_handshake_missing_key),
    cmocka_unit_test(test_connect_on_connect_faulty_http_handshake_malformed_request),
    cmocka_unit_test(test_connect_on_send_messages),
    cmocka_unit_test(test_connect_and_send_back_messages),
    cmocka_unit_test(test_connect_and_send_back_multiple_messages),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}