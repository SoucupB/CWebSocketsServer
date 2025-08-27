#include "FixedMemoryPool.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

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
    // printf("ZZZ %p %p\n", self->bufferFragments[i].buffer, self->bufferFragments[i].self);
    *self->bufferFragments[i].flag = 0;
    *self->bufferFragments[i].self = &self->bufferFragments[i];
    memory += fmp_MemoryFragmentSize(self->objSize);
  }
}

void fmp_PrintMemory(PFixedMemoryPool self) {
  for(size_t i = 0, c = self->capacity * fmp_MemoryFragmentSize(self->objSize); i < c; i++) {
    printf("%d ", ((uint8_t *)self->memory)[i]);
  }
  printf("\n");
}

static inline FreeStackTracker stack_Init(size_t capacity) {
  FreeStackTracker self;
  self.stack = malloc(sizeof(PMemoryFragment) * capacity);
  self.sz = 0;
  return self;
}

PFixedMemoryPool fmp_Init(size_t objSize, size_t capacity) {
  PFixedMemoryPool self = malloc(sizeof(FixedMemoryPool));
  memset(self, 0, sizeof(FixedMemoryPool));
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
  return *(PMemoryFragment *)((char *)buffer - sizeof(PFixedMemoryPool *));
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
  *frag->flag = 1;
  return frag;
}

void fmp_Delete(PFixedMemoryPool self) {
  if(!self) {
    return ;
  }
  fmp_Delete(self->next);
  if(self->bufferFragments) {
    free(self->bufferFragments);
  }
  if(self->memory) {
    free(self->memory);
  }
  free(self->freeStack.stack);
  free(self);
}

void *fmp_NextBlock(PFixedMemoryPool self) {
  if(self->next) {
    return fmp_Alloc(self->next);
  }
  PFixedMemoryPool newBuffer = fmp_Init(self->objSize, self->capacity * 10);
  self->next = newBuffer;
  return fmp_Alloc(self->next);
}

void *fmp_Alloc(PFixedMemoryPool self) {
  fmp_PrepareMemory(self);
  if(self->count >= self->capacity) {
    return fmp_NextBlock(self);
  }
  if(self->freeStack.sz) {
    self->count--;
    return stack_Pop(&self->freeStack);
  }
  return fmp_NormalMem(self);
}