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
  PConnection connection = test_Util_ExchangeConnection(wssServer);
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
  PConnection connection = test_Util_ExchangeConnection(wssServer);
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
    connections[i] = test_Util_ExchangeConnection(wssServer);
  }
  assert_true(onConnectCount == 10);
  test_Wss_Util_Delete(wssServer);
  for(size_t i = 0; i < 10; i++) {
    sock_Client_Free(connections[i]);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_connect_to_wss_server),
    cmocka_unit_test(test_connect_on_connect_callback),
    cmocka_unit_test(test_connect_on_connect_multiple_connections),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}