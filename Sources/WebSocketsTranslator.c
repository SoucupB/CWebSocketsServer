#include "WebSocketsTranslator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum {
  OPCODE_CONTINUATION_FRAME = 0x0,
  OPCODE_TEXT_FRAME = 0x1,
  OPCODE_BINARY = 0x2,
  OPCODE_CONNECTION_CLOSE = 0x8,
  OPCODE_PING = 0x9,
  OPCODE_PONG = 0xA
} Opcode;

static inline void wbs_SetOpcodeTo(char *buffer, Opcode code) {
  buffer[0] |= code;
}

static inline void wbs_SetFin(char *buffer) {
  buffer[0] |= (1<<7);
}

static inline void wbs_ClearHeaderBytes(char *buffer) {
  buffer[0] = 0;
  buffer[1] = 0;
}

static inline void wbs_SetPayloadSize(char *buffer, const PWebSocketObject obj) {
  if(buffer[1] == 126) {
    memcpy(buffer + 2, &obj->sz, sizeof(uint16_t));
    return ;
  }
  if(buffer[1] == 127) {
    memcpy(buffer + 2, &obj->sz, sizeof(uint64_t));
    return ;
  }
}

static inline void wbs_SetPayloadCode(char *buffer, const PWebSocketObject obj) {
  if(obj->sz <= 125) {
    buffer[1] = obj->sz;
  }
  else if(obj->sz <= (1<<16)) {
    buffer[1] = 126;
    return ;
  } else {
    buffer[1] = 127;
  }
  wbs_SetPayloadSize(buffer, obj);
}

void _wbs_PrintNextBytes(char *buffer, size_t sz) {
  printf("(");
  for(size_t i = 0; i < sz; i++) {
    printf("0x%x ", (uint8_t)buffer[i]);
  }
  printf(")\n");
}

void wbs_PrintHeader(char *buffer) {
  printf("First byte 0x%x\n", (uint8_t)buffer[0]);
  printf("Size cateogry byte is 0x%x\n", ((uint8_t)buffer[1] & ((1<<7) - 1)));
  switch (buffer[1])
  {
    case 126:
      _wbs_PrintNextBytes(buffer + 2, sizeof(uint16_t));
      break;

    case 127:
      _wbs_PrintNextBytes(buffer + 2, sizeof(uint64_t));
      break;
    
    default:
      break;
  }
  printf("Mask bit is 0x%x\n", ((uint8_t)buffer[1] & (1<<7)) > 0);
}

char *wbs_ToWebSocket(WebSocketObject self) {
  char *response = malloc(1024);
  wbs_ClearHeaderBytes(response);
  wbs_SetFin(response);
  wbs_SetOpcodeTo(response, OPCODE_BINARY);
  wbs_SetPayloadCode(response, &self);
  return response;
}

WebSocketObject wbs_FromWebSocket(char *msg, uint8_t *isValid) {
  *isValid = 0;
  return (WebSocketObject) {};
}