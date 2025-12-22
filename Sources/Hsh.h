#pragma once
#include <stddef.h>
#include <stdint.h>
#include "Structs.h"

PHsh hsh_Create();
void hsh_Add(PHsh self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize);
void hsh_Delete(PHsh self);
void hsh_RemoveNode(PHsh self, PVOID key, uint32_t keySize);
PVOID hsh_GetBuffer(PHsh self, PVOID key, uint32_t keySize);

void hsh_Integer32_Insert(PHsh self, uint32_t key, uint32_t value);
PVOID hsh_Integer32_Get(PHsh self, uint32_t key);
void hsh_Integer32_RemoveElement(PHsh self, uint32_t key);

void hsh_Buffer_AddToIndex64(PHsh self, uint64_t id, PVOID buffer, uint32_t bufferSize);
PVOID hsh_Buffer_GetFromIndex64(PHsh self, uint64_t id);
void hsh_Buffer_RemoveAtIndex64(PHsh self, uint64_t id);

void hsh_Buffer_AddToIndex(PHsh self, uint32_t id, PVOID buffer, uint32_t bufferSize);
PVOID hsh_Buffer_GetFromIndex(PHsh self, uint32_t id);
void hsh_Buffer_RemoveAtIndex(PHsh self, uint32_t id);

Array hsh_GetValues(PHsh self, size_t valueSize);
Array hsh_GetKeys(PHsh self);
void hsh_FreeKeys(Array keys);