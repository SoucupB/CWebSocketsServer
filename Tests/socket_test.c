#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include "SocketClient.h"
#include "SocketServer.h"

uint16_t port = 20000;

PSocketServer test_Util_PrepareServer(uint16_t port, void *method, void *buffer) {
  PSocketServer server = sock_Create(port);
  PSocketMethod onConnect = sock_Method_Create(
    method,
    buffer
  );
  server->onConnectionAquire = onConnect;
  return server;
}

void test_Util_Release(PSocketServer self) {
  if(self->onConnectionAquire) {
    sock_Method_Delete(self->onConnectionAquire);
  }
  if(self->onConnectionRelease) {
    sock_Method_Delete(self->onConnectionRelease);
  }
  if(self->onReceiveMessage) {
    sock_Method_Delete(self->onReceiveMessage);
  }
  sock_Delete(self);
}

PConnection test_Util_Connect(PSocketServer server) {
  PConnection conn = sock_Client_Connect(server->port, "127.0.0.1");
  sock_OnFrame(server, 32);
  return conn;
}

void methodToExecute(Connection conn, void *buffer) {
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

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_connect_to_server_with_single_client),
    cmocka_unit_test(test_connect_to_server_with_multiple_client),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}