#include "WebSocketServer.h"
#include "HttpParser.h"
#include "TimeFragment.h"
#include <string.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include "WebSocketsTranslator.h"
#include "SocketServer.h"
#include "Array.h"
#include "NetworkBuffer.h"


typedef struct PingConnData_t {
  Connection conn;
  uint64_t payload;
  int64_t remainingTime;
} PingConnData;

typedef struct ConnectionProtocol_t {
  Connection conn;
  PNetworkBuffer buff;
} ConnectionProtocol;

void wss_SetMethods(PWebSocketServer self);
void _wss_OnConnect(Connection connection, void *buffer);
void _wss_OnReceive(PDataFragment dt, void *buffer);
void _wss_OnRelease(Connection conn, void *buffer);
static inline void wss_RunCloseConnRoutine(PWebSocketServer self, Connection conn);
static inline uint8_t wss_RemovePingRequest(PWebSocketServer self, PDataFragment dt);
static inline uint8_t wss_IsPingRequestIssued(PWebSocketServer self, PDataFragment dt);
static inline size_t wss_FindConnectionOnThePull(PWebSocketServer self, PConnection conn, uint8_t *found);
static inline void wss_FreeConn(const ConnectionProtocol conn);
static inline void wss_RemoveConnBuffer(const Array arr, const size_t index);
static inline ConnectionProtocol *wss_FindConn(const PWebSocketServer self, const PDataFragment dt);

static inline uint64_t _wss_Rand() {
  uint64_t response;
  char *buffer = (char *)&response;
  for(size_t i = 0; i < sizeof(uint64_t); i++) {
    buffer[i] = (rand() & 255);
  }
  return response;
}

PWebSocketServer wss_Create(uint16_t port) {
  PWebSocketServer self = crm_Alloc(sizeof(WebSocketServer));
  memset(self, 0, sizeof(WebSocketServer));
  self->socketServer = sock_Create(port);
  self->pendingConnections = arr_Init(sizeof(ConnectionProtocol));
  self->pendingPingRequests = arr_Init(sizeof(PingConnData));
  self->activeConnections = arr_Init(sizeof(ConnectionProtocol));
  self->maxBSize = 1024 * 1024;
  self->maxBSizeForHttpReq = 1024 * 4;
  wss_SetMethods(self);
  return self;
}

void _wss_LoopPingPong(void *buffer) {
  PWebSocketServer self = buffer;
  Connection *conns = self->socketServer->connections->buffer;
  for(size_t i = 0, c = self->socketServer->connections->size; i < c; i++) {
    uint8_t found;
    (void)!wss_FindConnectionOnThePull(self, &conns[i], &found);
    if(found) {
      continue;
    }
    PingConnData pingDt = (PingConnData) {
      .conn = conns[i],
      .remainingTime = self->timeServer->timeout / 2,
      .payload = _wss_Rand()
    };
    arr_Push(self->pendingPingRequests, &pingDt);
    char *pingRequest = wbs_ToWebSocket((WebSocketObject) {
      .buffer = (char *)&((PingConnData *)arr_Last(self->pendingPingRequests))->payload,
      .sz = sizeof(uint64_t),
      .opcode = OPCODE_PING
    });
    DataFragment fragment = {
      .conn = conns[i],
      .data = pingRequest,
      .size = wbs_FullMessageSize(pingRequest),
      .persistent = 1
    };
    sock_Write_Push(self->socketServer, &fragment);
    crm_Free(pingRequest);
  }
}

void wss_SetMethod(PWebSocketServer self) {
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)_wss_LoopPingPong,
    .buffer = self
  };
  tf_ExecuteLoop(self->timeServer->server, timeFragment, self->timeServer->timeout);
}

void wss_EnablePingPongTimeout(PWebSocketServer self, uint64_t timeout) {
  if(!self->timeServer) {
    self->timeServer = crm_Alloc(sizeof(Timers));
    self->timeServer->server = tf_Create();
  }
  self->timeServer->timeout = timeout;
  wss_SetMethod(self);
}

void wss_SetMethods(PWebSocketServer self) {
  PSocketMethod _onConnect = sock_Method_Create(
    _wss_OnConnect,
    self
  );
  self->methodsBundle._onConnect = _onConnect;
  self->socketServer->onConnectionAquire = _onConnect;
  PSocketMethod _onReceive = sock_Method_Create(
    _wss_OnReceive,
    self
  );
  self->methodsBundle._onReceive = _onReceive;
  self->socketServer->onReceiveMessage = _onReceive;
  PSocketMethod _onRelease = sock_Method_Create(
    _wss_OnRelease,
    self
  );
  self->methodsBundle._onRelease = _onRelease;
  self->socketServer->onConnectionRelease = _onRelease;
}

