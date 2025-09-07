#pragma once
#include "Structs.h"
#include "SocketClient.h"
#include "SocketServer.h"
#include "WebSocketServer.h"

PConnection test_Wss_Util_ExchangeConnection(PWebSocketServer wssServer);
void test_Wss_Util_Delete(PWebSocketServer self);
PConnection test_Wss_Util_Connect(PWebSocketServer wssServer, char *input);
void test_Wss_RepeatFramesDiff(PWebSocketServer self, uint64_t deltaMS, uint32_t repeats);
void test_Wss_SendMessage(PWebSocketServer sv, PConnection conn, char *buffer, size_t sz);
void test_Wss_BufferMessage(PWebSocketServer wssServer, PConnection conn, char *buffer, size_t sz);
void test_Wss_Expect(PConnection conn, char *buffer, size_t sz);
void test_Wss_WaitAndRunUntil(PWebSocketServer sv, int64_t timeout, uint8_t (*method)(void *), void *buffer);
void test_Wss_SendPing(PWebSocketServer wssServer, PConnection conn);
void test_Wss_SendPong(PWebSocketServer wssServer, PConnection conn);
void test_Wss_PingPong(PWebSocketServer wssServer, PConnection conn, uint64_t pingAt);