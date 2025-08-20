#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct WebSocketObject_t {
  uint8_t opcode;
} WebSocketObject;

char *wbs_ToWebSocket(char *msg, size_t sz);