static inline void wss_Tf_Delete(PWebSocketServer self) {
  if(!self->timeServer) {
    return ;
  }
  tf_Delete(self->timeServer->server);
  crm_Free(self->timeServer);
}

static inline void wss_CloseConnections(PWebSocketServer self, Connection conn) {
  wss_RunCloseConnRoutine(self, conn);
  sock_PushCloseConnections(self->socketServer, &conn);
}

void wss_ProcessTimeoutPingRequests(PWebSocketServer self, uint64_t deltaMS) {
  PingConnData *pings = self->pendingPingRequests->buffer;
  Array indexesToRemove = arr_Init(sizeof(size_t));
  for(size_t i = 0, c = self->pendingPingRequests->size; i < c; i++) {
    pings[i].remainingTime -= (int64_t)deltaMS;
    if(pings[i].remainingTime <= 0) {
      arr_Push(indexesToRemove, &i);
      wss_CloseConnections(self, pings[i].conn);
    }
  }
  Array cpyVector = arr_RemoveElements(self->pendingPingRequests, indexesToRemove);
  arr_Delete(self->pendingPingRequests);
  self->pendingPingRequests = cpyVector;
  arr_Delete(indexesToRemove);
}

static inline void wss_ReleaseActiveConnections(const PWebSocketServer self) {
  ConnectionProtocol *conns = self->activeConnections->buffer;
  for(size_t i = 0, c = self->activeConnections->size; i < c; i++) {
    tpd_Delete(conns[i].buff);
  }
  arr_Delete(self->activeConnections);
}

static inline void wss_FreeConn(const ConnectionProtocol conn) {
  if(conn.buff) {
    tpd_Delete(conn.buff);
  }
}

void wss_FreeConnectionPayload(const Array arr) {
  const ConnectionProtocol *cp = arr->buffer;
  for(size_t i = 0, c = arr->size; i < c; i++) {
    wss_FreeConn(cp[i]);
  }
  arr_Delete(arr);
}

void wss_Delete(PWebSocketServer self) {
  sock_Method_Delete(self->methodsBundle._onReceive);
  sock_Method_Delete(self->methodsBundle._onConnect);
  sock_Method_Delete(self->methodsBundle._onRelease);
  wss_Tf_Delete(self);
  wss_FreeConnectionPayload(self->pendingConnections);
  arr_Delete(self->pendingPingRequests);
  wss_ReleaseActiveConnections(self);
  sock_Delete(self->socketServer);
  crm_Free(self);
}

static inline size_t wss_FindConnectionOnThePull(PWebSocketServer self, PConnection conn, uint8_t *found) {
  *found = 0;
  ConnectionProtocol *connections = self->pendingConnections->buffer;
  for(size_t i = 0, c = self->pendingConnections->size; i < c; i++) {
    if(conn->fd == connections[i].conn.fd) {
      *found = 1;
      return i;
    }
  }
  return 0;
}

char *webSocketKey(PHttpString sec_websocket_key) {
  static const char *GUID = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
  if (!sec_websocket_key->buffer) return NULL;
  size_t key_len = sec_websocket_key->sz;
  size_t guid_len = strlen(GUID);
  size_t cat_len  = key_len + guid_len;
  char *cat = (char *)crm_Alloc(cat_len + 1);
  if (!cat) return NULL;
  memcpy(cat, sec_websocket_key->buffer, key_len);
  memcpy(cat + key_len, GUID, guid_len);
  cat[cat_len] = '\0';
  unsigned char sha1_digest[SHA_DIGEST_LENGTH];
  SHA1((const unsigned char *)cat, cat_len, sha1_digest);
  crm_Free(cat);
  int b64_len = 4 * ((SHA_DIGEST_LENGTH + 2) / 3);
  char *accept = (char *)crm_Alloc(b64_len + 1);
  if (!accept) return NULL;
  EVP_EncodeBlock((unsigned char *)accept, sha1_digest, SHA_DIGEST_LENGTH);
  accept[b64_len] = '\0';
  return accept;
}

PHttpResponse wss_Response(PWebSocketServer self, PHttpRequest req) {
  PHttpResponse response = http_Response_Empty();
  response->response = 101;
  http_Response_Set(response, "Upgrade", sizeof("Upgrade") - 1, "websocket", sizeof("websocket") - 1);
  http_Response_Set(response, "Connection", sizeof("Connection") - 1, "Upgrade", sizeof("Upgrade") - 1);
  HttpString key = http_Request_GetValue(req, "Sec-WebSocket-Key");
  if(!key.buffer) {
    http_Response_Delete(response);
    return NULL;
  }
  char *newKey = webSocketKey(&key);
  http_Response_Set(response, "Sec-WebSocket-Accept", sizeof("Sec-WebSocket-Accept") - 1, newKey, strlen(newKey));
  crm_Free(newKey);
  return response;
}

