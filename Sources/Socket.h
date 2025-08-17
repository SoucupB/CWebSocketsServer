#pragma once

#include <stdint.h>
#include <stddef.h>
#include "Vector.h"

typedef struct Connection_t {
  int32_t fd;
} Connection;

typedef struct DataFragment_t {
  uint32_t size;
  uint8_t persistent;
  Connection conn;
  char *data;
} DataFragment;

typedef struct SocketServer_t {
  uint16_t port;
  int32_t maxActiveConnections;
  Connection serverFD;
  Vector connections;
  Vector inputReads;
  Vector outputCommands;
} SocketServer;

typedef struct SocketMethod_t {
  void (*method)(Connection conn, void *mirror);
  void *mirrorBuffer;
} SocketMethod;

typedef SocketServer *PSocketServer;

typedef struct SocketClient_t {
  int32_t fd;
} SocketClient;

PSocketServer sock_Create(uint16_t port);
void sock_Delete(PSocketServer self);
void sock_OnFrame(PSocketServer self);
void sock_Write_Push(PSocketServer self, DataFragment *dt);
// Default is set to 16 max concurent connections
void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections);