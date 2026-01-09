#pragma once
#include <stdlib.h>
#include <stdint.h>
#include "Structs.h"

Array arr_Init(size_t size);
Array arr_InitWithCapacity(size_t size, size_t count);
void arr_Push(Array self, void *buffer);
void arr_Delete(Array self);
void arr_DeleteWOBuffer(Array self);
void arr_Clear(Array self);
void arr_RemoveElement(Array payload, size_t index);
Array arr_RemoveElements(Array payload, Array indexes);
int64_t arr_Find(Array payload, void *element);
Array arr_InitWithSize(size_t objSize, size_t count);
char *arr_Last(Array self);
void arr_Pop(Array self);
void arr_RemoveElementsWithReplacing(Array *self, Array indexes);