void wss_SendMessage(PWebSocketServer self, PDataFragment dt) {
  WebSocketObject objs = {
    .buffer = dt->data,
    .sz = dt->size,
    .opcode = OPCODE_BINARY
  };
  char *response = wbs_ToWebSocket(objs);
  DataFragment fragment = {
    .conn = dt->conn,
    .data = response,
    .size = wbs_FullMessageSize(response),
    .persistent = 1
  };
  sock_Write_Push(self->socketServer, &fragment);
  crm_Free(response);
}

static inline ConnectionProtocol *wss_FindConn(const PWebSocketServer self, const PDataFragment dt) {
  ConnectionProtocol *protocol = self->pendingConnections->buffer;
  for(size_t i = 0, c = self->pendingConnections->size; i < c; i++) {
    if(protocol[i].conn.fd == dt->conn.fd) {
      return &protocol[i];
    }
  }
  return NULL;
}

PHttpRequest wss_ProcessHttpRequest(const PWebSocketServer self, const PDataFragment dt, uint8_t *incomplete) {
  *incomplete = 0;
  ConnectionProtocol *proto = wss_FindConn(self, dt);
  if(!proto) {
    return NULL;
  }
  if(!tpd_Push(proto->buff, dt->data, dt->size)) {
    return NULL;
  }
  PHttpRequest req = http_Request_NB_Get(proto->buff);
  if(!req) {
    *incomplete = 1;
    return NULL;
  }
  return req;
}

uint8_t wss_ProcessConnectionRequest(PWebSocketServer self, PDataFragment dt, uint8_t *incomplete) {
  PHttpRequest req = wss_ProcessHttpRequest(self, dt, incomplete);
  if(!req) {
    return 0;
  }
  PHttpResponse response = wss_Response(self, req);
  http_Request_Delete(req);
  if(!response) {
    return 0;
  }
  HttpString responseChar = http_Response_ToString(response);
  DataFragment frag = {
    .conn = dt->conn,
    .data = responseChar.buffer,
    .persistent = 1,
    .size = responseChar.sz
  };
  sock_Write_Push(self->socketServer, &frag);
  http_Response_Delete(response);
  crm_Free(responseChar.buffer);
  return 1;
}

PNetworkBuffer wss_FindPayloadChecker(const PWebSocketServer self, const PDataFragment dt) {
  ConnectionProtocol *conns = self->activeConnections->buffer;
  for(size_t i = 0, c = self->activeConnections->size; i < c; i++) {
    if(dt->conn.fd == conns[i].conn.fd) {
      return conns[i].buff;
    }
  }
  return NULL;
}

PNetworkBuffer wss_NetworkBuffer(const PWebSocketServer self, const PDataFragment dt) {
  PNetworkBuffer buff = wss_FindPayloadChecker(self, dt);
  if(!buff) {
    return NULL;
  }
  if(!tpd_Push(buff, dt->data, dt->size)) {
    return NULL;
  }
  return buff;
}

Array wss_GetObject(const PWebSocketServer self, const PDataFragment dt) {
  PNetworkBuffer protoBuff = wss_NetworkBuffer(self, dt);
  if(!protoBuff) {
    return NULL;
  }
  return wbs_Public_ParseData(protoBuff);
}

static inline void wss_CleanMessages(const Array arr) {
  wbs_Public_FreeParseData(arr);
}

int8_t wss_ReceiveMessages(PWebSocketServer self, PDataFragment dt, PSocketMethod routine) {
  Array messages = wss_GetObject(self, dt);
  if(!messages) {
    return 0;
  }
  WebSocketObject *objects = messages->buffer;
  DataFragment responseDt = {
    .conn = dt->conn,
    .data = NULL,
    .persistent = 0,
    .size = 0
  };
  uint8_t validConnection = !wss_IsPingRequestIssued(self, &responseDt);
  for(size_t i = 0, c = messages->size; i < c; i++) {
    responseDt.data = objects[i].buffer;
    responseDt.size = objects[i].sz;
    if(objects[i].opcode == OPCODE_CONNECTION_CLOSE) {
      wss_CloseConnections(self, responseDt.conn);
      continue;
    }
    if(!validConnection && objects[i].opcode == OPCODE_PONG && wss_RemovePingRequest(self, &responseDt)) {
      validConnection = 1;
      continue;
    }
    if(!routine || (objects[i].opcode != OPCODE_BINARY && objects[i].opcode != OPCODE_TEXT_FRAME)) {
      continue;
    }
    void (*cMethod)(PDataFragment, void *) = routine->method;
    cMethod(&responseDt, routine->mirrorBuffer);
  }
  wss_CleanMessages(messages);
  return validConnection;
}

