#pragma once
#include "SocketServer.h"
#include "HttpParser.h"
#include "TimeFragment.h"
#include "Structs.h"

PWebSocketServer wss_Create(uint16_t port);
size_t wss_ConnectionsCount(PWebSocketServer self);
void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS);
void wss_EnablePingPongTimeout(PWebSocketServer self, uint64_t timeout);
void wss_Delete(PWebSocketServer self);
void wss_SendMessage(PWebSocketServer self, PDataFragment dt);