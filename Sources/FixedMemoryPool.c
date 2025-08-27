#include "FixedMemoryPool.h"
#include <stdlib.h>
#include <string.h>

static inline size_t fmp_MemoryFragmentSize(size_t objSize) {
  return sizeof(MemoryFragment) - sizeof(void *) + objSize;
}

static inline void fmp_PrepareMemory(PFixedMemoryPool self) {
  if(self->bufferFragments) {
    return ;
  }
  self->bufferFragments = (MemoryFragment *)malloc(sizeof(MemoryFragment) * self->capacity);
  self->memory = malloc(fmp_MemoryFragmentSize(self->objSize) * self->capacity);
  char *memory = self->memory;
  for(size_t i = 0, c = self->capacity; i < c; i++) {
    self->bufferFragments[i] = (MemoryFragment) {
      .flag = (size_t *)memory,
      .self = (PMemoryFragment *)(memory + sizeof(size_t *)),
      .buffer = (void *)(memory + sizeof(size_t *) + sizeof(PMemoryFragment *))
    };
    *self->bufferFragments[i].flag = 0;
    *self->bufferFragments[i].self = &self->bufferFragments[i];
    memory += fmp_MemoryFragmentSize(self->objSize);
  }
}

PFixedMemoryPool fmp_Init(size_t objSize, size_t capacity) {
  PFixedMemoryPool self = malloc(sizeof(FixedMemoryPool));
  memset(&self, 0, sizeof(FixedMemoryPool));
  self->objSize = objSize;
  self->capacity = capacity;
  return self;
}

static inline void *fmp_NormalMem(const PFixedMemoryPool self) {
  MemoryFragment fragment = self->bufferFragments[self->count];
  *fragment.flag = 1;
  self->count++;
  return fragment.buffer;
}

void *fmp_Alloc(PFixedMemoryPool self) {
  fmp_PrepareMemory(self);
  if(self->count >= self->capacity) {
    return NULL;
  }
  return fmp_NormalMem(self);
}