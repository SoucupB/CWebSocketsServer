#include "EventMessage.h"
#include <string.h>
#include <stdlib.h>

static inline uint8_t evm_Out_IsAuthed(const PEventMessage self) {
  return self->isAuthed;
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
  return evm_Out_HeaderPointer(self, buffer) + sizeof(self->headerCode);
}

static inline char *evm_Out_PayloadPointer(const PEventMessage self, char *buffer) {
  if(!evm_Out_IsAuthed(self)) {
    return evm_Out_HeaderPointer(self, buffer) + sizeof(self->headerCode);
  }
  return evm_Out_HeaderPointer(self, buffer) + sizeof(self->headerCode) + sizeof(Auth);
}

static inline char *evm_In_SizePointer(char *buffer) {
  return buffer;
}

static inline char *evm_In_HeaderPointer(char *buffer) {
  return evm_In_SizePointer(buffer) + sizeof(uint32_t);
}

static inline uint32_t evm_In_Size(char *buffer) {
  return *(uint32_t *)evm_In_SizePointer(buffer);
}

static inline uint32_t evm_In_Header(char *buffer) {
  return *(uint32_t *)evm_In_HeaderPointer(buffer);
}

static inline uint32_t evm_In_HeaderCode(char *buffer) {
  return (evm_In_Header(buffer) & 0xFFFFFF);
}

static inline uint8_t evm_In_HeaderIsAuth(char *buffer) {
  return (evm_In_Header(buffer) & (1<<24)) != 0; 
}

static inline char *evm_In_AuthPointer(char *buffer) {
  if(!evm_In_HeaderIsAuth(buffer)) {
    return NULL;
  }
  return evm_In_HeaderPointer(buffer) + sizeof(uint32_t);
}

static inline char *evm_In_PayloadPointer(char *buffer) {
  return evm_In_HeaderPointer(buffer) + ((size_t)evm_In_AuthPointer(buffer) != 0) * sizeof(Auth) + sizeof(uint32_t);
}

static inline char *evm_In_EndPointer(char *buffer) {
  return evm_In_PayloadPointer(buffer) + evm_In_Size(buffer);
}

static inline uint32_t evm_Out_TotalSize(const PEventMessage self) {
  return self->str.size + sizeof(self->headerCode) + sizeof(self->str.size) + sizeof(Auth) * evm_Out_IsAuthed(self);
}

uint32_t evm_Out_Public_TotalSize(PEventMessage self) {
  return evm_Out_TotalSize(self);
}

EventBuffer evm_Reuse_Transform(const PEventMessage self, char *buffer) {
  uint32_t totalSize = evm_Out_TotalSize(self);
  memcpy(evm_Out_PayloadSizePointer(self, buffer), &self->str.size, sizeof(self->str.size));
  uint32_t mergedHeaders = (self->headerCode | ((1<<24) * self->isAuthed));
  memcpy(evm_Out_HeaderPointer(self, buffer), &mergedHeaders, sizeof(mergedHeaders));
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

EventBuffer evm_New_Transform(const PEventMessage self) {
  uint32_t totalSize = evm_Out_TotalSize(self);
  char *buffer = malloc(totalSize);
  return evm_Reuse_Transform(self, buffer);
}

EventMessage evm_Parse(EventBuffer inp, uint8_t *valid) {
  *valid = 0;
  char *endBuffer = evm_In_EndPointer(inp.buffer);
  if(endBuffer != inp.size + inp.buffer) {
    return (EventMessage) {};
  }
  EventMessage response = (EventMessage) {
    .isAuthed = evm_In_HeaderIsAuth(inp.buffer),
    .headerCode = evm_In_HeaderCode(inp.buffer),
    .str = (EventBuffer) {
      .buffer = evm_In_PayloadPointer(inp.buffer),
      .size = evm_In_Size(inp.buffer)
    }
  };
  char *authCode = evm_In_AuthPointer(inp.buffer);
  if(authCode) {
    memcpy(response.uniqueCode.bff, authCode, sizeof(Auth));
  }
  *valid = 1;
  return response;
}