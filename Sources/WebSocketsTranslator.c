#include "WebSocketsTranslator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include "Vector.h"

#define MAX_FRAME_SIZE (1024 * 1024 * 1024) 

static inline char *wbs_PayloadBuffer(char *buffer);
static inline uint8_t wbs_IsMasked(char *buffer);
static inline char *wbs_MaskOffset(char *msg);

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

static inline void wbs_SetMaskFlag(char *buffer) {
  buffer[1] |= (1<<7);
}

static inline uint8_t wbs_SizeCode(char *buffer) {
  return (buffer[1] & ((1<<7) - 1));
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
  size_t maskSize = wbs_IsMasked(buffer) * 4;
  switch (wbs_SizeCode(buffer))
  {
    case 126: {
      wbs_RevertBytes(currentNumberPointer, currentNumberPointer + sizeof(uint16_t), buffer + 2);
      return sizeof(uint16_t) + maskSize;
      break;  
    }

    case 127: {
      wbs_RevertBytes(currentNumberPointer, currentNumberPointer + sizeof(uint64_t), buffer + 2);
      return sizeof(uint64_t) + maskSize;
      break;  
    }
  
    default:
      break;
  }
  return maskSize;
}

static inline void wbs_WritePayload(char *buffer, const PWebSocketObject obj) {
  memcpy(buffer, obj->buffer, obj->sz);
}

static inline size_t wbs_Object_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked) {
  size_t maskData = shouldBeMasked * 4;
  if(obj->sz <= 125) {
    return obj->sz + 2 + maskData;
  }
  if(obj->sz <= (1<<16)) {
    return obj->sz + 4 + maskData;
  }
  return obj->sz + 10 + maskData;
}

static inline size_t wbs_Raw_HeaderSize(char *buffer) {
  return (size_t)(wbs_PayloadBuffer(buffer) - buffer);
}

size_t wbs_Raw_Public_HeaderSize(char *buffer) {
  return wbs_Raw_HeaderSize(buffer);
}

size_t wbs_Public_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked) {
  return wbs_Object_HeaderSize(obj, shouldBeMasked);
}

