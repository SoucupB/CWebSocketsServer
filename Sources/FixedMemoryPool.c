#include "FixedMemoryPool.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

static inline FreeStackTracker stack_Init(size_t capacity) {
  FreeStackTracker self;
  self.stack = malloc(sizeof(PMemoryFragment) * capacity);
  self.sz = 0;
  return self;
}

PFixedMemoryPool fmp_Init(size_t objSize, size_t capacity) {
  PFixedMemoryPool self = malloc(sizeof(FixedMemoryPool));
  memset(&self, 0, sizeof(FixedMemoryPool));
  self->objSize = objSize;
  self->capacity = capacity;
  self->freeStack = stack_Init(capacity);
  return self;
}

static inline void *fmp_NormalMem(const PFixedMemoryPool self) {
  MemoryFragment fragment = self->bufferFragments[self->count];
  *fragment.flag = 1;
  self->count++;
  return fragment.buffer;
}

static inline PMemoryFragment fmp_StartingPointer(void *buffer) {
  return (void *)((char *)buffer - sizeof(PFixedMemoryPool *) - sizeof(size_t *));
}

static inline void stack_Push(PFreeStackTracker self, PMemoryFragment *memory) {
  memcpy((char *)self->stack + self->sz * sizeof(PMemoryFragment), memory, sizeof(PMemoryFragment));
  self->sz++;
}

void fmp_Free(PFixedMemoryPool self, void *buffer) {
  PMemoryFragment currentMemoryFragment = fmp_StartingPointer(buffer);
  assert(*currentMemoryFragment->flag == 1);
  stack_Push(&self->freeStack, currentMemoryFragment->self);
  *currentMemoryFragment->flag = 0;
}

PMemoryFragment stack_Pop(PFreeStackTracker self) {
  PMemoryFragment frag = (self->stack + sizeof(PMemoryFragment) * (self->sz - 1));
  self->sz--;
  return frag;
}

void fmp_Delete(PFixedMemoryPool self) {
  if(self->bufferFragments) {
    free(self->bufferFragments);
  }
  free(self->freeStack.stack);
  free(self);
}

void *fmp_Alloc(PFixedMemoryPool self) {
  fmp_PrepareMemory(self);
  if(self->count >= self->capacity) {
    return NULL;
  }
  if(self->freeStack.sz) {
    return stack_Pop(&self->freeStack);
  }
  return fmp_NormalMem(self);
}