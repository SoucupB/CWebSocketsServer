#pragma once

#include <stdint.h>
#include <stddef.h>
#include "Vector.h"

typedef struct Connection_t {
  int32_t fd;
} Connection;

typedef struct SocketServer_t {
  uint16_t port;
  int32_t maxActiveConnections;
  Connection serverFD;
  Vector connections;
} SocketServer;

typedef SocketServer *PSocketServer;

typedef struct SocketClient_t {
  int32_t fd;
} SocketClient;

PSocketServer sock_Create(uint16_t port);
void sock_Delete(PSocketServer self);
void sock_OnFrame(PSocketServer self);
// Default is set to 16 max concurent connections
void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections);