#include "WebSocketsTranslator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>

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

static inline void wbs_RevertBytes(char *st, char *end, char *dst) {
  end--;
  for(char *it = end; it >= st; it--) {
    *dst = *it;
    dst++;
  }
}

static inline size_t wbs_SetPayloadSize(char *buffer, const PWebSocketObject obj) {
  char *currentNumberPointer = (char *)&obj->sz;
  switch (buffer[1])
  {
    case 126: {
      wbs_RevertBytes(currentNumberPointer, currentNumberPointer + sizeof(uint16_t), buffer + 2);
      return sizeof(uint16_t);
      break;  
    }

    case 127: {
      wbs_RevertBytes(currentNumberPointer, currentNumberPointer + sizeof(uint64_t), buffer + 2);
      return sizeof(uint64_t);
      break;  
    }
  
    default:
      break;
  }
  return 0;
}

static inline void wbs_WritePayload(char *buffer, const PWebSocketObject obj) {
  memcpy(buffer, obj->buffer, obj->sz);
}

static inline size_t wbs_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked) {
  size_t maskData = (!shouldBeMasked ? 0 : 4);
  if(obj->sz <= 125) {
    return obj->sz + 2 + maskData;
  }
  if(obj->sz <= (1<<16)) {
    return obj->sz + 4 + maskData;
  }
  return obj->sz + 10 + maskData;
}

size_t wbs_Public_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked) {
  return wbs_HeaderSize(obj, shouldBeMasked);
}

static inline char *wbs_SetPayloadCode(char *buffer, const PWebSocketObject obj) {
  if(obj->sz <= 125) {
    buffer[1] = obj->sz;
  }
  else if(obj->sz <= (1<<16)) {
    buffer[1] |= 126;
  } else {
    buffer[1] |= 127;
  }
  return buffer + 1 + wbs_SetPayloadSize(buffer, obj);
}

void _wbs_PrintNextBytes(char *buffer, size_t sz) {
  printf("(");
  for(size_t i = 0; i < sz; i++) {
    printf("0x%x ", (uint8_t)buffer[i]);
  }
  printf(")\n");
}

static inline uint8_t wbs_IsMasked(char *buffer) {
  return (buffer[1] & (1<<7)) > 0;
}

static inline size_t wbs_PayloadSize(char *buffer) {
  size_t result = 0;
  if(buffer[1] < 126) {
    return buffer[1];
  }
  if(buffer[1] == 126) {
    wbs_RevertBytes(buffer + 2, buffer + 2 + sizeof(uint16_t), (char *)&result);
    return result;
  }
  if(buffer[1] == 127) {
    wbs_RevertBytes(buffer + 2, buffer + 2 + sizeof(uint64_t), (char *)&result);
    return result;
  }
  return 0;
}

static inline char *wbs_PayloadBuffer(char *buffer) {
  size_t maskOffset = (wbs_IsMasked(buffer) ? 4 : 0);
  if(buffer[1] < 126) {
    return buffer + 2 + maskOffset;
  }
  if(buffer[1] == 126) {
    return buffer + 4 + maskOffset;
  }
  return buffer + 10 + maskOffset;
}

size_t wbs_FullMessageSize(char *buffer) {
  return (wbs_PayloadBuffer(buffer) - buffer) + wbs_PayloadSize(buffer);
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
  const size_t payloadSize = wbs_PayloadSize(buffer), messageSize = wbs_FullMessageSize(buffer);
  printf("Payload is size is %ld\n", payloadSize);
  _wbs_PrintNextBytes(wbs_PayloadBuffer(buffer), payloadSize);
  printf("Full message size is %ld\n", messageSize);
  _wbs_PrintNextBytes(buffer, messageSize);
}

char *wbs_ToWebSocket(WebSocketObject self) {
  char *response = malloc(wbs_HeaderSize(&self, 0));
  wbs_ClearHeaderBytes(response);
  wbs_SetFin(response);
  wbs_SetOpcodeTo(response, OPCODE_BINARY);
  char *cpyResponse = response;
  cpyResponse = wbs_SetPayloadCode(response, &self) + 1 /*First byte*/;
  wbs_WritePayload(cpyResponse, &self);
  return response;
}

WebSocketObject wbs_FromWebSocket(char *msg, uint8_t *isValid) {
  *isValid = 0;
  return (WebSocketObject) {};
}