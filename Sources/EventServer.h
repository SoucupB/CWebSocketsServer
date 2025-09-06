#pragma once
#include <stdint.h>
#include <stddef.h>
#include "WebSocketServer.h"
#include "EventMessage.h"

typedef struct EventServer_t {
  PWebSocketServer wsServer;
  PSocketMethod onReceive; // void (*method)(PResponseObject, void *)
  PSocketMethod onClose; // void (*method)(PConnection, void *)
} EventServer;

typedef struct ResponseObject_t {
  EventMessage metaData;
  PConnection conn;
} ResponseObject;

typedef ResponseObject *PResponseObject;
typedef EventServer *PEventServer;

PEventServer evs_Create(uint16_t port);
void evs_Delete(PEventServer self);