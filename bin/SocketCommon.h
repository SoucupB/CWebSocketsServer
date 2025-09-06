#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct SocketMethod_t {
  void *method;
  void *mirrorBuffer; /*This buffer should be on heap or static memory but not on the stack*/
} SocketMethod;

typedef struct Connection_t {
  int32_t fd;
} Connection;

typedef struct DataFragment_t {
  uint32_t size;
  uint8_t persistent;
  Connection conn;
  char *data;
} DataFragment;

typedef SocketMethod *PSocketMethod;
typedef Connection *PConnection;
typedef DataFragment *PDataFragment;