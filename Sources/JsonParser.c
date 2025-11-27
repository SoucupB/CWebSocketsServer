#include "JsonParser.h"
#include "TrieHash.h"
#include <stdlib.h>
#include <assert.h>
#include "Vector.h"
#include <string.h>
#include <stdio.h>

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
  trh_Delete(self->hsh);
  free(self);
}

static inline void json_PushString(Vector str, char *strC, size_t sz) {
  for(size_t i = 0; i < sz; i++) {
    vct_Push(str, &strC[i]);
  }
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

void json_PushLeafValue(Vector str, JsonElement element) {
  switch (element.type)
  {
    case JSON_NULL: {
      json_PushString(str, "null", sizeof("null") - 1);
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
      .buffer = keysBuffer->key,
      .sz = keysBuffer->keySize
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

void json_RemoveSelfContainedData(PJsonObject self) {
  if(!self) {
    return ;
  }
  Vector values = trh_GetValues(self->hsh, sizeof(JsonElement));
  JsonElement *elements = values->buffer;
  for(size_t i = 0, c = values->size; i < c; i++) {
    switch (elements[i].type)
    {
      case JSON_INTEGER: {
        free(elements[i].value); 
        break;
      }
      case JSON_NUMBER: {
        free(elements[i].value); 
        break;
      }
      case JSON_STRING: {
        free(((PHttpString)elements[i].value)->buffer); 
        break;
      }
      case JSON_JSON: {
        json_Delete(elements[i].value);
        break;
      }
      default:
        break;
    }
  }
  vct_Delete(values);
}