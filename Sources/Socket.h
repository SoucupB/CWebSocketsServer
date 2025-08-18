#pragma once

#include <stdint.h>
#include <stddef.h>
#include "Vector.h"
#include "TimeFragment.h"

typedef struct Connection_t {
  int32_t fd;
} Connection;

typedef struct DataFragment_t {
  uint32_t size;
  uint8_t persistent;
  Connection conn;
  char *data;
} DataFragment;

typedef struct SocketMethod_t {
  void *method;
  void *mirrorBuffer; /*This buffer should be on heap or static memory but not on the stack*/
} SocketMethod;

typedef SocketMethod *PSocketMethod;
typedef Connection *PConnection;

typedef struct Timers_t {
  PTimeServer timeServer;
  int64_t timeout;
} Timers;

typedef struct SocketServer_t {
  uint16_t port;
  int32_t maxActiveConnections;
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
// Default is set to 16 max concurent connections
void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections);
void sock_AddConnectionTimeout(PSocketServer self, int64_t expireAfter);

PSocketMethod sock_Method_Create(void *method, void *mirrorBuffer);
void sock_Method_Delete(PSocketMethod self);