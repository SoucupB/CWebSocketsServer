#pragma once
#include "SocketServer.h"
#include "HttpParser.h"
#include "TimeFragment.h"

typedef struct PrivateMethodsBundle_t {
  PSocketMethod _onConnect;
  PSocketMethod _onReceive;
  PSocketMethod _onRelease;
} PrivateMethodsBundle;

typedef struct Timeout_t {
  uint64_t timeout;
  PTimeServer server;
} Timeout;

typedef Timeout *PTimeout;

typedef struct WebSocketServer_t {
  PSocketServer socketServer;
  PSocketMethod onConnect;
  PSocketMethod onReceiveMessage;
  PSocketMethod onRelease;
  PrivateMethodsBundle methodsBundle;
  Vector pendingConnections;
  PTimeout timeServer;
} WebSocketServer;

typedef WebSocketServer *PWebSocketServer;

PWebSocketServer wss_Create(uint16_t port);
size_t wss_ConnectionsCount(PWebSocketServer self);
void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS);
void wss_EnablePingPongTimeout(PWebSocketServer self, uint64_t timeout);
void wss_Delete(PWebSocketServer self);
void wss_SendMessage(PWebSocketServer self, PDataFragment dt);