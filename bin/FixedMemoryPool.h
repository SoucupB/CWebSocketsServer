#pragma once

#include <stdint.h>
#include <stddef.h>

typedef struct MemoryFragment_t {
  size_t *flag;
  struct MemoryFragment_t **self;
  void *buffer;
} MemoryFragment;

typedef MemoryFragment *PMemoryFragment;

typedef struct FreeStackTracker_t {
  void *stack;
  size_t sz;
} FreeStackTracker;

typedef FreeStackTracker *PFreeStackTracker;

typedef struct FixedMemoryPool_t {
  MemoryFragment *bufferFragments;
  void *memory;
  void *_endBuffer;
  FreeStackTracker freeStack;
  size_t count;
  size_t objSize;
  size_t capacity;
  struct FixedMemoryPool_t *next;
} FixedMemoryPool;

typedef FixedMemoryPool *PFixedMemoryPool;

PFixedMemoryPool fmp_InitWithCapacity(size_t objSize, size_t capacity);
PFixedMemoryPool fmp_Init(size_t objSize);
void *fmp_Alloc(PFixedMemoryPool self);
void fmp_Free(PFixedMemoryPool self, void *buffer);
void fmp_PrintMemory(PFixedMemoryPool self);

void fmp_Delete(PFixedMemoryPool self);