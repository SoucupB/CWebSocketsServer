#pragma once
#include <stdint.h>
#include <stddef.h>
#include "Vector.h"

typedef struct WebSocketObject_t {
  char *buffer;
  size_t sz;
} WebSocketObject;

typedef WebSocketObject *PWebSocketObject;

char *wbs_ToWebSocket(WebSocketObject self);
Vector/*WebSocketObject*/ wbs_FromWebSocket(char *msg, size_t bufferSize);
void wbs_Print(char *buffer);
size_t wbs_FullMessageSize(char *buffer);
char *wbs_NextMessageIterator(char *st, size_t maxMessageSize);
uint8_t wbs_IsBufferValid(char *buffer, size_t sz);

size_t wbs_Public_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked);
size_t wbs_Public_PayloadSize(char *buffer);
size_t wbs_Public_PayloadSize(char *buffer);
size_t wbs_Raw_Public_HeaderSize(char *buffer);
char *wbs_Public_PayloadBuffer(char *buffer);