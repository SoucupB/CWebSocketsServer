#include "EventServer.h"
#include <string.h>
#define MAX_BYTES_SWITCH_STACK (1<<12)

static inline void evs_ProcessClosingConn(PEventServer self, PConnection conn) {
  if(self->onClose) {
    void (*method)(PConnection, void *) = self->onClose->method;
    method(conn, self->onClose->mirrorBuffer);
  }
}

static inline void evs_PushEventBuffer(PEventServer self, PEventBuffer bff, PConnection conn) {
  DataFragment nextFrag = {
    .conn = *conn,
    .data = bff->buffer,
    .size = bff->size
  };
  wss_SendMessage(self->wsServer, &nextFrag);
}

void evs_PushMessage(PEventServer self, PResponseObject msg) {
  uint32_t msgSize = evm_Out_Public_TotalSize(&msg->metaData);
  if(msgSize < MAX_BYTES_SWITCH_STACK) {
    char buffer[MAX_BYTES_SWITCH_STACK];
    EventBuffer response = evm_Reuse_Transform(&msg->metaData, buffer);
    evs_PushEventBuffer(self, &response, msg->conn);
    return ;
  }
  char *buffer = malloc(msgSize);
  EventBuffer response = evm_Reuse_Transform(&msg->metaData, buffer);
  evs_PushEventBuffer(self, &response, msg->conn);
  free(buffer);
}

void _evs_OnClose(Connection conn, void *buffer) {
  evs_ProcessClosingConn(buffer, &conn);
}

void _evs_OnReceive(PDataFragment frag, void *buffer) {
  PEventServer self = buffer;
  uint8_t valid;
  EventMessage currentMessage = evm_Parse((EventBuffer) {
    .buffer = frag->data,
    .size = frag->size
  }, &valid);
  if(!valid) {
    evs_ProcessClosingConn(self, &frag->conn);
    sock_PushCloseConnections(self->wsServer->socketServer, &frag->conn);
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
  PSocketMethod _onClose = sock_Method_Create(
    _evs_OnClose,
    self
  );
  self->wsServer->onRelease = _onClose;
}

PEventServer evs_Create(uint16_t port) {
  PEventServer self = malloc(sizeof(EventServer));
  memset(self, 0, sizeof(EventServer));
  self->wsServer = wss_Create(port);
  evs_RegisterMethods(self);
  return self;
}

void evs_FreeMethods(PEventServer self) {
  sock_Method_Delete(self->wsServer->onReceiveMessage);
  sock_Method_Delete(self->wsServer->onRelease);
}

void evs_OnFrame(PEventServer self, uint64_t deltaMS) {
  wss_OnFrame(self->wsServer, deltaMS);
}

void evs_Delete(PEventServer self) {
  evs_FreeMethods(self);
  wss_Delete(self->wsServer);
  free(self);
}