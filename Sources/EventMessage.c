#include "EventMessage.h"
#include <string.h>
#include <stdlib.h>

#define ENDING_CODE 47323

static inline uint8_t evm_Out_IsAuthed(const PEventMessage self) {
  return (self->header & 0xFFFFFFFF) != 0;
}

static inline char *evm_Out_PayloadSizePointer(const PEventMessage self, char *buffer) {
  return buffer;
}

static inline char *evm_Out_HeaderPointer(const PEventMessage self, char *buffer) {
  return buffer + sizeof(self->str.size);
}

static inline char *evm_Out_HeaderAuthPointer(const PEventMessage self, char *buffer) {
  if(!evm_Out_IsAuthed(self)) {
    return NULL;
  }
  return evm_Out_HeaderPointer(self, buffer) + sizeof(self->header);
}

static inline char *evm_Out_PayloadPointer(const PEventMessage self, char *buffer) {
  if(evm_Out_IsAuthed(self)) {
    return evm_Out_HeaderPointer(self, buffer) + sizeof(self->header);
  }
  return evm_Out_HeaderPointer(self, buffer) + sizeof(self->header) + sizeof(Auth);
}

static inline uint32_t evm_TotalSize(const PEventMessage self) {
  return self->str.size + sizeof(self->header) + sizeof(self->str.size) + sizeof(Auth) * evm_Out_IsAuthed(self);
}

EventBuffer evm_Transform(const PEventMessage self) {
  uint32_t totalSize = evm_TotalSize(self);
  char *buffer = malloc(totalSize);
  memcpy(evm_Out_PayloadSizePointer(self, buffer), &self->str.size, sizeof(self->str.size));
  memcpy(evm_Out_HeaderPointer(self, buffer), &self->header, sizeof(self->header));
  char *headerPointer = evm_Out_HeaderAuthPointer(self, buffer);
  if(headerPointer) {
    memcpy(headerPointer, self->uniqueCode.bff, sizeof(self->uniqueCode));
  }
  memcpy(evm_Out_PayloadPointer(self, buffer), self->str.buffer, self->str.size);
  return (EventBuffer) {
    .buffer = buffer,
    .size = totalSize
  };
}

EventMessage evm_Parse(char *buffer, size_t size, uint8_t *valid) {
  return (EventMessage) {};
}