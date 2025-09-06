#pragma once
#include <stddef.h>
#include <stdint.h>
#include "Vector.h"
#include "Structs.h"

PTrieHash trh_Create();
void trh_Add(PTrieHash self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize);
void trh_Delete(PTrieHash self);
void trh_RemoveNode(PTrieHash self, PVOID key, uint32_t keySize);
PVOID trh_GetBuffer(PTrieHash self, PVOID key, uint32_t keySize);

void trh_Integer32_Insert(PTrieHash self, uint32_t key, uint32_t value);
PVOID trh_Integer32_Get(PTrieHash self, uint32_t key);
void trh_Integer32_RemoveElement(PTrieHash self, uint32_t key);

void trh_Buffer_AddToIndex64(PTrieHash self, uint64_t id, PVOID buffer, uint32_t bufferSize);
PVOID trh_Buffer_GetFromIndex64(PTrieHash self, uint64_t id);
void trh_Buffer_RemoveAtIndex64(PTrieHash self, uint64_t id);

void trh_Buffer_AddToIndex(PTrieHash self, uint32_t id, PVOID buffer, uint32_t bufferSize);
PVOID trh_Buffer_GetFromIndex(PTrieHash self, uint32_t id);
void trh_Buffer_RemoveAtIndex(PTrieHash self, uint32_t id);

Vector trh_GetValues(PTrieHash self, size_t valueSize);
Vector trh_GetKeys(PTrieHash self);
void trh_FreeKeys(Vector keys);