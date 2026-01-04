#include "NetworkBuffer.h"
#include <stdlib.h>
#include <string.h>

PNetworkBuffer tpd_Create(size_t maxSizeB) {
  PNetworkBuffer self = malloc(sizeof(NetworkBuffer));
  const size_t capacity = 16;
  self->buffer = malloc(capacity);
  self->currentBuffer = self->buffer;
  self->size = 0;
  self->capacity = capacity;
  return self;
}

void tpd_Delete(PNetworkBuffer self) {

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
}

void tpd_Retract(PNetworkBuffer self, size_t bytes) {
  const size_t oldSize = self->size;
  if(oldSize < bytes) {
    self->size = 0;
  }
  else {
    self->size -= bytes;
  }
  if(oldSize >= self->size * 2) {
    tpd_Retract_Realloc(self);
    return ;
  }
  self->currentBuffer += bytes;
}

void *tpd_StartingBuffer(PNetworkBuffer self) {
  return self->currentBuffer;
}

static inline void tpd_OverPush(const PNetworkBuffer self, void *buffer, size_t size) {
  while(self->capacity <= size + self->size) {
    self->capacity *= 2;
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
  if(self->size + size >= self->capacity) {
    tpd_OverPush(self, buffer, size);
  }
  memcpy(tpd_EndBuffer(self), buffer, size);
  self->size += size;
}