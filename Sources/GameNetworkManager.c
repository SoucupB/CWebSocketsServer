#include "GameNetworkManager.h"
#include "JsonParser.h"
#include "JWT.h"
#include <string.h>
#include <assert.h>
#include "HttpParser.h"
#include "String.h"

void man_SetupMethods(PManager self);
uint8_t man_RemoveConnection(const PManager self, const Connection conn);
static inline void man_RunOnLogin(const PManager self, const PUser user);
static inline void man_PushClosingConnection(const PManager self, Connection conn);

typedef enum ResponseTypes_t {
  SUCCESS,
  FAILED_AUTH,
  BAD_REQUEST
} ResponseTypes;

typedef struct GameConnTimeout_t {
  PManager man;
  Connection conn;
} GameConnTimeout;

typedef GameConnTimeout *PGameConnTimeout;

PManager man_Create(uint16_t port) {
  PManager self = crm_Alloc(sizeof(Manager));
  memset(self, 0, sizeof(Manager));
  self->server = wss_Create(port);
  self->pendingConnections = arr_Init(sizeof(Connection));
  self->timeoutConnectionCheckers = arr_Init(sizeof(PGameConnTimeout));
  self->timeServer = tf_Create();
  self->userData = usrs_Create();
  man_SetupMethods(self);
  return self;
}

static inline size_t man_GetConn(const PManager self, const PDataFragment dt, uint8_t *found) {
  return usrs_ConnID(self->userData, &dt->conn, found);
}

void man_DeleteTimeoutConn(const PGameConnTimeout gameConnTimeout) {
  const PManager self = gameConnTimeout->man;
  PGameConnTimeout *buffer = self->timeoutConnectionCheckers->buffer;
  for(size_t i = 0, c = self->timeoutConnectionCheckers->size; i < c; i++) {
    if(buffer[i] == gameConnTimeout) {
      crm_Free(buffer[i]);
      arr_RemoveElement(self->timeoutConnectionCheckers, i);
      return ;
    }
  }
}

static inline HttpString man_HTTP_GetAuthCode(const HttpString auth) {
  const size_t total = auth.sz;
  size_t index = 0;
  while(index < total && auth.buffer[index] != ' ') {
    index++;
  }
  index++;
  if(index >= total) {
    return (HttpString) {
      .buffer = NULL,
      .sz = 0
    };
  }
  return (HttpString) {
    .buffer = auth.buffer + index,
    .sz = total - index
  };
}

static inline uint8_t man_HTTP_OnUserRegister(const PManager self, const uint64_t userID) {
  if(!self->onUserRegister) {
    return 1;
  }
  uint8_t (*method)(void *, uint64_t) = self->onUserRegister->method;
  return method(self->onUserRegister->mirrorBuffer, userID);
}

static inline uint8_t man_HTTP_IsValidUser(const PManager self, const PJWT jwt, uint64_t *userID) {
  JsonElement userIDValue = json_Map_Get(jwt->payload, (HttpString) {
    .buffer = "user_id",
    .sz = sizeof("user_id") - 1
  });
  if(userIDValue.type != JSON_INTEGER) {
    return 0;
  }
  JsonElement isAdmin = json_Map_Get(jwt->payload, (HttpString) {
    .buffer = "admin",
    .sz = sizeof("admin") - 1
  });
  if(isAdmin.type != JSON_BOOLEAN || !isAdmin.value) {
    return 0;
  }
  *userID = json_Integer_Get(userIDValue);
  return 1;
}

