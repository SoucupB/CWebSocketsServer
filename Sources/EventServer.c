#include "EventServer.h"
#include <string.h>

static inline void evs_ProcessClosingConn(PEventServer self, PDataFragment frag) {
  if(self->onClose) {
    void (*method)(PConnection, void *) = self->onClose->method;
    method(&frag->conn, self->onClose->mirrorBuffer);
  }
  sock_PushCloseConnections(self->wsServer->socketServer, &frag->conn);
}

void _evs_OnReceive(PDataFragment frag, void *buffer) {
  PEventServer self = buffer;
  uint8_t valid;
  EventMessage currentMessage = evm_Parse((EventBuffer) {
    .buffer = frag->data,
    .size = frag->size
  }, &valid);
  if(!valid) {
    evs_ProcessClosingConn(self, frag);
    return ;
  }
  if(self->onReceive) {
    void (*method)(PResponseObject, void *) = self->onReceive->method;
    ResponseObject rsp = (ResponseObject) {
      .conn = &frag->conn,
      .metaData = currentMessage
    };
    method(&rsp, self->onReceive->mirrorBuffer);
  }
}

static inline void evs_RegisterMethods(PEventServer self) {
  PSocketMethod _onReceive = sock_Method_Create(
    _evs_OnReceive,
    self
  );
  self->wsServer->onReceiveMessage = _onReceive;
}

PEventServer evs_Create(uint16_t port) {
  PEventServer self = malloc(sizeof(EventServer));
  memset(self, 0, sizeof(EventServer));
  self->wsServer = wss_Create(port);
  evs_RegisterMethods(self);
  return self;
}

void evs_Delete(PEventServer self) {
  wss_Delete(self->wsServer);
  free(self);
}