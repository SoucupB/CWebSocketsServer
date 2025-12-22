#pragma once
#include <stddef.h>
#include <stdint.h>
#include "Structs.h"

PHsh trh_Create();
void trh_Add(PHsh self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize);
void trh_Delete(PHsh self);
void trh_RemoveNode(PHsh self, PVOID key, uint32_t keySize);
PVOID trh_GetBuffer(PHsh self, PVOID key, uint32_t keySize);

void trh_Integer32_Insert(PHsh self, uint32_t key, uint32_t value);
PVOID trh_Integer32_Get(PHsh self, uint32_t key);
void trh_Integer32_RemoveElement(PHsh self, uint32_t key);

void trh_Buffer_AddToIndex64(PHsh self, uint64_t id, PVOID buffer, uint32_t bufferSize);
PVOID trh_Buffer_GetFromIndex64(PHsh self, uint64_t id);
void trh_Buffer_RemoveAtIndex64(PHsh self, uint64_t id);

void trh_Buffer_AddToIndex(PHsh self, uint32_t id, PVOID buffer, uint32_t bufferSize);
PVOID trh_Buffer_GetFromIndex(PHsh self, uint32_t id);
void trh_Buffer_RemoveAtIndex(PHsh self, uint32_t id);

Array trh_GetValues(PHsh self, size_t valueSize);
Array trh_GetKeys(PHsh self);
void trh_FreeKeys(Array keys);