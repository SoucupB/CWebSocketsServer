#include "Manager_Helper_test.h"
#include "SocketServer.h"
#include "WebSocketServer_Helper_Test.h"
#include "JWT.h"
#include <string.h>
#include "Json_Helper_test.h"
#include "String.h"
#include <unistd.h>

typedef struct TempBuffStr_t {
  PManager manager;
  PSocketMethod parent;
  int32_t callCount;
} TempBuffStr;

typedef TempBuffStr *PTempBuffStr;

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

void loginMethod(PUser user, void *mirror) {
  PTempBuffStr temp = mirror;
  temp->callCount++;
  if(!temp->parent) {
    return ;
  }
  void (*method)(PUser, void *) = temp->parent->method;
  method(user, temp->parent->mirrorBuffer);
}

void man_Helper_AddUser(PManager self, uint64_t userID) {
  PUser usr = crm_Alloc(sizeof(User));
  usr->active = 0;
  usr->conn = NULL;
  usr->ID = userID;
  arr_Push(self->userData->users, &usr);
}

HttpString man_Helper_Token(HttpString token) {
  JsonElement str = json_String_CreateFromHttpString(token);
  JsonElement loginMap = json_Map_Create();
  json_Map_Add(loginMap, "token", str);
  HttpString finalLogin = json_Element_ToString(loginMap);
  json_DeleteElement(loginMap);
  return finalLogin;
}

HttpString man_Helper_GetStringToken(PManager self, JsonElement loginPayload, char *secret) {
  HttpString jwt = jwt_Encode(loginPayload, (HttpString) {
    .buffer = secret,
    .sz = strlen(secret)
  }, 1000000000);
  HttpString loginRequest = man_Helper_Token(jwt);
  crm_Free(jwt.buffer);
  return loginRequest;
}

void man_Helper_ProcessMessage(PManager self, PConnection conn, PTempBuffStr tempBuff, HttpString loginMessage) {
  int32_t currentCallsCount = tempBuff->callCount;
  test_Wss_SendMessage(self->server, conn, loginMessage.buffer, loginMessage.sz);
  while(currentCallsCount == tempBuff->callCount) {
    man_OnFrame(self, 1);
    usleep(1000);
  }
}

PConnection man_Helper_LoginHigherLevel(PManager self, uint64_t userID, char *secret) {
  char *template = "\
{\
    \"user_id\": %ld\
}\
";
  char responseCode[64] = {0};
  snprintf(responseCode, sizeof(responseCode), template, userID);

  JsonElement payload = test_Helper_Json_Parse(responseCode);
  PSocketMethod oldLoginMethod = self->onLogin;
  TempBuffStr tempBuffer = {
    .manager = self,
    .parent = oldLoginMethod,
    .callCount = 0
  };
  PSocketMethod newLoginMethod = sock_Method_Create(
    (void *)loginMethod,
    &tempBuffer
  );
  self->onLogin = newLoginMethod;
  PConnection conn = test_Wss_Util_ExchangeConnection(self->server);
  if(!conn) {
    self->onLogin = oldLoginMethod;
    sock_Method_Delete(newLoginMethod);
    return NULL;
  }
  HttpString loginString = man_Helper_GetStringToken(self, payload, secret);
  man_Helper_ProcessMessage(self, conn, &tempBuffer, loginString);

  json_DeleteElement(payload);
  sock_Method_Delete(newLoginMethod);
  crm_Free(loginString.buffer);
  self->onLogin = oldLoginMethod;
  return conn;
}