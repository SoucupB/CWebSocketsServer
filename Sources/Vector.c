#include "Vector.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

#define crm_Alloc malloc
#define crm_Free free
#define crm_Realloc realloc

Vector vct_Init(size_t size) {
  Vector self = (Vector)crm_Alloc(sizeof(struct Vector_t));
  self->buffer = crm_Alloc(size);
  self->size = 0;
  self->capacity = 1;
  self->objSize = size;
  return self;
}

Vector vct_InitWithCapacity(size_t size, size_t count) {
  Vector self = crm_Alloc(sizeof(struct Vector_t));
  self->buffer = crm_Alloc(size * count);
  self->size = 0;
  self->capacity = count;
  self->objSize = size;
  return self;
}

Vector vct_InitWithSize(size_t objSize, size_t count) {
  Vector self = crm_Alloc(sizeof(struct Vector_t));
  self->buffer = crm_Alloc(objSize * count);
  self->size = count;
  self->capacity = count;
  self->objSize = objSize;
  return self;
}

void copyData(Vector self, void *buffer) {
  memcpy(self->buffer + (self->size * self->objSize), buffer, self->objSize);
  self->size++;
}

void vct_Push(Vector self, void *buffer) {
  if(self->size >= self->capacity) {
    self->capacity <<= 1;
    self->buffer = crm_Realloc(self->buffer, self->capacity * self->objSize);
  }
  copyData(self, buffer);
}

void vct_RemoveElement(Vector self, size_t index) {
  assert(self->size != 0);
  if(index >= self->size) {
    return ;
  }
  char *payloadBuffer = self->buffer;
  for(ssize_t i = index, c = (ssize_t)self->size - 1; i < c; i++) {
    memcpy(payloadBuffer + i * self->objSize, payloadBuffer + (i + 1) * self->objSize, self->objSize);
  }
  self->size--;
}

void vct_Delete(Vector self) {
  crm_Free(self->buffer);
  crm_Free(self);
}

void vct_DeleteWOBuffer(Vector self) {
  crm_Free(self);
}

char *vct_Last(Vector self) {
  if(!self->size) {
    return NULL;
  }
  return self->buffer + (self->size - 1) * self->objSize;
}

void vct_Pop(Vector self) {
  if(!self->size) {
    return ;
  }
  self->size--;
}

Vector vct_RemoveElements(Vector payload, Vector indexes) {
  Vector indexesCount = vct_InitWithSize(sizeof(uint8_t), payload->size);
  memset(indexesCount->buffer, 0, sizeof(uint8_t) * payload->size);

  size_t *indexesBuffer = indexes->buffer;
  uint8_t *aparitionCount = indexesCount->buffer;
  
  for(size_t i = 0, c = indexes->size; i < c; i++) {
    if(indexesBuffer[i] < payload->size) {
      aparitionCount[indexesBuffer[i]] = 1;
    }
  }
  Vector payloadWithMissingElements = vct_Init(payload->objSize);
  for(size_t i = 0, c = payload->size; i < c; i++) {
    if(!aparitionCount[i]) {
      vct_Push(payloadWithMissingElements, payload->buffer + i * payload->objSize);
    }
  }
  vct_Delete(indexesCount);
  return payloadWithMissingElements;
}

void vct_RemoveElementsWithReplacing(Vector *self, Vector indexes) {
  Vector deleted = vct_RemoveElements(*self, indexes);
  vct_Delete(*self);
  *self = deleted;
}

int64_t vct_Find(Vector payload, void *element) {
  void *startingPointer = payload->buffer;
  size_t objSize = payload->objSize;
  for(size_t i = 0, c = payload->size; i < c; i++) {
    if(!memcmp(startingPointer + i * objSize, element, objSize)) {
      return i;
    }
  }
  return -1;
}

void vct_Clear(Vector self) {
  self->size = 0;
}