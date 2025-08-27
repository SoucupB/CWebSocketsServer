#include "FixedMemoryPool.h"
#include <stdlib.h>
#include <string.h>

static inline size_t fmp_MemoryFragmentSize(size_t objSize) {
  return sizeof(MemoryFragment) - sizeof(void *) + objSize;
}

static inline void fmp_PrepareMemory(PFixedMemoryPool self) {
  self->buffer = (MemoryFragment *)malloc(fmp_MemoryFragmentSize(self->objSize) * self->capacity);
}

FixedMemoryPool fmp_Init(size_t objSize, size_t capacity) {
  FixedMemoryPool self;
  memset(&self, 0, sizeof(FixedMemoryPool));
  self.objSize = objSize;
  self.capacity = capacity;
  return self;
}

void *fmp_Alloc(PFixedMemoryPool self) {
  if(self->count >= self->capacity) {
    return NULL;
  }
  return NULL;
}