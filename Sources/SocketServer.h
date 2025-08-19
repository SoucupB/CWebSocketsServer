#pragma once

#include <stdint.h>
#include <stddef.h>
#include "Vector.h"
#include "TimeFragment.h"
#include "SocketCommon.h"

typedef struct Timers_t {
  PTimeServer timeServer;
  int64_t timeout;
} Timers;

typedef struct SocketServer_t {
  uint16_t port;
  int32_t maxActiveConnections;
  int32_t maxBytesPerReadConnection;
  Connection serverFD;
  Vector connections;
  Vector inputReads;
  Vector outputCommands;
  PSocketMethod onConnectionRelease;
  PSocketMethod onConnectionAquire;
  PSocketMethod onReceiveMessage;
  Timers timeServer;
} SocketServer;

typedef SocketServer *PSocketServer;

PSocketServer sock_Create(uint16_t port);
void sock_Delete(PSocketServer self);
void sock_OnFrame(PSocketServer self, uint64_t deltaMS);
void sock_Write_Push(PSocketServer self, DataFragment *dt);
PConnection sock_FindConnectionByIndex(PSocketServer self, size_t index);
// Default is set to 16 max concurent connections
void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections);
void sock_AddConnectionTimeout(PSocketServer self, int64_t expireAfter);

PSocketMethod sock_Method_Create(void *method, void *mirrorBuffer);
void sock_Method_Delete(PSocketMethod self);