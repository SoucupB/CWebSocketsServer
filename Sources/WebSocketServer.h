#pragma once
#include "SocketServer.h"
#include "HttpParser.h"

typedef struct PrivateMethodsBundle_t {
  PSocketMethod _onConnect;
  PSocketMethod _onReceive;
  PSocketMethod _onRelease;
} PrivateMethodsBundle;

typedef struct WebSocketServer_t {
  PSocketServer socketServer;
  PSocketMethod onConnect;
  PSocketMethod onReceiveMessage;
  PSocketMethod onRelease;
  PrivateMethodsBundle methodsBundle;
  Vector pendingConnections;
} WebSocketServer;

typedef WebSocketServer *PWebSocketServer;

PWebSocketServer wss_Create(uint16_t port);
size_t wss_ConnectionsCount(PWebSocketServer self);
void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS);
void wss_Delete(PWebSocketServer self);