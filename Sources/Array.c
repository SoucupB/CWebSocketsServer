#include "Array.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

#define crm_Alloc malloc
#define crm_Free free
#define crm_Realloc realloc

Array arr_Init(size_t size) {
  Array self = (Array)crm_Alloc(sizeof(struct Array_t));
  self->buffer = crm_Alloc(size);
  self->size = 0;
  self->capacity = 1;
  self->objSize = size;
  return self;
}

Array arr_InitWithCapacity(size_t size, size_t count) {
  Array self = crm_Alloc(sizeof(struct Array_t));
  self->buffer = crm_Alloc(size * count);
  self->size = 0;
  self->capacity = count;
  self->objSize = size;
  return self;
}

Array arr_InitWithSize(size_t objSize, size_t count) {
  Array self = crm_Alloc(sizeof(struct Array_t));
  self->buffer = crm_Alloc(objSize * count);
  self->size = count;
  self->capacity = count;
  self->objSize = objSize;
  return self;
}

void copyData(Array self, void *buffer) {
  memcpy(self->buffer + (self->size * self->objSize), buffer, self->objSize);
  self->size++;
}

void arr_Push(Array self, void *buffer) {
  if(self->size >= self->capacity) {
    self->capacity <<= 1;
    self->buffer = crm_Realloc(self->buffer, self->capacity * self->objSize);
  }
  copyData(self, buffer);
}

void arr_RemoveElement(Array self, size_t index) {
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

void arr_Delete(Array self) {
  crm_Free(self->buffer);
  crm_Free(self);
}

void arr_DeleteWOBuffer(Array self) {
  crm_Free(self);
}

char *arr_Last(Array self) {
  if(!self->size) {
    return NULL;
  }
  return self->buffer + (self->size - 1) * self->objSize;
}

void arr_Pop(Array self) {
  if(!self->size) {
    return ;
  }
  self->size--;
}

Array arr_RemoveElements(Array payload, Array indexes) {
  Array indexesCount = arr_InitWithSize(sizeof(uint8_t), payload->size);
  memset(indexesCount->buffer, 0, sizeof(uint8_t) * payload->size);

  size_t *indexesBuffer = indexes->buffer;
  uint8_t *aparitionCount = indexesCount->buffer;
  
  for(size_t i = 0, c = indexes->size; i < c; i++) {
    if(indexesBuffer[i] < payload->size) {
      aparitionCount[indexesBuffer[i]] = 1;
    }
  }
  Array payloadWithMissingElements = arr_Init(payload->objSize);
  for(size_t i = 0, c = payload->size; i < c; i++) {
    if(!aparitionCount[i]) {
      arr_Push(payloadWithMissingElements, payload->buffer + i * payload->objSize);
    }
  }
  arr_Delete(indexesCount);
  return payloadWithMissingElements;
}

void arr_RemoveElementsWithReplacing(Array *self, Array indexes) {
  Array deleted = arr_RemoveElements(*self, indexes);
  arr_Delete(*self);
  *self = deleted;
}

int64_t arr_Find(Array payload, void *element) {
  void *startingPointer = payload->buffer;
  size_t objSize = payload->objSize;
  for(size_t i = 0, c = payload->size; i < c; i++) {
    if(!memcmp(startingPointer + i * objSize, element, objSize)) {
      return i;
    }
  }
  return -1;
}

void arr_Clear(Array self) {
  self->size = 0;
}