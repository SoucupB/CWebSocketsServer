#include "NetworkBuffer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static inline size_t tpd_Min(const size_t a, const size_t b) {
  return a < b ? a : b;
}

PNetworkBuffer tpd_Create(size_t maxSizeB) {
  PNetworkBuffer self = malloc(sizeof(NetworkBuffer));
  const size_t capacity = 16;
  self->buffer = malloc(capacity);
  self->currentBuffer = self->buffer;
  self->size = 0;
  self->capacity = capacity;
  self->maxRetriedSize = 0;
  return self;
}

void tpd_Delete(PNetworkBuffer self) {
  free(self->buffer);
  free(self);
}

size_t tpd_Size(PNetworkBuffer self) {
  return self->size;
}

static inline void tpd_Retract_Realloc(const PNetworkBuffer self) {
  self->capacity = self->size * 2 + 1;
  void *newBuffer = malloc(self->capacity);
  memcpy(newBuffer, self->currentBuffer, (size_t)(self->size));
  free(self->buffer);
  self->buffer = newBuffer;
  self->currentBuffer = newBuffer;
  self->maxRetriedSize = self->size;
}

void tpd_Retract(PNetworkBuffer self, size_t bytes) {
  bytes = tpd_Min(bytes, self->size);
  self->size -= bytes;
  self->currentBuffer += bytes;
  if(self->maxRetriedSize >= (self->size << 1)) {
    tpd_Retract_Realloc(self);
    return ;
  }
}

void *tpd_StartingBuffer(PNetworkBuffer self) {
  return self->currentBuffer;
}

static inline void tpd_OverPush(const PNetworkBuffer self, const void *buffer, const size_t size) {
  while(self->capacity <= size + self->maxRetriedSize) {
    self->capacity <<= 1;
  }
  void *newBuffer = malloc(self->capacity);
  memcpy(newBuffer, self->currentBuffer, self->size);
  free(self->buffer);
  self->buffer = newBuffer;
  self->currentBuffer = newBuffer;
}

static inline void *tpd_EndBuffer(const PNetworkBuffer self) {
  return (void *)(self->currentBuffer + self->size);
}

void tpd_Push(PNetworkBuffer self, void *buffer, size_t size) {
  if(self->maxRetriedSize + size >= self->capacity) {
    tpd_OverPush(self, buffer, size);
  }
  memcpy(tpd_EndBuffer(self), buffer, size);
  self->size += size;
  self->maxRetriedSize += size;
}