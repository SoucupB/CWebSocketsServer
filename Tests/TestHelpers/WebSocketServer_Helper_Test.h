#pragma once
#include "SocketClient.h"
#include "SocketServer.h"
#include "WebSocketServer.h"

PConnection test_Wss_Util_ExchangeConnection(PWebSocketServer wssServer);
void test_Wss_Util_Delete(PWebSocketServer self);
PConnection test_Wss_Util_Connect(PWebSocketServer wssServer, char *input);
void test_Wss_RepeatFramesDiff(PWebSocketServer self, uint64_t deltaMS, uint32_t repeats);
void test_Wss_SendMessage(PWebSocketServer sv, PConnection conn, char *buffer, size_t sz) ;