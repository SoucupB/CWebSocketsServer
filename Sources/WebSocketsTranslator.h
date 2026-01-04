#pragma once
#include <stdint.h>
#include <stddef.h>
#include "Structs.h"
#include "NetworkBuffer.h"

char *wbs_ToWebSocket(WebSocketObject self);
Array/*WebSocketObject*/ wbs_FromWebSocket(char *msg, size_t bufferSize);
void wbs_Print(char *buffer);
size_t wbs_FullMessageSize(char *buffer);
char *wbs_NextMessageIterator(char *st, size_t maxMessageSize);
uint8_t wbs_IsBufferValid(char *buffer, size_t sz);
void wbs_Clear_FromWebSocket(Array objects);
char *wbs_Masked_ToWebSocket(WebSocketObject self);
void wbs_MaskSwitch(char *buffer);
char *wbs_Ping(WebSocketObject self);
WebSocketObject wbs_Get(char *left, char *right);

size_t wbs_Public_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked);
size_t wbs_Public_PayloadSize(char *buffer);
size_t wbs_Public_PayloadSize(char *buffer);
size_t wbs_Raw_Public_HeaderSize(char *buffer);

char *wbs_Public_PayloadBuffer(char *buffer);
uint8_t wbs_Public_GetCode(char *buffer);
Array wbs_Public_ParseData(PNetworkBuffer self);