#include "Manager_Helper_test.h"
#include "SocketServer.h"
#include "WebSocketServer_Helper_Test.h"
#include "JWT.h"
#include <string.h>

PConnection man_Helper_Login(PManager self, uint16_t port, JsonElement payload, char *secret) {
  PWebSocketServer server = self->server;
  PConnection conn = test_Wss_Util_ExchangeConnection(server);
  HttpString jwt = jwt_Encode(payload, (HttpString) {
    .buffer = secret,
    .sz = strlen(secret)
  }, 1000000000);
  char cBuff[jwt.sz + 1];
  cBuff[jwt.sz] = 0;
  memcpy(cBuff, jwt.buffer, jwt.sz);
  JsonElement str = json_String_Create(cBuff);

  JsonElement loginMap = json_Map_Create();
  json_Map_Add(loginMap, "token", str);
  HttpString finalLogin = json_Element_ToString(loginMap);
  test_Wss_SendMessage(server, conn, finalLogin.buffer, finalLogin.sz);
  crm_Free(jwt.buffer);
  crm_Free(finalLogin.buffer);
  json_DeleteElement(loginMap);
  return conn;
}

void man_Helper_AddUser(PManager self, uint64_t userID) {
  PUser usr = crm_Alloc(sizeof(User));
  usr->active = 0;
  usr->conn = NULL;
  usr->ID = userID;
  arr_Push(self->userData->users, &usr);
}