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
#include "EventServer.h"
#include "Socket_Helper_test.h"
#include "WebSocketServer_Helper_Test.h"
#include "EventServer_Helper_test.h"

uint16_t port = 20000;

PEventServer newServer() {
  return evs_Create(port--);
}

static void test_connect_to_evs_server(void **state) {
  PEventServer evServer = newServer();
  assert_non_null(evServer);
  test_Util_Evs_Delete(evServer);
}

static void test_send_message(void **state) {
  uint32_t onReceiveCount = 0;
  void onReceive(PResponseObject msg, void *buffer) {
    if(!buffer) {
      return ;
    }
    uint32_t *number = buffer;
    (*number)++;
  }
  PSocketMethod onReceiveMessage = sock_Method_Create(
    onReceive,
    &onReceiveCount
  );
  PEventServer evServer = newServer();
  evServer->onReceive = onReceiveMessage;
  PConnection connection = test_Wss_Util_ExchangeConnection(evServer->wsServer);
  assert_non_null(evServer);
  test_Util_Evs_SendClearMessage(evServer, connection, "some_message", sizeof("some_message") - 1, 0);
  assert_true(onReceiveCount == 1);
  test_Util_Evs_Delete(evServer);
  sock_Client_Free(connection);
}

static void test_send_message_correctness(void **state) {
  uint32_t onReceiveCount = 0;
  void onReceive(PResponseObject msg, void *buffer) {
    if(!buffer) {
      return ;
    }
    uint32_t *number = buffer;
    (*number)++;
    assert_true(msg->metaData.headerCode == 33221);
    assert_true(msg->metaData.isAuthed == 0);
    assert_true(msg->metaData.str.size == sizeof("some_message") - 1);
    assert_memory_equal(msg->metaData.str.buffer, "some_message", msg->metaData.str.size);
  }
  PSocketMethod onReceiveMessage = sock_Method_Create(
    onReceive,
    &onReceiveCount
  );
  PEventServer evServer = newServer();
  evServer->onReceive = onReceiveMessage;
  PConnection connection = test_Wss_Util_ExchangeConnection(evServer->wsServer);
  assert_non_null(evServer);
  test_Util_Evs_SendClearMessage(evServer, connection, "some_message", sizeof("some_message") - 1, 33221);
  assert_true(onReceiveCount == 1);
  test_Util_Evs_Delete(evServer);
  sock_Client_Free(connection);
}

static void test_on_malformed_message(void **state) {
  uint32_t onReceiveCount = 0;
  uint32_t onCloseCount = 0;
  void onReceive(PResponseObject msg, void *buffer) {
    if(!buffer) {
      return ;
    }
    uint32_t *number = buffer;
    (*number)++;
  }
  void onRemove(PConnection conn, void *buffer) {
    if(!buffer) {
      return ;
    }
    uint32_t *number = buffer;
    (*number)++;
  }
  PSocketMethod onReceiveMessage = sock_Method_Create(
    onReceive,
    &onReceiveCount
  );
  PSocketMethod onCloseMessage = sock_Method_Create(
    onRemove,
    &onCloseCount
  );
  PEventServer evServer = newServer();
  evServer->onReceive = onReceiveMessage;
  evServer->onClose = onCloseMessage;
  PConnection connection = test_Wss_Util_ExchangeConnection(evServer->wsServer);
  assert_non_null(evServer);
  test_Wss_SendMessage(evServer->wsServer, connection, "some_message", sizeof("some_message"));
  assert_true(onReceiveCount == 0);
  assert_true(onCloseCount == 1);
  test_Util_Evs_Delete(evServer);
  sock_Client_Free(connection);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_connect_to_evs_server),
    cmocka_unit_test(test_send_message),
    cmocka_unit_test(test_send_message_correctness),
    cmocka_unit_test(test_on_malformed_message),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}