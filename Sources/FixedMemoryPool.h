#pragma once

#include <stdint.h>
#include <stddef.h>

typedef struct MemoryFragment_t {
  char *flag;
  void *buffer;
} MemoryFragment;

typedef struct FreeStackTracker_t {
  void *stack;
  size_t sz;
} FreeStackTracker;

typedef struct FixedMemoryPool_t {
  MemoryFragment *buffer;
  FreeStackTracker freeStack;
  size_t count;
  size_t objSize;
  size_t capacity;
  struct FixedMemoryPool_t *next;
} FixedMemoryPool;

typedef FixedMemoryPool *PFixedMemoryPool;

FixedMemoryPool fmp_Init(size_t objSize, size_t capacity);