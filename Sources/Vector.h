#pragma once
#include <stdlib.h>
#include <stdint.h>
#include "Structs.h"

Vector vct_Init(size_t size);
Vector vct_InitWithCapacity(size_t size, size_t count);
void vct_Push(Vector self, void *buffer);
void vct_Delete(Vector self);
void vct_DeleteWOBuffer(Vector self);
void vct_Clear(Vector self);
void vct_RemoveElement(Vector payload, size_t index);
Vector vct_RemoveElements(Vector payload, Vector indexes);
int64_t vct_Find(Vector payload, void *element);
Vector vct_InitWithSize(size_t objSize, size_t count);
char *vct_Last(Vector self);
void vct_Pop(Vector self);