static inline void wss_ProcessReleaseMethod(PWebSocketServer self, PDataFragment dt, PSocketMethod routine) {
  if(self->onRelease) {
    void (*cMethod)(Connection, void *) = self->onRelease->method;
    cMethod(dt->conn, self->onRelease->mirrorBuffer);
  }
}

static inline uint8_t wss_IsPingRequestIssued(PWebSocketServer self, PDataFragment dt) {
  PingConnData *pingBuffer = self->pendingPingRequests->buffer;
  for(size_t i = 0, c = self->pendingPingRequests->size; i < c; i++) {
    if(pingBuffer[i].conn.fd == dt->conn.fd) {
      return 1;
    }
  }
  return 0;
}

static inline uint8_t wss_RemovePingRequest(PWebSocketServer self, PDataFragment dt) {
  PingConnData *pingBuffer = self->pendingPingRequests->buffer;
  for(size_t i = 0, c = self->pendingPingRequests->size; i < c; i++) {
    if(dt->size == sizeof(uint64_t) && pingBuffer[i].payload == *(uint64_t *)dt->data) {
      arr_RemoveElement(self->pendingPingRequests, i);
      return 1;
    }
  }
  return 0;
}

static inline void wss_ProcessWsRequests(PWebSocketServer self, PDataFragment dt, PSocketMethod routine) {
  if(!wss_ReceiveMessages(self, dt, routine)) {
    wss_ProcessReleaseMethod(self, dt, routine);
    sock_PushCloseConnections(self->socketServer, &dt->conn);
  }
}

void wss_SetMaxBSizeSocket(PWebSocketServer self, size_t bytesSize) {
  self->maxBSize = bytesSize;
}

static inline void wss_AddConnection(const PWebSocketServer self, const Connection conn) {
  ConnectionProtocol conns = {
    .conn = conn,
    .buff = tpd_Create(self->maxBSize)
  };
  arr_Push(self->activeConnections, &conns);
}

void _wss_OnReceive(PDataFragment dt, void *buffer) {
  PWebSocketServer self = buffer;
  uint8_t found;
  size_t connIndex = wss_FindConnectionOnThePull(self, &dt->conn, &found);
  if(!found) {
    wss_ProcessWsRequests(self, dt, self->onReceiveMessage);
    return ;
  }
  uint8_t incomplete;
  uint8_t request = wss_ProcessConnectionRequest(self, dt, &incomplete);
  if(incomplete) {
    return ;
  }
  wss_RemoveConnBuffer(self->pendingConnections, connIndex);
  if(!request) {
    sock_PushCloseConnections(self->socketServer, &dt->conn);
    return ;
  }
  if(self->onConnect) {
    void (*cMethod)(PConnection, void *) = self->onConnect->method;
    cMethod(&dt->conn, self->onConnect->mirrorBuffer);
  }
  wss_AddConnection(self, dt->conn);
}

size_t wss_ConnectionsCount(PWebSocketServer self) {
  return sock_ConnectionCount(self->socketServer);
}

void _wss_OnConnect(Connection connection, void *buffer) {
  PWebSocketServer self = buffer;
  ConnectionProtocol conn = {
    .conn = connection,
    .buff = tpd_Create(self->maxBSizeForHttpReq)
  };
  arr_Push(self->pendingConnections, &conn);
}

static inline void wss_RunCloseConnRoutine(PWebSocketServer self, Connection conn) {
  if(self->onRelease) {
    void (*cMethod)(Connection, void *) = self->onRelease->method;
    cMethod(conn, self->onRelease->mirrorBuffer);
  }
}

static inline void wss_RemoveConnBuffer(const Array arr, const size_t index) {
  wss_FreeConn(((ConnectionProtocol *)arr->buffer)[index]);
  arr_RemoveElement(arr, index);
}

void _wss_OnRelease(Connection conn, void *buffer) {
  PWebSocketServer self = buffer;
  uint8_t found;
  size_t connIndex = wss_FindConnectionOnThePull(self, &conn, &found);
  if(found) {
    wss_RemoveConnBuffer(self->pendingConnections, connIndex);
    return ;
  }
  wss_RunCloseConnRoutine(self, conn);
}

static inline void wss_Tf_OnFrame(PWebSocketServer self, uint64_t deltaMS) {
  if(self->timeServer) {
    tf_OnFrame(self->timeServer->server, deltaMS);
  }
}

void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS) {
  wss_Tf_OnFrame(self, deltaMS);
  wss_ProcessTimeoutPingRequests(self, deltaMS);
  sock_OnFrame(self->socketServer, deltaMS);
}