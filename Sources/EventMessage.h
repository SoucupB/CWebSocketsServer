#pragma once
#include <stddef.h>
#include <stdint.h>

typedef struct Auth_t {
  uint8_t bff[8];
} Auth;

typedef struct EventBuffer_t {
  char *buffer;
  size_t size;
} EventBuffer;

typedef EventBuffer *PEventBuffer;

typedef struct EventMessage_t {
  uint32_t header; // request code + is_authed
  Auth uniqueCode;
  EventBuffer str;
} EventMessage;

typedef EventMessage *PEventMessage;

EventBuffer evm_Transform(PEventMessage self);
EventMessage evm_Parse(char *buffer, size_t size, uint8_t *valid);