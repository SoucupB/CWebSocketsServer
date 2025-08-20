#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct WebSocketObject_t {
  char *buffer;
  size_t sz;
} WebSocketObject;

char *wbs_ToWebSocket(char *msg, size_t sz);
WebSocketObject wbs_FromWebSocket(char *msg, uint8_t *isValid);