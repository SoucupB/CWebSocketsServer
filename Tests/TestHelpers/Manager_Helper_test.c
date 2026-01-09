#include "Manager_Helper_test.h"
#include "SocketServer.h"
#include "Structs.h"
#include "WebSocketServer_Helper_Test.h"
#include "JWT.h"
#include <string.h>
#include "Json_Helper_test.h"
#include "String.h"
#include <unistd.h>
#include "HttpParser.h"

typedef struct TempBuffStr_t {
  PManager manager;
  PSocketMethod parent;
  void *mirror;
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
  int32_t maxCount = 3500;
  while(1) {
    if(currentCallsCount != tempBuff->callCount) {
      return ;
    }
    if(!(maxCount--)) {
      return ;
    }
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
    .mirror = NULL,
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

HttpString man_Helper_CreateJWT(char *secret, JsonElement payload) {
  return jwt_Encode(payload, (HttpString) {
    .buffer = secret,
    .sz = strlen(secret)
  }, 1000000000);
}

PHttpRequest man_Helper_Http_Admin_CreateRequest(uint64_t userID, char *secret) {
  JsonElement jsn = json_Map_Create();
  json_Map_String_Integer_Add(jsn, "user_id", userID);
  json_Map_String_Boolean_Add(jsn, "admin", 1);
  HttpString jwt = man_Helper_CreateJWT(secret, jsn);
  PHttpRequest req = http_Request_Basic();
  const size_t buffSize = jwt.sz + 64;
  char *codeResp = crm_Alloc(buffSize);
  memset(codeResp, 0, buffSize);
  snprintf(codeResp, buffSize, "Bearer %.*s", (int32_t)jwt.sz, jwt.buffer);
  http_Request_AddHeader(req, "Authorization", codeResp);
  crm_Free(jwt.buffer);
  crm_Free(codeResp);
  json_DeleteElement(jsn);
  return req;
}

uint8_t onRegister(void *mirror, uint64_t userID) {
  PTempBuffStr tmp = mirror;
  tmp->callCount++;
  if(!tmp->parent) {
    return 1;
  }
  uint8_t (*method)(void *, uint64_t) = tmp->parent->method;
  return method(mirror, userID);
}

static void _man_Helper_SendMessage(PConnection conn, PHttpRequest req) {
  HttpString strReq = http_Request_ToString(req);
  DataFragment dt = {
    .conn = *conn,
    .data = strReq.buffer,
    .persistent = 1,
    .size = strReq.sz
  };
  sock_Client_SendMessage(&dt);
  crm_Free(strReq.buffer);
}

static PHttpResponse _man_Helper_RetrieveMessage(PConnection conn) {
  // sock_Client_Receive();
  HttpString respString = sock_Client_ReceiveWithErrors(conn);
  while(!respString.buffer) {
    respString = sock_Client_ReceiveWithErrors(conn);
  }
  PHttpResponse response = http_Response_Parse(respString);
  crm_Free(respString.buffer);
  return response;
}

PHttpResponse man_Helper_RegisterPlayer(PManager self, uint64_t userID, char *secret) {
  TempBuffStr tmp = {
    .manager = self,
    .parent = self->onUserRegister,
    .mirror = NULL,
    .callCount = 0
  };
  PHttpRequest req = man_Helper_Http_Admin_CreateRequest(userID, secret);
  PSocketMethod lastSocketMethod = self->onUserRegister;
  PSocketMethod onRegisterMethod = sock_Method_Create(
    (void *)onRegister,
    &tmp
  );
  self->onUserRegister = onRegisterMethod;
  int32_t totalTicks = 5000;
  PConnection conn = sock_Client_Connect(self->httpServer->server->port, "127.0.0.1");
  _man_Helper_SendMessage(conn, req);
  while(totalTicks--) {
    if(tmp.callCount) {
      break;
    }
    man_OnFrame(self, 1);
    usleep(1000);
  }
  PHttpResponse resp = _man_Helper_RetrieveMessage(conn);
  sock_Method_Delete(onRegisterMethod);
  self->onUserRegister = lastSocketMethod;
  sock_Client_Free(conn);
  http_Request_Delete(req);
  return resp;
}