static inline ResponseTypes man_HTTP_AddUser(const PManager self, const PHttpRequest req) {
  if(!self->hmacKey.buffer) {
    return FAILED_AUTH;
  }
  HttpString auth = http_Request_GetValue(req, "Authorization");
  if(!auth.buffer) {
    return FAILED_AUTH;
  }
  HttpString authAddress = man_HTTP_GetAuthCode(auth);
  PJWT currentJwt = jwt_Parse(authAddress, self->hmacKey);
  if(!currentJwt) {
    return FAILED_AUTH;
  }
  uint64_t userID;
  uint8_t jwtApproved = man_HTTP_IsValidUser(self, currentJwt, &userID);
  jwt_Delete(currentJwt);
  if(!jwtApproved) {
    return FAILED_AUTH;
  }
  if(man_User_Get(self, userID)) { // Needs testing
    return BAD_REQUEST;
  }
  if(!man_HTTP_OnUserRegister(self, userID) || !man_User_Register(self, userID)) {
    return BAD_REQUEST;
  }
  return SUCCESS;
}

PHttpResponse _man_HTTP_AddUser(PHttpRequest req, void *mirror) {
  PManager self = mirror;
  switch (man_HTTP_AddUser(self, req))
  {
    case BAD_REQUEST:
      return http_Response_Basic(400);
      break;

    case FAILED_AUTH:
      return http_Response_Basic(401);
      break;
    
    default:
      break;
  }
  return http_Response_Basic(200);
}

static inline void man_InitHTTPMethods(const PManager self) {
  PHttpServer server = self->httpServer;
  PSocketMethod method = sock_Method_Create(
    (void *)_man_HTTP_AddUser,
    self
  );
  server->onReceive = method;
}

void man_InitHTTPServer(PManager self, uint16_t port) {
  assert(port != self->server->socketServer->port);
  self->httpServer = httpS_Create(port);
  man_InitHTTPMethods(self);
}

static inline void man_RunOnLogin(const PManager self, const PUser user) {
  if(!self->onLogin || !user) {
    return ;
  }
  void (*method)(PUser, void *) = self->onLogin->method;
  method(user, self->onLogin->mirrorBuffer);
}

static inline void man_DeleteRemainingConns(const PManager self) {
  PGameConnTimeout *buffer = self->timeoutConnectionCheckers->buffer;
  for(size_t i = 0, c = self->timeoutConnectionCheckers->size; i < c; i++) {
    crm_Free(buffer[i]);
  }
  arr_Delete(self->timeoutConnectionCheckers);
}

static inline void man_PushClosingConnection(const PManager self, Connection conn) {
  sock_PushCloseConnections(self->server->socketServer, &conn);
}

void _man_ExecuteAfterMS(void *buffer) {
  PGameConnTimeout gameConnTimeout = buffer;
  if(man_RemoveConnection(gameConnTimeout->man, gameConnTimeout->conn)) {
    man_PushClosingConnection(gameConnTimeout->man, gameConnTimeout->conn);
  }
  man_DeleteTimeoutConn(gameConnTimeout);
}

void man_SetSecret(PManager self, HttpString hmacKey) {
  self->hmacKey.buffer = crm_Alloc(hmacKey.sz);
  self->hmacKey.sz = hmacKey.sz;
  memcpy(self->hmacKey.buffer, hmacKey.buffer, hmacKey.sz);
}

void man_PushConnTimeout(const PManager self, const PConnection conn, uint64_t afterMS) {
  PGameConnTimeout gameConnTimeout = crm_Alloc(sizeof(GameConnTimeout));
  gameConnTimeout->conn = *conn;
  gameConnTimeout->man = self;
  TimeMethod tm = {
    .buffer = gameConnTimeout,
    .method = _man_ExecuteAfterMS
  };
  arr_Push(self->timeoutConnectionCheckers, &gameConnTimeout);
  tf_ExecuteAfter(self->timeServer, tm, afterMS);
}

void man_OnConnect(PManager self, PConnection conn) {
  arr_Push(self->pendingConnections, conn);
  man_PushConnTimeout(self, conn, 2500);
}

static inline uint8_t man_ProcessJWT(const PManager self, const HttpString jwt, uint64_t *userID) {
  if(!self->hmacKey.buffer || !self->hmacKey.sz) {
    return 0;
  }
  PJWT jwtToken = jwt_Parse(jwt, self->hmacKey);
  if(!jwtToken) {
    return 0;
  }
  JsonElement userIDString = json_Map_Get(jwtToken->payload, (HttpString) {
    .buffer = "user_id",
    .sz = sizeof("user_id") - 1
  });
  if(userIDString.type != JSON_INTEGER) {
    return 0;
  }
  *userID = json_Integer_Get(userIDString);
  jwt_Delete(jwtToken);
  return 1;
}

