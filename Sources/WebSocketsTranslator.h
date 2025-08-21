#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct WebSocketObject_t {
  char *buffer;
  size_t sz;
} WebSocketObject;

typedef WebSocketObject *PWebSocketObject;

char *wbs_ToWebSocket(WebSocketObject self);
WebSocketObject wbs_FromWebSocket(char *msg, uint8_t *isValid);
void wbs_PrintHeader(char *buffer);
size_t wbs_FullMessageSize(char *buffer);

size_t wbs_Public_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked);