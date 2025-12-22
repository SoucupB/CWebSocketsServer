#pragma once
#include <stdlib.h>
#include <stdint.h>
#include "Structs.h"

Array vct_Init(size_t size);
Array vct_InitWithCapacity(size_t size, size_t count);
void vct_Push(Array self, void *buffer);
void vct_Delete(Array self);
void vct_DeleteWOBuffer(Array self);
void vct_Clear(Array self);
void vct_RemoveElement(Array payload, size_t index);
Array vct_RemoveElements(Array payload, Array indexes);
int64_t vct_Find(Array payload, void *element);
Array vct_InitWithSize(size_t objSize, size_t count);
char *vct_Last(Array self);
void vct_Pop(Array self);
void vct_RemoveElementsWithReplacing(Array *self, Array indexes);