#include "JsonParser.h"
#include "TrieHash.h"
#include <stdlib.h>
#include <assert.h>
#include "Vector.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>

void json_ToString_t(PJsonObject self, Vector str);
void json_DeleteArray(JsonElement element);
void json_PushLeafValue(Vector str, JsonElement element);

typedef struct TokenParser_t {
  char *startToken;
  char *endToken;
  char *endingBuffer;
} TokenParser;

typedef TokenParser *PTokenParser;

TokenParser json_Parser_Map(TokenParser tck);
JsonElement json_Parser_Get_Array(TokenParser tck, PTokenParser next);
JsonElement json_Parser_Get_Map(TokenParser tck, PTokenParser next);

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
  return (size_t)(tck->endingBuffer - tck->endToken);
}

static inline uint8_t json_Parser_IsInvalid(TokenParser tck) {
  return !tck.endingBuffer || !tck.endToken || !tck.startToken;
}

static inline uint8_t json_Parser_Get_IsInvalid(JsonElement tck) {
  return tck.type == JSON_INVALID;
}

static inline TokenParser json_Parse_Invalid() {
  return (TokenParser) {
    .startToken = NULL,
    .endToken = NULL,
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

static inline JsonElement json_Element_Invalid() {
  return (JsonElement) {
    .type = JSON_INVALID
  };
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

HttpString json_Element_ToString(JsonElement self) {
  Vector responseString = vct_Init(sizeof(char));
  json_PushLeafValue(responseString, self);
  HttpString response = {
    .buffer = responseString->buffer,
    .sz = responseString->size
  };
  vct_DeleteWOBuffer(responseString);
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
  while(startingIndex < sz && tck->endToken[startingIndex] == ' ') {
    startingIndex++;
  }
  tck->endToken += startingIndex;
}

TokenParser json_Parser_Token(TokenParser tck, char *token, size_t tokenSize) {
  size_t sz = json_Parser_CurrentSize(&tck);
  if(sz < tokenSize || memcmp(tck.endToken, token, (sz < tokenSize ? sz : tokenSize) * sizeof(char))) {
    return json_Parse_Invalid();
  }
  return (TokenParser) {
    .startToken = tck.endToken,
    .endToken = tck.endToken + tokenSize,
    .endingBuffer = tck.endingBuffer
  };
}

static inline TokenParser json_Parser_Token_IgnoreErrors(TokenParser tck, char *token, size_t tokenSize) {
  TokenParser resp = json_Parser_Token(tck, token, tokenSize);
  if(json_Parser_IsInvalid(resp)) {
    return tck;
  }
  return resp;
}

uint8_t json_Parser_IsCharValid(char val) {
  return val != '"'; 
}

TokenParser json_Parser_String(TokenParser tck) {
  json_Parser_RemoveEmptySpace(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, "\"", sizeof("\"") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  while(tck.endToken < tck.endingBuffer) {
    TokenParser specialCharOffset = json_Parser_Token(tck, "\\\"", sizeof("\\\"") - 1);
    if(!json_Parser_IsInvalid(specialCharOffset)) {
      tck.endToken = specialCharOffset.endToken;
      continue;
    }
    if(!json_Parser_IsCharValid(*tck.endToken)) {
      break;
    }
    tck.endToken++;
  }
  if(tck.endToken >= tck.endingBuffer) {
    return json_Parse_Invalid();
  }
  tck = json_Parser_Token(tck, "\"", sizeof("\"") - 1);
  tck.startToken = cpyTck.startToken;
  return tck;
}

TokenParser json_Parser_Integer(TokenParser tck) {
  json_Parser_RemoveEmptySpace(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token_IgnoreErrors(tck, "-", sizeof("-") - 1);
  uint8_t checker = 0;
  while(tck.endToken < tck.endingBuffer && isdigit(*tck.endToken)) {
    checker = 1;
    tck.endToken++;
  }
  if(!checker) {
    return json_Parse_Invalid();
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}

TokenParser json_Parser_Number(TokenParser tck) {
  json_Parser_RemoveEmptySpace(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token_IgnoreErrors(tck, "-", sizeof("-") - 1);
  uint8_t checker = 0;
  while(tck.endToken < tck.endingBuffer && isdigit(*tck.endToken)) {
    checker = 1;
    tck.endToken++;
  }
  if(!checker) {
    return json_Parse_Invalid();
  }
  tck = json_Parser_Token(tck, ".", sizeof(".") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  checker = 0;
  while(tck.endToken < tck.endingBuffer && isdigit(*tck.endToken)) {
    checker = 1;
    tck.endToken++;
  }
  if(!checker) {
    return json_Parse_Invalid();
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}

TokenParser json_Parser_Comma(TokenParser tck) {
  json_Parser_RemoveEmptySpace(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, ",", sizeof(",") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}

TokenParser json_Parser_Splitter(TokenParser tck) {
  json_Parser_RemoveEmptySpace(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, ":", sizeof(":") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}

TokenParser json_Parser_Array(TokenParser tck) {
  json_Parser_RemoveEmptySpace(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, "[", sizeof("[") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  void *methods[] = {
    (void *)json_Parser_String,
    (void *)json_Parser_Number,
    (void *)json_Parser_Integer,
    (void *)json_Parser_Map,
    (void *)json_Parser_Array
  };
  TokenParser ncpy = tck;
  while(ncpy.endToken < ncpy.endingBuffer) {
    uint8_t validToken = 0;
    for(size_t i = 0; i < sizeof(methods) / sizeof(void *); i++) {
      TokenParser (*tokenMethod)(TokenParser) = (TokenParser (*)(TokenParser)) (((size_t *)methods)[i]);
      TokenParser next = tokenMethod(ncpy);
      if(json_Parser_IsInvalid(next)) {
        continue;
      }
      ncpy = next;
      validToken = 1;
      break;
    }
    if(!validToken) {
      return json_Parse_Invalid();
    }
    TokenParser comma = json_Parser_Comma(ncpy);
    if(json_Parser_IsInvalid(comma)) {
      break;
    }
    ncpy = comma;
  }
  tck.endToken = ncpy.endToken;
  json_Parser_RemoveEmptySpace(&tck);
  tck = json_Parser_Token(tck, "]", sizeof("]") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}

TokenParser json_Parser_Map(TokenParser tck) {
  json_Parser_RemoveEmptySpace(&tck);
  TokenParser cpyTck = tck;
  cpyTck.startToken = tck.endToken;
  tck = json_Parser_Token(tck, "{", sizeof("{") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  void *methods[] = {
    (void *)json_Parser_String,
    (void *)json_Parser_Number,
    (void *)json_Parser_Integer,
    (void *)json_Parser_Map,
    (void *)json_Parser_Array
  };
  TokenParser ncpy = tck;
  while(ncpy.endToken < ncpy.endingBuffer) {
    uint8_t validToken = 0;
    ncpy = json_Parser_String(ncpy);
    if(json_Parser_IsInvalid(ncpy)) {
      return json_Parse_Invalid();
    }
    ncpy = json_Parser_Splitter(ncpy);
    if(json_Parser_IsInvalid(ncpy)) {
      return json_Parse_Invalid();
    }
    for(size_t i = 0; i < sizeof(methods) / sizeof(void *); i++) {
      TokenParser (*tokenMethod)(TokenParser) = (TokenParser (*)(TokenParser)) (((size_t *)methods)[i]);
      TokenParser next = tokenMethod(ncpy);
      if(json_Parser_IsInvalid(next)) {
        continue;
      }
      ncpy = next;
      validToken = 1;
      break;
    }
    if(!validToken) {
      return json_Parse_Invalid();
    }
    TokenParser comma = json_Parser_Comma(ncpy);
    if(json_Parser_IsInvalid(comma)) {
      break;
    }
    ncpy = comma;
  }
  tck.endToken = ncpy.endToken;
  json_Parser_RemoveEmptySpace(&tck);
  tck = json_Parser_Token(tck, "}", sizeof("}") - 1);
  if(json_Parser_IsInvalid(tck)) {
    return tck;
  }
  tck.startToken = cpyTck.startToken;
  return tck;
}

JsonElement json_Parser_Get_String(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_String(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  const size_t stringSize = (size_t)(nextTck.endToken - nextTck.startToken) - 2;
  PHttpString responseString = malloc(sizeof(HttpString));
  responseString->sz = stringSize;
  responseString->buffer = malloc(stringSize + 1);
  memcpy(responseString->buffer, nextTck.startToken + 1, stringSize);
  if(next) {
    *next = nextTck;
  }
  return (JsonElement) {
    .type = JSON_STRING,
    .value = responseString
  };
}

JsonElement json_Parser_Get_Integer(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Integer(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  JsonElement response = {
    .type = JSON_INTEGER
  };
  char *endingPointer;
  errno = 0;
  int64_t nrm = strtoll(nextTck.startToken, &endingPointer, 10);
  if(errno == ERANGE || endingPointer == nextTck.startToken) {
    return json_Element_Invalid();
  }
  response.value = malloc(sizeof(int64_t));
  memcpy(response.value, &nrm, sizeof(int64_t));
  if(next) {
    *next = nextTck;
  }
  return response;
}

JsonElement json_Parser_Get_Number(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Number(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  JsonElement response = {
    .type = JSON_NUMBER
  };
  char *endingPointer;
  errno = 0;
  float nrm = strtof(nextTck.startToken, &endingPointer);
  if(errno == ERANGE || endingPointer == nextTck.startToken) {
    return json_Element_Invalid();
  }
  response.value = malloc(sizeof(float));
  memcpy(response.value, &nrm, sizeof(float));
  if(next) {
    *next = nextTck;
  }
  return response;
}

static inline TokenParser json_Parser_Open_SquareBracket(TokenParser token) {
  json_Parser_RemoveEmptySpace(&token);
  token = json_Parser_Token_IgnoreErrors(token, "[", sizeof("[") - 1);
  return token;
}

static inline TokenParser json_Parser_Close_SquareBracket(TokenParser token) {
  json_Parser_RemoveEmptySpace(&token);
  token = json_Parser_Token_IgnoreErrors(token, "]", sizeof("]") - 1);
  return token;
}

static inline TokenParser json_Parser_Open_CurlyBracket(TokenParser token) {
  json_Parser_RemoveEmptySpace(&token);
  token = json_Parser_Token_IgnoreErrors(token, "{", sizeof("{") - 1);
  return token;
}

static inline TokenParser json_Parser_Close_CurlyBracket(TokenParser token) {
  json_Parser_RemoveEmptySpace(&token);
  token = json_Parser_Token_IgnoreErrors(token, "}", sizeof("}") - 1);
  return token;
}

JsonElement json_Parser_Get_Array(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Array(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  Vector rspArray = vct_Init(sizeof(JsonElement));
  JsonElement response = {
    .type = JSON_ARRAY,
    .value = rspArray
  };
  void *methods[] = {
    json_Parser_Get_String,
    json_Parser_Get_Number,
    json_Parser_Get_Integer,
    json_Parser_Get_Map,
    json_Parser_Get_Array
  };
  tck = json_Parser_Open_SquareBracket(tck);
  TokenParser cpyTck = tck;
  while(1) {
    for(size_t i = 0; i < sizeof(methods) / sizeof(void *); i++) {
      JsonElement (*tokenMethod)(TokenParser, PTokenParser) = (JsonElement (*)(TokenParser, PTokenParser)) (((size_t *)methods)[i]);
      JsonElement currentElement = tokenMethod(cpyTck, &cpyTck);
      if(json_Parser_Get_IsInvalid(currentElement)) {
        continue;
      }
      vct_Push(rspArray, &currentElement);
      break;
    }
    TokenParser comma = json_Parser_Comma(cpyTck);
    if(json_Parser_IsInvalid(comma)) {
      break;
    }
    cpyTck = comma;
  }
  cpyTck = json_Parser_Close_SquareBracket(cpyTck);
  if(next) {
    next->startToken = nextTck.startToken;
    next->endToken = cpyTck.endToken;
    next->endingBuffer = tck.endingBuffer;
  }
  return response;
}

void json_Parser_Print(JsonElement self) {
  HttpString strResponse = json_Element_ToString(self);
  printf("%.*s\n", (uint32_t)strResponse.sz, strResponse.buffer);
  free(strResponse.buffer);
}

JsonElement json_Parser_Get_Map(TokenParser tck, PTokenParser next) {
  TokenParser nextTck = json_Parser_Map(tck);
  if(json_Parser_IsInvalid(nextTck)) {
    return json_Element_Invalid();
  }
  PJsonObject jsn = json_Create();
  jsn->selfContained = 1;
  JsonElement response = {
    .type = JSON_JSON,
    .value = jsn
  };
  void *methods[] = {
    json_Parser_Get_String,
    json_Parser_Get_Number,
    json_Parser_Get_Integer,
    json_Parser_Get_Map,
    json_Parser_Get_Array
  };
  tck = json_Parser_Open_CurlyBracket(tck);
  TokenParser cpyTck = tck;
  while(1) {
    JsonElement key = json_Parser_Get_String(cpyTck, &cpyTck);
    cpyTck = json_Parser_Token_IgnoreErrors(cpyTck, ":", sizeof(":") - 1);
    for(size_t i = 0; i < sizeof(methods) / sizeof(void *); i++) {
      JsonElement (*tokenMethod)(TokenParser, PTokenParser) = (JsonElement (*)(TokenParser, PTokenParser)) (((size_t *)methods)[i]);
      JsonElement currentElement = tokenMethod(cpyTck, &cpyTck);
      if(json_Parser_Get_IsInvalid(currentElement)) {
        continue;
      }
      json_Add((PJsonObject)response.value, key.value, currentElement);
      break;
    }
    json_DeleteElement(key);
    TokenParser comma = json_Parser_Comma(cpyTck);
    if(json_Parser_IsInvalid(comma)) {
      break;
    }
    cpyTck = comma;
  }
  cpyTck = json_Parser_Close_CurlyBracket(cpyTck);
  if(next) {
    next->startToken = nextTck.startToken;
    next->endToken = cpyTck.endToken;
    next->endingBuffer = tck.endingBuffer;
  }
  return response;
}

JsonElement json_Parse(PHttpString buffer, char *nextBuffer) {
  return (JsonElement) {
    .type = JSON_INVALID
  };
}