uint8_t man_RemoveConnection(const PManager self, const Connection conn) {
  Array pendingConns = self->pendingConnections;
  Connection *conns = pendingConns->buffer;
  for(size_t i = 0, c = pendingConns->size; i < c; i++) {
    if(conn.fd == conns[i].fd) {
      arr_RemoveElement(pendingConns, i);
      return 1;
    }
  }
  return 0;
}

void man_SendMessage(const PManager self, const PDataFragment dt) {
  wss_SendMessage(self->server, dt);
}

void man_Response_SendMessage(const PManager self, PConnection conn, JsonElement element) {
  if(element.type != JSON_JSON) {
    return ;
  }
  HttpString message = json_Element_ToString(element);
  DataFragment frag = {
    .conn = *conn,
    .data = message.buffer,
    .persistent = 1,
    .size = message.sz
  };
  man_SendMessage(self, &frag);
  crm_Free(message.buffer);
}

void man_SendResponseMessage(const PManager self, const PDataFragment dt, int64_t code) {
  JsonElement response = json_Map_Create();
  json_Map_String_Integer_Add(response, "status", code);
  man_Response_SendMessage(self, &dt->conn, response);
  json_DeleteElement(response);
}

void man_PushClosingConn(PManager self, Connection conn) {
  if(sock_IsInvalid(conn)) {
    return ;
  }
  sock_PushCloseConnections(self->server->socketServer, &conn);
}

static inline void man_DeactivatePreviousConnection(const PManager self, const uint64_t userID) {
  PUser currentUser = man_User_Get(self, userID);
  if(currentUser && currentUser->active) {
    man_PushClosingConn(self, currentUser->conn);
  }
}

static inline PUser man_ProcessPendingMessage_t(const PManager self, const PDataFragment dt) {
  char *endBuffer;
  JsonElement currentElement = json_Parse((HttpString) {
    .buffer = dt->data,
    .sz = dt->size
  }, &endBuffer);
  if(currentElement.type != JSON_JSON || endBuffer != dt->data + dt->size) {
    json_DeleteElement(currentElement);
    return NULL;
  }
  JsonElement jwtToken = json_Map_Get(currentElement, (HttpString) {
    .buffer = "token",
    .sz = sizeof("token") - 1
  });
  if(jwtToken.type != JSON_STRING) {
    json_DeleteElement(currentElement);
    return NULL;
  }
  uint64_t userID;
  if(!man_ProcessJWT(self, *(HttpString *)jwtToken.value, &userID)) {
    json_DeleteElement(currentElement);
    return NULL;
  }
  json_DeleteElement(currentElement);
  man_DeactivatePreviousConnection(self, userID); // needs tests
  PUser activatedUser = usrs_Activate(self->userData, userID, dt->conn);
  (void)!man_RemoveConnection(self, dt->conn);
  man_RunOnLogin(self, activatedUser);
  return activatedUser;
}

static inline uint8_t man_IsUserActive(const PManager self, const size_t plyIndex) {
  PUser user = usrs_Get(self->userData, plyIndex);
  assert(user != NULL);
  return user->active;
}

PUser man_User_Get(PManager self, uint64_t ID) {
  return usrs_Get(self->userData, ID);
}

static inline PUser man_ProcessPendingMessage(const PManager self, const PDataFragment dt) {
  PUser currentUser = man_ProcessPendingMessage_t(self, dt);
  if(!currentUser) {
    man_SendResponseMessage(self, dt, 401);
  } else {
    man_SendResponseMessage(self, dt, 200);
  }
  return currentUser;
}

