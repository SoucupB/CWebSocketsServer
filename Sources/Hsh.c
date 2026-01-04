#include "Hsh.h"
#include <string.h>
#include "Array.h"
#include "TimeFragment.h"

PTrieNode trn_Create();
uint8_t trn_AddValues(PTrieNode self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize, uint32_t position);

PHsh hsh_Create() {
  PHsh self = crm_Alloc(sizeof(Hsh));
  memset(self, 0, sizeof(Hsh));
  self->parentNode = trn_Create();
  return self;
}

void hsh_Add(PHsh self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize) {
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

static inline void hsh_FreeNode(PTrieNode self) {
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
  hsh_FreeNode(self);
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
      hsh_FreeNode(node);
    }
  }
  return deleted;
}

void hsh_Buffer_AddToIndex(PHsh self, uint32_t id, PVOID buffer, uint32_t bufferSize) {
  hsh_Add(self, &id, sizeof(uint32_t), buffer, bufferSize);
}

void hsh_Buffer_AddToIndex64(PHsh self, uint64_t id, PVOID buffer, uint32_t bufferSize) {
  hsh_Add(self, &id, sizeof(uint64_t), buffer, bufferSize);
}

PVOID hsh_Buffer_GetFromIndex(PHsh self, uint32_t id) {
  return hsh_GetBuffer(self, &id, sizeof(uint32_t));
}

PVOID hsh_Buffer_GetFromIndex64(PHsh self, uint64_t id) {
  return hsh_GetBuffer(self, &id, sizeof(uint64_t));
}

void hsh_Buffer_RemoveAtIndex(PHsh self, uint32_t id) {
  hsh_RemoveNode(self, &id, sizeof(uint32_t));
}

void hsh_Buffer_RemoveAtIndex64(PHsh self, uint64_t id) {
  hsh_RemoveNode(self, &id, sizeof(uint64_t));
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

void hsh_GetValues_t(PTrieNode self, Array values) {
  if(!self) {
    return ;
  }
  if(self->buffer) {
    arr_Push(values, self->buffer);
  }
  PTrieNode *nextNodes = self->nextNodes;
  for(size_t i = 0; i < 16; i++) {
    if(nextNodes[i]) {
      hsh_GetValues_t(nextNodes[i], values);
    }
  }
}

Array hsh_GetValues(PHsh self, size_t valueSize) {
  Array response = arr_Init(valueSize);
  hsh_GetValues_t(self->parentNode, response);
  return response;
}

void hsh_Key_Push(Array currentKey, uint8_t value, size_t position) {
  if(!(position & 1)) {
    value <<= 4;
    arr_Push(currentKey, &value);
    return ;
  }
  uint8_t *last = (uint8_t *)arr_Last(currentKey);
  if(!last) {
    return ;
  }
  (*last) += value;
}

static inline void hsh_Key_Pop(Array currentKey, size_t position) {
  if(!(position & 1)) {
    arr_Pop(currentKey);
  }
  else {
    uint8_t *last = (uint8_t *)arr_Last(currentKey);
    if(!last) {
      return ;
    }
    (*last) &= 0xF0;
  }
}

void hsh_GetKeys_t(PTrieNode self, Array keys, Array currentKey, size_t position) {
  if(!self) {
    return ;
  }
  if(self->buffer) {
    Key key;
    key.keySize = currentKey->size;
    key.key = crm_Alloc(key.keySize);

    memcpy(key.key, currentKey->buffer, key.keySize);
    arr_Push(keys, &key);
  }
  PTrieNode *nextNodes = self->nextNodes;
  for(uint8_t i = 0; i < 16; i++) {
    if(nextNodes[i]) {
      hsh_Key_Push(currentKey, i, position);
      hsh_GetKeys_t(nextNodes[i], keys, currentKey, position + 1);
      hsh_Key_Pop(currentKey, position);
    }
  }
}

Array hsh_GetKeys(PHsh self) {
  Array response = arr_Init(sizeof(Key));
  Array currentKey = arr_Init(sizeof(uint8_t));
  hsh_GetKeys_t(self->parentNode, response, currentKey, 0);
  arr_Delete(currentKey);
  return response;
}

void hsh_FreeKeys(Array keys) {
  Key *buffer = (Key *)keys->buffer;
  for(size_t i = 0, c = keys->size; i < c; i++) {
    crm_Free(buffer[i].key);
  }
  arr_Delete(keys);
}

PVOID hsh_GetBuffer(PHsh self, PVOID key, uint32_t keySize) {
  return trn_GetBuffer_t(self->parentNode, key, keySize, 0);
}

void hsh_RemoveNode(PHsh self, PVOID key, uint32_t keySize) {
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

void hsh_Integer32_Insert(PHsh self, uint32_t key, uint32_t value) {
  hsh_Add(self, &key, sizeof(uint32_t), &value, sizeof(uint32_t));
}

PVOID hsh_Integer32_Get(PHsh self, uint32_t key) {
  return hsh_GetBuffer(self, &key, sizeof(uint32_t));
}

void hsh_Integer32_RemoveElement(PHsh self, uint32_t key) {
  hsh_RemoveNode(self, &key, sizeof(uint32_t));
}

void hsh_Delete(PHsh self) {
  trn_DeleteNodes(self->parentNode);
  crm_Free(self);
}