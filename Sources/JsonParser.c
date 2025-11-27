#include "JsonParser.h"
#include "TrieHash.h"
#include <stdlib.h>
#include <assert.h>
#include "Vector.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void json_ToString_t(PJsonObject self, Vector str);
void json_DeleteArray(JsonElement element);
void json_PushLeafValue(Vector str, JsonElement element);

typedef struct TokenParser_t {
  char *startingBuffer;
  char *endingBuffer;
} TokenParser;

typedef TokenParser *PTokenParser;

PJsonObject json_Create() {
  PJsonObject self = malloc(sizeof(JsonObject));
  self->hsh = trh_Create();
  self->selfContained = 0;
  return self;
}

void json_Add(PJsonObject self, PHttpString key, JsonElement element) {
  assert(self->hsh);
  trh_Add(self->hsh, key->buffer, key->sz, &element, sizeof(JsonElement));
}

void json_Delete(PJsonObject self) {
  json_RemoveSelfContainedData(self);
  trh_Delete(self->hsh);
  free(self);
}

static inline void json_PushString(Vector str, char *strC, size_t sz) {
  for(size_t i = 0; i < sz; i++) {
    vct_Push(str, &strC[i]);
  }
}

static inline size_t json_Parser_CurrentSize(PTokenParser tck) {
  return (size_t)(tck->endingBuffer - tck->startingBuffer);
}

static inline uint8_t json_Parser_IsInvalid(TokenParser tck) {
  return !tck.endingBuffer || !tck.startingBuffer;
}

static inline TokenParser json_Parse_Invalid() {
  return (TokenParser) {
    .startingBuffer = NULL,
    .endingBuffer = NULL
  };
}

static inline void json_Element_PushInteger(Vector str, int64_t number) {
  char arr[21] = {0};
  snprintf(arr, sizeof(arr) - 1, "%ld", number);
  json_PushString(str, arr, strlen(arr));
}

static inline void json_Element_PushFloat(Vector str, float number) {
  char arr[21] = {0};
  snprintf(arr, sizeof(arr) - 1, "%f", number);
  json_PushString(str, arr, strlen(arr));
}

static inline void json_Element_PushString(Vector str, PHttpString value) {
  vct_Push(str, &(char){'"'});
  char *bff = value->buffer;
  for(size_t i = 0, c = value->sz; i < c; i++) {
    vct_Push(str, &bff[i]);
  }
  vct_Push(str, &(char){'"'});
}

void json_PushLeafArray(Vector str, JsonElement element) {
  vct_Push(str, &(char){'['});
  Vector currentVector = element.value;
  JsonElement *arrList = currentVector->buffer;
  for(size_t i = 0, c = currentVector->size; i < c; i++) {
    json_PushLeafValue(str, arrList[i]);
    if(i != c - 1) {
      vct_Push(str, &(char){','});
    }
  }
  vct_Push(str, &(char){']'});
}

void json_PushLeafValue(Vector str, JsonElement element) {
  switch (element.type)
  {
    case JSON_NULL: {
      json_PushString(str, "null", sizeof("null") - 1);
      break;
    }
    case JSON_JSON: {
      json_ToString_t(element.value, str);
      break;
    }
    case JSON_INTEGER: {
      assert(element.value);
      json_Element_PushInteger(str, *(int64_t *)element.value);
      break;
    }
    case JSON_NUMBER: {
      assert(element.value);
      json_Element_PushFloat(str, *(float *)element.value);
      break;
    }
    case JSON_STRING: {
      assert(element.value);
      json_Element_PushString(str, element.value);
      break;
    }
    case JSON_ARRAY: {
      json_PushLeafArray(str, element);
      break;
    }
    default:
      break;
  }
}

void json_PushLeafElement(Vector str, PHttpString key, JsonElement element, int8_t lastElement) {
  vct_Push(str, &(char){'"'});
  char *bff = key->buffer;
  for(size_t i = 0, c = key->sz; i < c; i++) {
    vct_Push(str, &bff[i]);
  }
  vct_Push(str, &(char){'"'});
  vct_Push(str, &(char){':'});
  json_PushLeafValue(str, element);
  if(!lastElement) {
    vct_Push(str, &(char){','});
  }
}

