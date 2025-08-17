#pragma once

#include <stdint.h>
#include <stddef.h>
#include "Vector.h"

typedef struct Connection_t {
  int32_t fd;
} Connection;

typedef struct SocketServer_t {
  uint16_t port;
  Connection serverFD;
  Vector connections;
} SocketServer;

typedef SocketServer *PSocketServer;

typedef struct SocketClient_t {
  int32_t fd;
} SocketClient;

PSocketServer sock_Create(uint16_t port);
void sock_Delete(PSocketServer self);