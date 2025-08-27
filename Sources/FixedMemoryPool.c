#include "FixedMemoryPool.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

static inline size_t fmp_MemoryFragmentSize(size_t objSize) {
  return sizeof(MemoryFragment) - sizeof(void *) + objSize;
}

static inline void fmp_PrepareMemory(const PFixedMemoryPool self) {
  if(self->bufferFragments) {
    return ;
  }
  self->bufferFragments = (MemoryFragment *)malloc(sizeof(MemoryFragment) * self->capacity);
  size_t totalSize = fmp_MemoryFragmentSize(self->objSize) * self->capacity;
  self->memory = malloc(totalSize);
  self->_endBuffer = (char *)self->memory + totalSize;
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

PFixedMemoryPool fmp_InitWithCapacity(size_t objSize, size_t capacity) {
  PFixedMemoryPool self = malloc(sizeof(FixedMemoryPool));
  memset(self, 0, sizeof(FixedMemoryPool));
  self->objSize = objSize;
  self->capacity = capacity;
  self->freeStack = stack_Init(capacity);
  return self;
}

PFixedMemoryPool fmp_Init(size_t objSize) {
  return fmp_InitWithCapacity(objSize, 128);
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

static inline PFixedMemoryPool fmp_FindPool(const PFixedMemoryPool self, const void *buffer) {
  PFixedMemoryPool current = self;
  while(1) {
    if(!current) {
      return NULL;
    }
    if(current->memory <= buffer && current->_endBuffer >= buffer) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void fmp_Free(PFixedMemoryPool self, void *buffer) {
  PFixedMemoryPool currentPool = fmp_FindPool(self, buffer);
  PMemoryFragment currentMemoryFragment = fmp_StartingPointer(buffer);
  assert(*currentMemoryFragment->flag == 1);
  stack_Push(&currentPool->freeStack, currentMemoryFragment->self);
  *currentMemoryFragment->flag = 0;
  currentPool->count--;
}

PMemoryFragment stack_Pop(PFixedMemoryPool self) {
  PFreeStackTracker currentStack = &self->freeStack;
  PMemoryFragment frag = *(PMemoryFragment *)(currentStack->stack + sizeof(PMemoryFragment) * (currentStack->sz - 1));
  currentStack->sz--;
  *frag->flag = 1;
  self->count++;
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
  PFixedMemoryPool newBuffer = fmp_InitWithCapacity(self->objSize, self->capacity * 10);
  self->next = newBuffer;
  return fmp_Alloc(newBuffer);
}

void *fmp_Alloc(PFixedMemoryPool self) {
  if(self->count >= self->capacity) {
    return fmp_NextBlock(self);
  }
  fmp_PrepareMemory(self);
  if(self->freeStack.sz) {
    return stack_Pop(self)->buffer;
  }
  return fmp_NormalMem(self);
}