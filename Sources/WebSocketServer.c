#include "WebSocketServer.h"
#include <string.h>

void wss_SetMethods(PWebSocketServer self);
void _wss_OnConnect(PConnection connection, void *buffer);

PWebSocketServer wss_Create(uint16_t port) {
  PWebSocketServer self = malloc(sizeof(WebSocketServer));
  memset(self, 0, sizeof(WebSocketServer));
  self->socketServer = sock_Create(port);
  self->pendingConnections = vct_Init(sizeof(Connection));
  wss_SetMethods(self);
  return self;
}

void wss_SetMethods(PWebSocketServer self) {
  PSocketMethod _onConnect = sock_Method_Create(
    _wss_OnConnect,
    self
  );
  self->methodsBundle._onConnect = _onConnect;
  self->socketServer->onConnectionAquire = _onConnect; 
}

void wss_Delete(PWebSocketServer self) {
  sock_Method_Delete(self->methodsBundle._onConnect);
  sock_Delete(self->socketServer);
  free(self);
}

static inline size_t wss_FindConnectionOnThePull(PWebSocketServer self, PConnection conn, uint8_t *found) {
  *found = 0;
  Connection *connections = self->pendingConnections->buffer;
  for(size_t i = 0, c = self->pendingConnections->size; i < c; i++) {
    if(conn->fd == connections[i].fd) {
      *found = 1;
      return i;
    }
  }
  return 0;
}

PHttpResponse wss_Response(PWebSocketServer self) {
  PHttpResponse response = http_Response_Create();
  return response;
}

uint8_t wss_ProcessConnectionRequest(PWebSocketServer self, PDataFragment dt) {
  PHttpRequest req = http_Request_Parse(dt->data, dt->size);
  if(!req) {
    return 0;
  }
  http_Request_Delete(req);
  return 1;
}

void _wss_OnReceive(PDataFragment dt, void *buffer) {
  PWebSocketServer self = buffer;
  uint8_t found;
  size_t connIndex = wss_FindConnectionOnThePull(self, &dt->conn, &found);
  if(!found) {
    void (*cMethod)(PDataFragment, void *) = self->onReceiveMessage->method;
    cMethod(dt, self->onReceiveMessage->mirrorBuffer);
    return ;
  }
  if(!wss_ProcessConnectionRequest(self, dt)) {
    sock_PushCloseConnections(self->socketServer, &dt->conn);
  }
  vct_RemoveElement(self->pendingConnections, connIndex);
}

void _wss_OnConnect(PConnection connection, void *buffer) {
  PWebSocketServer self = buffer;
  if(self->onConnect) {
    void (*cMethod)(PConnection, void *) = self->onConnect->method;
    cMethod(connection, self->onConnect->mirrorBuffer);
  }
  vct_Push(self->pendingConnections, connection);
}

void wss_SetOnConnect(PWebSocketServer self, PSocketMethod routine) {
  self->onConnect = routine;
}

void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS) {
  sock_OnFrame(self->socketServer, deltaMS);
}