void json_ToString_t(PJsonObject self, Vector str) {
  vct_Push(str, &(char){'{'});
  Vector keys = trh_GetKeys(self->hsh);
  Key *keysBuffer = keys->buffer;
  for(size_t i = 0, c = keys->size; i < c; i++) {
    HttpString currentKey = {
      .buffer = keysBuffer[i].key,
      .sz = keysBuffer[i].keySize
    };
    JsonElement *currentElement = trh_GetBuffer(self->hsh, currentKey.buffer, currentKey.sz);
    json_PushLeafElement(str, &currentKey, *currentElement, i == keys->size - 1);
    free(currentKey.buffer);
  }
  vct_Push(str, &(char){'}'});
  vct_Delete(keys);
}

HttpString json_ToString(PJsonObject self) {
  Vector rsp = vct_Init(sizeof(char));
  json_ToString_t(self, rsp);
  HttpString response = {
    .buffer = rsp->buffer,
    .sz = rsp->size
  };
  vct_DeleteWOBuffer(rsp);
  return response;
}

void json_DeleteElement(JsonElement element) {
  switch (element.type)
  {
    case JSON_INTEGER: {
      free(element.value); 
      break;
    }
    case JSON_NUMBER: {
      free(element.value); 
      break;
    }
    case JSON_STRING: {
      free(((PHttpString)element.value)->buffer);
      free(element.value);
      break;
    }
    case JSON_JSON: {
      json_Delete(element.value);
      break;
    }
    case JSON_ARRAY: {
      json_DeleteArray(element);
      break;
    }
    default:
      break;
  }
}

void json_DeleteArray(JsonElement element) {
  Vector listArr = element.value;
  JsonElement *arr = listArr->buffer;
  for(size_t i = 0, c = listArr->size; i < c; i++) {
    json_DeleteElement(arr[i]);
  }
  vct_Delete(listArr);
}

void json_RemoveSelfContainedData(PJsonObject self) {
  if(!self || !self->selfContained) {
    return ;
  }
  Vector values = trh_GetValues(self->hsh, sizeof(JsonElement));
  JsonElement *elements = values->buffer;
  for(size_t i = 0, c = values->size; i < c; i++) {
    json_DeleteElement(elements[i]);
  }
  vct_Delete(values);
}

void json_Parser_RemoveEmptySpace(PTokenParser tck) {
  size_t sz = json_Parser_CurrentSize(tck);
  size_t startingIndex = 0;
  while(startingIndex < sz && tck->startingBuffer[startingIndex] == ' ') {
    startingIndex++;
  }
  tck->startingBuffer += startingIndex;
}

TokenParser json_Parser_Token(TokenParser tck, char *token, size_t tokenSize) {
  size_t sz = json_Parser_CurrentSize(&tck);
  if(sz < tokenSize || memcmp(tck.startingBuffer, token, (sz < tokenSize ? sz : tokenSize) * sizeof(char))) {
    return json_Parse_Invalid();
  }
  return (TokenParser) {
    .startingBuffer = tck.startingBuffer + tokenSize,
    .endingBuffer = tck.endingBuffer
  };
}

uint8_t json_Parser_IsCharValid(char val) {
  return val != '"'; 
}

TokenParser json_Parser_String(TokenParser tck) {
  json_Parser_RemoveEmptySpace(&tck);
  tck = json_Parser_Token(tck, "\"", sizeof("\"") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  while(tck.startingBuffer < tck.endingBuffer) {
    TokenParser specialCharOffset = json_Parser_Token(tck, "\\\"", sizeof("\\\"") - 1);
    if(!json_Parser_IsInvalid(specialCharOffset)) {
      tck.startingBuffer = specialCharOffset.startingBuffer;
      continue;
    }
    if(!json_Parser_IsCharValid(*tck.startingBuffer)) {
      break;
    }
    tck.startingBuffer++;
  }
  if(tck.startingBuffer >= tck.endingBuffer || *tck.startingBuffer != '"') {
    return json_Parse_Invalid();
  }
  return tck;
}

TokenParser json_Parser_Integer(TokenParser tck) {
  json_Parser_RemoveEmptySpace(&tck);
  uint8_t checker = 0;
  while(tck.startingBuffer < tck.endingBuffer && isdigit(*tck.startingBuffer)) {
    checker = 0;
    tck.startingBuffer++;
  }
  if(!checker) {
    return json_Parse_Invalid();
  }
  return tck;
}

JsonElement json_Parse(PHttpString buffer, char *nextBuffer) {
  return (JsonElement) {
    .type = JSON_INVALID
  };
}