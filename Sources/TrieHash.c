#include "TrieHash.h"
#include <string.h>
#include "Vector.h"

PTrieNode trn_Create();
uint8_t trn_AddValues(PTrieNode self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize, uint32_t position);

PTrieHash trh_Create() {
  PTrieHash self = crm_Alloc(sizeof(TrieHash));
  memset(self, 0, sizeof(TrieHash));
  self->parentNode = trn_Create();
  return self;
}

void trh_Add(PTrieHash self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize) {
  if(!trn_AddValues(self->parentNode, key, keySize, value, valueSize, 0)) {
    self->count++;
  }
}

PTrieNode trn_Create() {
  PTrieNode self = crm_Alloc(sizeof(TrieNode));
  memset(self, 0, sizeof(TrieNode));
  self->nextNodes = crm_Alloc(sizeof(PTrieNode) * 16);
  memset(self->nextNodes, 0, sizeof(PTrieNode) * 16);
  return self;
}

static inline void trh_FreeNode(PTrieNode self) {
  crm_Free(self->nextNodes);
  crm_Free(self);
}

void trn_DeleteNodes(PTrieNode self) {
  for(uint8_t i = 0; i < 16; i++) {
    if(self->nextNodes[i]) {
      trn_DeleteNodes(self->nextNodes[i]);
      self->nextNodes[i] = NULL;
    }
  }
  if(self->buffer) {
    crm_Free(self->buffer);
  }
  trh_FreeNode(self);
}

uint8_t trn_RemoveNode_t(PTrieNode self, PVOID key, uint32_t keySize, uint32_t position) {
  if(position >= (keySize << 1)) {
    if(self->buffer) {
      crm_Free(self->buffer);
      self->buffer = NULL;
      return 1;
    }
    return 0;
  }
  uint8_t currentValue;
  if(position & 1) {
    currentValue = (((uint8_t *)key)[(position >> 1)] & 15);
  }
  else {
    currentValue = (((uint8_t *)key)[(position >> 1)] >> 4);
  }
  PTrieNode node = self->nextNodes[currentValue];
  uint8_t deleted = 0;
  if(node) {
    deleted = trn_RemoveNode_t(node, key, keySize, position + 1);
    node->count--;
    if(!node->count) {
      self->nextNodes[currentValue] = NULL;
      trh_FreeNode(node);
    }
  }
  return deleted;
}

void trh_Buffer_AddToIndex(PTrieHash self, uint32_t id, PVOID buffer, uint32_t bufferSize) {
  trh_Add(self, &id, sizeof(uint32_t), buffer, bufferSize);
}

void trh_Buffer_AddToIndex64(PTrieHash self, uint64_t id, PVOID buffer, uint32_t bufferSize) {
  trh_Add(self, &id, sizeof(uint64_t), buffer, bufferSize);
}

PVOID trh_Buffer_GetFromIndex(PTrieHash self, uint32_t id) {
  return trh_GetBuffer(self, &id, sizeof(uint32_t));
}

PVOID trh_Buffer_GetFromIndex64(PTrieHash self, uint64_t id) {
  return trh_GetBuffer(self, &id, sizeof(uint64_t));
}

void trh_Buffer_RemoveAtIndex(PTrieHash self, uint32_t id) {
  trh_RemoveNode(self, &id, sizeof(uint32_t));
}

void trh_Buffer_RemoveAtIndex64(PTrieHash self, uint64_t id) {
  trh_RemoveNode(self, &id, sizeof(uint64_t));
}

PVOID trn_GetBuffer_t(PTrieNode self, PVOID key, uint32_t keySize, uint32_t position) {
  if(position >= (keySize << 1)) {
    return self->buffer;
  }
  uint8_t currentValue;
  if(position & 1) {
    currentValue = (((uint8_t *)key)[(position >> 1)] & 15);
  }
  else {
    currentValue = (((uint8_t *)key)[(position >> 1)] >> 4);
  }
  PTrieNode node = self->nextNodes[currentValue];
  if(node) {
    return trn_GetBuffer_t(node, key, keySize, position + 1);
  }
  return NULL;
}