static inline PUser man_ProcessPendingConnection(const PManager self, const PDataFragment dt, uint8_t *pendingConn) {
  *pendingConn = 1;
  uint8_t found;
  size_t plyIndex = man_GetConn(self, dt, &found);
  if(!found) {
    return man_ProcessPendingMessage(self, dt);
  }
  PUser currentUser = usrs_ByIndex(self->userData, plyIndex);
  if(!currentUser->active) {
    return NULL;
  }
  *pendingConn = 0;
  return currentUser;
}

static inline void man_RunOnReceiveCommand(const PManager self, const PDataFragment dt, const PUser user) {
  if(!self->onReceive) {
    return ;
  }
  void (*method)(PDataFragment, PUser, void *) = self->onReceive->method;
  method(dt, user, self->onReceive->mirrorBuffer);
}

static inline void man_RunOnRelease(const PManager self, const PUser user) {
  if(!self->onDisconnect) {
    return ;
  }
  void (*method)(PUser, void *) = self->onDisconnect->method;
  method(user, self->onDisconnect->mirrorBuffer);
}

static inline void man_OnReceive(const PManager self, const PDataFragment dt) {
  uint8_t pendingConn;
  const PUser currentUser = man_ProcessPendingConnection(self, dt, &pendingConn);
  if(!currentUser) {
    sock_PushCloseConnections(self->server->socketServer, &dt->conn);
    return ;
  }
  if(!pendingConn) {
    man_RunOnReceiveCommand(self, dt, currentUser);
  }
}

void _man_OnReceive(PDataFragment dt, void *mirror) {
  man_OnReceive(mirror, dt);
}

void _man_OnConnect(PConnection conn, void *mirror) {
  man_OnConnect(mirror, conn);
}

uint8_t man_User_Register(PManager self, uint64_t userID) {
  return usrs_AddUser(self->userData, userID);
}

void _man_OnRelease(Connection conn, void *mirror) {
  PManager self = mirror;
  PUser currentUser = usrs_ByConnection(self->userData, &conn);
  (void)!man_RemoveConnection(self, conn);
  if(!currentUser) {
    return ;
  }
  usr_Deactivate(currentUser);
  man_RunOnRelease(self, currentUser);
}

void man_ActivatePingPongRequests(PManager self, uint64_t timeout) {
  wss_EnablePingPongTimeout(self->server, timeout);
}

Array man_Users(PManager self) {
  return self->userData->users;
}

void man_SetupMethods(PManager self) {
  PSocketMethod onConnectMethod = sock_Method_Create(
    _man_OnConnect,
    self
  );
  self->server->onConnect = onConnectMethod;
  PSocketMethod onReceiveMethod = sock_Method_Create(
    _man_OnReceive,
    self
  );
  self->server->onReceiveMessage = onReceiveMethod;
  PSocketMethod onRelease = sock_Method_Create(
    _man_OnRelease,
    self
  );
  self->server->onRelease = onRelease;
}

static inline void man_HTTPS_Delete(const PHttpServer self) {
  if(!self) {
    return ;
  }
  sock_Method_Delete(self->onReceive);
  httpS_Delete(self);
}

void man_Delete(PManager self) {
  sock_Method_Delete(self->server->onReceiveMessage);
  sock_Method_Delete(self->server->onRelease);
  sock_Method_Delete(self->server->onConnect);
  wss_Delete(self->server);
  arr_Delete(self->pendingConnections);
  man_DeleteRemainingConns(self);
  tf_Delete(self->timeServer);
  usrs_Delete(self->userData);
  if(self->hmacKey.buffer) {
    crm_Free(self->hmacKey.buffer);
  }
  man_HTTPS_Delete(self->httpServer);
  crm_Free(self);
}

static inline void man_HTTPS_OnFrame(const PManager self, const uint64_t deltaMS) {
  if(!self->httpServer) {
    return ;
  }
  httpS_OnFrame(self->httpServer, deltaMS);
}

void man_OnFrame(PManager self, uint64_t deltaMS) {
  wss_OnFrame(self->server, deltaMS);
  tf_OnFrame(self->timeServer, deltaMS);
  man_HTTPS_OnFrame(self, deltaMS);
}