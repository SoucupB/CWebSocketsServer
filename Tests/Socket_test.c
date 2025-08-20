#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include "SocketClient.h"
#include "SocketServer.h"
#include <string.h>
#include <stdio.h>
#include "Socket_Helper_test.h"

uint16_t port = 20000;

void methodToExecute(Connection conn, void *buffer) {
  if(!buffer) {
    return ;
  }
  uint32_t *number = buffer;
  (*number)++;
}

static void test_connect_to_server_with_single_client(void **state) {
  const uint16_t currentPort = port--;
  uint32_t calleCount = 0;
  PSocketServer server = test_Util_PrepareServer(currentPort, methodToExecute, &calleCount);
  PConnection connection = test_Util_Connect(server);
  assert_true(calleCount == 1);
  test_Util_Release(server);
  sock_Client_Free(connection);
}

static void test_connect_to_server_with_multiple_client(void **state) {
  const uint16_t currentPort = port--;
  uint32_t calleCount = 0;
  PSocketServer server = test_Util_PrepareServer(currentPort, methodToExecute, &calleCount);
  PConnection connections[16];
  for(size_t i = 0; i < 10; i++) {
    connections[i] = test_Util_Connect(server);
  }
  assert_true(calleCount == 10);
  test_Util_Release(server);
  for(size_t i = 0; i < 10; i++) {
    sock_Client_Free(connections[i]);
  }
}

static void test_connect_to_server_with_maximum_connections_count(void **state) {
  const uint16_t currentPort = port--;
  uint32_t calleCount = 0;
  PSocketServer server = test_Util_PrepareServer(currentPort, methodToExecute, &calleCount);
  sock_SetMaxConnections(server, 5);
  PConnection connections[16];
  for(size_t i = 0; i < 10; i++) {
    connections[i] = test_Util_Connect(server);
  }
  assert_true(calleCount == 5);
  test_Util_Release(server);
  for(size_t i = 0; i < 10; i++) {
    sock_Client_Free(connections[i]);
  }
}

static void test_connect_to_server_sending_one_message(void **state) {
  void onReceiveMessage(DataFragment *dt, void *buffer) {
    uint32_t *bff = buffer;
    (*bff)++;
  }
  const uint16_t currentPort = port--;
  uint32_t messageCount = 0;
  PSocketMethod onReceiveMessageMethod = sock_Method_Create(
    onReceiveMessage,
    &messageCount
  );
  PSocketServer server = test_Util_PrepareServer(currentPort, methodToExecute, NULL);
  server->onReceiveMessage = onReceiveMessageMethod;
  PConnection connection = test_Util_Connect(server);
  test_Util_SendMessage(server, connection, "some message", sizeof("some message") - 1);
  assert_true(messageCount == 1);
  test_Util_Release(server);
  sock_Client_Free(connection);
}

static void test_connect_to_server_sending_multiple_messages(void **state) {
  void onReceiveMessage(DataFragment *dt, void *buffer) {
    uint32_t *bff = buffer;
    (*bff)++;
  }
  const uint16_t currentPort = port--;
  uint32_t messageCount = 0;
  PSocketMethod onReceiveMessageMethod = sock_Method_Create(
    onReceiveMessage,
    &messageCount
  );
  PSocketServer server = test_Util_PrepareServer(currentPort, methodToExecute, NULL);
  server->onReceiveMessage = onReceiveMessageMethod;
  PConnection connection = test_Util_Connect(server);
  for(uint32_t i = 0; i < 100; i++) {
    test_Util_SendMessage(server, connection, "some message", sizeof("some message") - 1);
  }
  assert_true(messageCount == 100);
  test_Util_Release(server);
  sock_Client_Free(connection);
}

static void test_connect_to_server_message_correctness(void **state) {
  void onReceiveMessage(DataFragment *dt, void *buffer) {
    assert_true(dt->size == sizeof("some message") - 1);
    assert_true(memcmp(dt->data, "some message", dt->size) == 0);
  }
  const uint16_t currentPort = port--;
  PSocketMethod onReceiveMessageMethod = sock_Method_Create(
    onReceiveMessage,
    NULL
  );
  PSocketServer server = test_Util_PrepareServer(currentPort, methodToExecute, NULL);
  server->onReceiveMessage = onReceiveMessageMethod;
  PConnection connection = test_Util_Connect(server);
  test_Util_SendMessage(server, connection, "some message", sizeof("some message") - 1);
  test_Util_Release(server);
  sock_Client_Free(connection);
}

static void test_connect_to_server_on_close_connection(void **state) {
  void onCloseMessage(DataFragment *dt, void *buffer) {
    uint32_t *onClose = buffer;
    (*onClose)++;
  }
  const uint16_t currentPort = port--;
  uint32_t onReleaseCounter = 0;
  PSocketMethod onCloseMessageMethod = sock_Method_Create(
    onCloseMessage,
    &onReleaseCounter
  );
  PSocketServer server = test_Util_PrepareServer(currentPort, methodToExecute, NULL);
  server->onConnectionRelease = onCloseMessageMethod;
  PConnection connection = test_Util_Connect(server);
  sock_Client_Free(connection);
  test_Util_WriteTo(server, /*index=*/0, "test", sizeof("test") - 1, /*times=*/10);
  assert_true(sock_ConnectionCount(server) == 0);
  test_Util_Release(server);
  assert_true(onReleaseCounter == 1);
}

static void test_connect_to_server_on_write_back(void **state) {
  void onReceiveMessage(DataFragment *dt, void *buffer) {
    PSocketServer server = buffer;
    DataFragment responseDT = test_Util_GetDT(&dt->conn, "echo back", sizeof("echo back") - 1);
    sock_Write_Push(server, &responseDT);
  }
  const uint16_t currentPort = port--;
  PSocketServer server = test_Util_PrepareServer(currentPort, methodToExecute, NULL);
  PSocketMethod onReceiveMessageMethod = sock_Method_Create(
    onReceiveMessage,
    server
  );
  server->onReceiveMessage = onReceiveMessageMethod;
  PConnection connection = test_Util_Connect(server);
  test_Util_SendMessage(server, connection, "some message", sizeof("some message") - 1);
  test_Util_Expect(connection, "echo back", sizeof("echo back") - 1);
  test_Util_Release(server);
  sock_Client_Free(connection);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_connect_to_server_with_single_client),
    cmocka_unit_test(test_connect_to_server_with_multiple_client),
    cmocka_unit_test(test_connect_to_server_with_maximum_connections_count),
    cmocka_unit_test(test_connect_to_server_sending_one_message),
    cmocka_unit_test(test_connect_to_server_sending_multiple_messages),
    cmocka_unit_test(test_connect_to_server_message_correctness),
    cmocka_unit_test(test_connect_to_server_on_close_connection),
    cmocka_unit_test(test_connect_to_server_on_write_back),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}