void trh_GetValues_t(PTrieNode self, Vector values) {
  if(!self) {
    return ;
  }
  if(self->buffer) {
    vct_Push(values, self->buffer);
  }
  PTrieNode *nextNodes = self->nextNodes;
  for(size_t i = 0; i < 16; i++) {
    if(nextNodes[i]) {
      trh_GetValues_t(nextNodes[i], values);
    }
  }
}

Vector trh_GetValues(PTrieHash self, size_t valueSize) {
  Vector response = vct_Init(valueSize);
  trh_GetValues_t(self->parentNode, response);
  return response;
}

void trh_Key_Push(Vector currentKey, uint8_t value, size_t position) {
  if(!(position & 1)) {
    value <<= 4;
    vct_Push(currentKey, &value);
    return ;
  }
  uint8_t *last = (uint8_t *)vct_Last(currentKey);
  if(!last) {
    return ;
  }
  (*last) += value;
}

static inline void trh_Key_Pop(Vector currentKey, size_t position) {
  if(!(position & 1)) {
    vct_Pop(currentKey);
  }
  else {
    uint8_t *last = (uint8_t *)vct_Last(currentKey);
    if(!last) {
      return ;
    }
    (*last) &= 0xF0;
  }
}

void trh_GetKeys_t(PTrieNode self, Vector keys, Vector currentKey, size_t position) {
  if(!self) {
    return ;
  }
  if(self->buffer) {
    Key key;
    key.keySize = currentKey->size;
    key.key = crm_Alloc(key.keySize);

    memcpy(key.key, currentKey->buffer, key.keySize);
    vct_Push(keys, &key);
  }
  PTrieNode *nextNodes = self->nextNodes;
  for(uint8_t i = 0; i < 16; i++) {
    if(nextNodes[i]) {
      trh_Key_Push(currentKey, i, position);
      trh_GetKeys_t(nextNodes[i], keys, currentKey, position + 1);
      trh_Key_Pop(currentKey, position);
    }
  }
}

Vector trh_GetKeys(PTrieHash self) {
  Vector response = vct_Init(sizeof(Key));
  Vector currentKey = vct_Init(sizeof(uint8_t));
  trh_GetKeys_t(self->parentNode, response, currentKey, 0);
  vct_Delete(currentKey);
  return response;
}

void trh_FreeKeys(Vector keys) {
  Key *buffer = (Key *)keys->buffer;
  for(size_t i = 0, c = keys->size; i < c; i++) {
    crm_Free(buffer[i].key);
  }
  vct_Delete(keys);
}

PVOID trh_GetBuffer(PTrieHash self, PVOID key, uint32_t keySize) {
  return trn_GetBuffer_t(self->parentNode, key, keySize, 0);
}

void trh_RemoveNode(PTrieHash self, PVOID key, uint32_t keySize) {
  if(trn_RemoveNode_t(self->parentNode, key, keySize, 0)) {
    self->count--;
  }
}

uint8_t trn_AddValues(PTrieNode self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize, uint32_t position) {
  if(position >= (keySize << 1)) {
    PVOID lastBuffer = self->buffer;
    self->buffer = crm_Alloc(valueSize);
    memcpy(self->buffer, value, valueSize);
    if(lastBuffer) {
      crm_Free(lastBuffer);
      return 0;
    }
    return 1;
  }
  uint8_t currentValue;
  if(position & 1) {
    currentValue = (((uint8_t *)key)[(position >> 1)] & 15);
  }
  else {
    currentValue = (((uint8_t *)key)[(position >> 1)] >> 4);
  }
  PTrieNode node = self->nextNodes[currentValue];
  if(!node) {
    node = trn_Create();
    self->nextNodes[currentValue] = node;
  }
  node->count++;
  return trn_AddValues(node, key, keySize, value, valueSize, position + 1);
}

void trh_Integer32_Insert(PTrieHash self, uint32_t key, uint32_t value) {
  trh_Add(self, &key, sizeof(uint32_t), &value, sizeof(uint32_t));
}

PVOID trh_Integer32_Get(PTrieHash self, uint32_t key) {
  return trh_GetBuffer(self, &key, sizeof(uint32_t));
}

void trh_Integer32_RemoveElement(PTrieHash self, uint32_t key) {
  trh_RemoveNode(self, &key, sizeof(uint32_t));
}

void trh_Delete(PTrieHash self) {
  trn_DeleteNodes(self->parentNode);
  crm_Free(self);
}