static inline char *wbs_SetPayloadCode(char *buffer, const PWebSocketObject obj) {
  if(obj->sz <= 125) {
    buffer[1] |= obj->sz;
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
  uint8_t size = wbs_SizeCode(buffer);
  if(size < 126) {
    return size;
  }
  if(size == 126) {
    wbs_RevertBytes(buffer + 2, buffer + 2 + sizeof(uint16_t), (char *)&result);
    return result;
  }
  if(size == 127) {
    wbs_RevertBytes(buffer + 2, buffer + 2 + sizeof(uint64_t), (char *)&result);
    return result;
  }
  return 0;
}

size_t wbs_Public_PayloadSize(char *buffer) {
  return wbs_PayloadSize(buffer);
}

static inline char *wbs_PayloadBuffer(char *buffer) {
  size_t maskOffset = wbs_IsMasked(buffer) * 4;
  uint8_t size = wbs_SizeCode(buffer);
  if(size < 126) {
    return buffer + 2 + maskOffset;
  }
  if(size == 126) {
    return buffer + 4 + maskOffset;
  }
  return buffer + 10 + maskOffset;
}

char *wbs_Public_PayloadBuffer(char *buffer) {
  return wbs_PayloadBuffer(buffer);
}

uint8_t wbs_IsBufferValid(char *buffer, size_t sz) {
  char *endBuffer = buffer + sz;
  while(buffer < endBuffer) {
    size_t currentSize = (size_t)(endBuffer - buffer);
    char *nextBuffer = wbs_NextMessageIterator(buffer, currentSize);
    if(!nextBuffer) {
      return 0;
    }
    buffer = nextBuffer;
  }
  return buffer == endBuffer;
}

static inline size_t wbs_ValidMinimumSize(char *buffer) {
  size_t maskSize = wbs_IsMasked(buffer) * 4;
  uint8_t size = wbs_SizeCode(buffer);
  if(size < 126) {
    return 2 + maskSize;
  }
  if(size == 126) {
    return 4 + maskSize;
  }
  return 10 + maskSize;
}

char *wbs_NextMessageIterator(char *st, size_t maxMessageSize) {
  if(maxMessageSize < 2) {
    return NULL;
  }
  if(wbs_ValidMinimumSize(st) > maxMessageSize) {
    return NULL;
  }
  size_t messageSz = wbs_FullMessageSize(st);
  if(messageSz > maxMessageSize) {
    return NULL;
  }
  return st + messageSz;
}

size_t wbs_FullMessageSize(char *buffer) {
  return wbs_Raw_HeaderSize(buffer) + wbs_PayloadSize(buffer);
}

void wbs_Print(char *buffer) {
  printf("First byte 0x%x\n", (uint8_t)buffer[0]);
  uint8_t size = wbs_SizeCode(buffer);
  printf("Size cateogry byte is 0x%x\n", size);
  switch (size)
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
  printf("Mask bit is 0x%x\n", wbs_IsMasked(buffer));
  const size_t payloadSize = wbs_PayloadSize(buffer), messageSize = wbs_FullMessageSize(buffer);
  printf("Payload is size is %ld\n", payloadSize);
  _wbs_PrintNextBytes(wbs_PayloadBuffer(buffer), payloadSize);
  printf("Full message size is %ld\n", messageSize);
  _wbs_PrintNextBytes(buffer, messageSize);
}

static inline char *_wbs_ToWebSocket(WebSocketObject self, Opcode opcode) {
  char *response = malloc(wbs_Object_HeaderSize(&self, 0));
  wbs_ClearHeaderBytes(response);
  wbs_SetFin(response);
  wbs_SetOpcodeTo(response, opcode);
  char *cpyResponse = response;
  cpyResponse = wbs_SetPayloadCode(response, &self) + 1 /*First byte*/;
  wbs_WritePayload(cpyResponse, &self);
  return response;
}

char *wbs_ToWebSocket(WebSocketObject self) {
  return _wbs_ToWebSocket(self, self.opcode);
}

void wbs_MaskSwitch(char *buffer) {
  char *maskOffset = wbs_MaskOffset(buffer);
  char *payloadOffset = wbs_PayloadBuffer(buffer);
  for(size_t i = 0, c = 0, z = wbs_PayloadSize(buffer); i < z; i++, c = ((c + 1) & 3)) {
    payloadOffset[i] ^= maskOffset[c];
  }
}

static inline void wbs_Mask_Set(char *buffer) {
  if(!wbs_IsMasked(buffer)) {
    return ;
  }
  char *maskOffset = wbs_MaskOffset(buffer);
  for(size_t i = 0; i < sizeof(uint32_t); i++) {
    maskOffset[i] = (rand() & 0xFF);
  }
  wbs_MaskSwitch(buffer);
}

char *wbs_Masked_ToWebSocket(WebSocketObject self) {
  char *response = malloc(wbs_Object_HeaderSize(&self, 1));
  wbs_ClearHeaderBytes(response);
  wbs_SetFin(response);
  wbs_SetMaskFlag(response);
  wbs_SetOpcodeTo(response, OPCODE_BINARY);
  char *cpyResponse = response;
  cpyResponse = wbs_SetPayloadCode(response, &self) + 1 /*First byte*/;
  wbs_WritePayload(cpyResponse, &self);
  wbs_Mask_Set(response);
  return response;
}

char *wbs_Ping(WebSocketObject self) {
  return _wbs_ToWebSocket(self, OPCODE_PING);
}

static inline char *wbs_UnmaskedBuffer(char *msg) {
  return wbs_PayloadBuffer(msg);
}

static inline char *wbs_MaskOffset(char *msg) {
  return wbs_PayloadBuffer(msg) - sizeof(uint32_t);
}

static inline char *wbs_MaskedPayload(char *msg) {
  wbs_MaskSwitch(msg);
  return wbs_PayloadBuffer(msg);
}

char *wbs_ExtractPayload(char *msg) {
  if(!wbs_IsMasked(msg)) {
    return wbs_UnmaskedBuffer(msg);
  }
  return wbs_MaskedPayload(msg);
}

void wbs_Clear_FromWebSocket(Vector objects) {
  vct_Delete(objects);
}

Vector wbs_FromWebSocket(char *msg, size_t bufferSize) {
  if(!wbs_IsBufferValid(msg, bufferSize)) {
    return NULL;
  }
  char *endBuffer = msg + bufferSize;
  Vector buffer = vct_Init(sizeof(WebSocketObject));
  while(msg < endBuffer) {
    WebSocketObject obj = (WebSocketObject) {
      .buffer = wbs_ExtractPayload(msg),
      .sz = wbs_PayloadSize(msg)
    };
    if(!obj.buffer) {
      wbs_Clear_FromWebSocket(buffer);
      return NULL;
    }
    vct_Push(buffer, &obj);
    msg += wbs_FullMessageSize(msg);
  }

  return buffer;
}