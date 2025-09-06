#pragma once
#include <stdint.h>
#include <stddef.h>
#include "WebSocketServer.h"

typedef struct EventServer_t {
  PWebSocketServer wsServer;
} EventServer;

typedef EventServer *PEventServer;