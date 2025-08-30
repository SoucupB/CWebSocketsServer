#pragma once
#include "SocketClient.h"
#include "SocketServer.h"
#include "WebSocketServer.h"

PConnection test_Util_ExchangeConnection(PWebSocketServer wssServer);
void test_Wss_Util_Delete(PWebSocketServer self) ;