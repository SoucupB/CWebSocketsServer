#pragma once
#include <stddef.h>
#include <stdint.h>

typedef struct Auth_t {
  uint8_t bff[8];
} Auth;

typedef Auth *PAuth;

typedef struct EventBuffer_t {
  char *buffer;
  size_t size;
} EventBuffer;

typedef EventBuffer *PEventBuffer;

typedef struct EventMessage_t {
  uint8_t isAuthed;
  uint32_t headerCode; // request code + is_authed
  Auth uniqueCode;
  EventBuffer str;
} EventMessage;

// <payload_size> <header> <auth_code> (if necessary) <payload>

typedef EventMessage *PEventMessage;

EventBuffer evm_New_Transform(const PEventMessage self);
EventBuffer evm_Reuse_Transform(const PEventMessage self, char *buffer);
EventMessage evm_Parse(EventBuffer buffer, uint8_t *valid);