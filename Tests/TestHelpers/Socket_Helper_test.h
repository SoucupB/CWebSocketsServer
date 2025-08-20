#pragma once
#include <stdint.h>
#include "SocketClient.h"
#include "SocketServer.h"
#include <string.h>
#include <stdio.h>

PSocketServer test_Util_PrepareServer(uint16_t port, void *method, void *buffer);
DataFragment test_Util_GetDT(PConnection conn, char *msg, size_t sz);
void test_Util_WriteTo(PSocketServer server, size_t index, char *msg, size_t sz, uint32_t times);
void test_Util_Release(PSocketServer self);
void test_Util_Expect(PConnection conn, char *buffer, size_t sz);
PConnection test_Util_Connect(PSocketServer server);
void test_Util_SendMessage(PSocketServer server, PConnection conn, char *msg, size_t sz);