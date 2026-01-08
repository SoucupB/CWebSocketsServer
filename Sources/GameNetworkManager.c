#include "GameNetworkManager.h"
#include "JsonParser.h"
#include "JWT.h"
#include <string.h>
#include <assert.h>
#include "HttpParser.h"

void man_SetupMethods(PManager self);
static inline void man_RemoveConnection(const PManager self, const Connection conn);
static inline void man_RunOnLogin(const PManager self, const PUser user);
static inline void man_PushClosingConnection(const PManager self, Connection conn);

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
  man_PushClosingConnection(gameConnTimeout->man, gameConnTimeout->conn);
  man_RemoveConnection(gameConnTimeout->man, gameConnTimeout->conn);
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

static inline void man_RemoveConnection(const PManager self, const Connection conn) {
  Array pendingConns = self->pendingConnections;
  Connection *conns = pendingConns->buffer;
  for(size_t i = 0, c = pendingConns->size; i < c; i++) {
    if(conn.fd == conns[i].fd) {
      arr_RemoveElement(pendingConns, i);
      return ;
    }
  }
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

static inline void man_SendAckMessage(const PManager self, const PDataFragment dt) {
  JsonElement response = json_Map_Create();
  json_Map_String_String_Add(response, "response", "ok");
  man_Response_SendMessage(self, &dt->conn, response);
}

static inline PUser man_ProcessPendingMessage(const PManager self, const PDataFragment dt) {
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
  PUser activatedUser = usrs_Activate(self->userData, userID, &dt->conn);
  man_RemoveConnection(self, dt->conn);
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

static inline PUser man_ProcessPendingConnection(const PManager self, const PDataFragment dt) {
  uint8_t found;
  size_t plyIndex = man_GetConn(self, dt, &found);
  if(!found) {
    return man_ProcessPendingMessage(self, dt);
  }
  PUser currentUser = usrs_ByIndex(self->userData, plyIndex);
  if(!currentUser->active) {
    return NULL;
  }
  man_SendAckMessage(self, dt);
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
  const PUser currentUser = man_ProcessPendingConnection(self, dt);
  if(!currentUser) {
    sock_PushCloseConnections(self->server->socketServer, &dt->conn);
    return ;
  }
  man_RunOnReceiveCommand(self, dt, currentUser);
}

void _man_OnReceive(PDataFragment dt, void *mirror) {
  man_OnReceive(mirror, dt);
}

void _man_OnConnect(PConnection conn, void *mirror) {
  man_OnConnect(mirror, conn);
}

void _man_OnRelease(Connection conn, void *mirror) {
  PManager self = mirror;
  PUser currentUser = usrs_ByConnection(self->userData, &conn);
  usr_Deactivate(currentUser);
  man_RemoveConnection(self, conn);
  man_RunOnRelease(self, currentUser);
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
  crm_Free(self);
}

void man_OnFrame(PManager self, uint64_t deltaMS) {
  wss_OnFrame(self->server, deltaMS);
  tf_OnFrame(self->timeServer, deltaMS);
}