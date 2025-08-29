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

static void test_connect_to_wss_server(void **state) {
  PWebSocketServer socketServer = newServer();
  wss_Delete(socketServer);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_connect_to_wss_server),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}