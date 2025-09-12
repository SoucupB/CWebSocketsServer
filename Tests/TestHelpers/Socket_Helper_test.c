#include "Socket_Helper_test.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>

PConnection sock_FindConnectionByIndex(PSocketServer self, size_t index);

PSocketServer test_Util_PrepareServer(uint16_t port, void *method, void *buffer) {
  PSocketServer server = sock_Create(port);
  PSocketMethod onConnect = sock_Method_Create(
    method,
    buffer
  );
  server->onConnectionAquire = onConnect;
  return server;
}

DataFragment test_Util_GetDT(PConnection conn, char *msg, size_t sz) {
  DataFragment dt = {
    .conn = *conn,
    .data = msg,
    .persistent = 1,
    .size = sz,
  };
  return dt;
}

void test_Util_WriteTo(PSocketServer server, size_t index, char *msg, size_t sz, uint32_t times) {
  for(size_t i = 0; i < times; i++) {
    PConnection conn = sock_FindConnectionByIndex(server, index);
    if(!conn) {
      break;
    }
    DataFragment dt = {
      .conn = *conn,
      .data = msg,
      .persistent = 1,
      .size = sz,
    };
    sock_Write_Push(server, &dt);
    sock_OnFrame(server, 32);
  }
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


void test_Util_Expect(PConnection conn, char *buffer, size_t sz) {
  DataFragment dt = sock_Client_Receive(conn);
  assert_true(sz == dt.size);
  assert_true(memcmp(dt.data, buffer, sz) == 0);
  free(dt.data);
}

PConnection test_Util_Connect(PSocketServer server) {
  PConnection conn = sock_Client_Connect(server->port, "127.0.0.1");
  sock_OnFrame(server, 32);
  return conn;
}

void test_Util_BufferMessage(PSocketServer server, PConnection conn, char *msg, size_t sz) {
  DataFragment dt = (DataFragment) {
    .conn = *conn,
    .data = msg,
    .persistent = 0,
    .size = sz
  };
  sock_Client_SendMessage(&dt);
}

void test_Util_SendMessage(PSocketServer server, PConnection conn, char *msg, size_t sz) {
  test_Util_BufferMessage(server, conn, msg, sz);
  for(size_t i = 0; i < 10; i++) {
    sock_OnFrame(server, 32);
  }
}