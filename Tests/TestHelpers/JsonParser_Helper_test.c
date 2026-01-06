#include "JsonParser_Helper_test.h"
#include "JsonParser.h"
#include <stdlib.h>
#include "Array.h"

HttpString json_Helper_Add(char *buffer) {
  HttpString response = {
    .buffer = buffer,
    .sz = strlen(buffer)
  };
  return response;
}

JsonElement json_Helper_Integer(int64_t element) {
  int64_t *bff = crm_Alloc(sizeof(int64_t));
  memcpy(bff, &element, sizeof(int64_t));
  return (JsonElement){
    .value = bff,
    .type = JSON_INTEGER
  };
}

JsonElement json_Helper_Number(float element) {
  float *bff = crm_Alloc(sizeof(float));
  memcpy(bff, &element, sizeof(float));
  return (JsonElement){
    .value = bff,
    .type = JSON_NUMBER
  };
}

PJsonObject json_Helper_Create() {
  PJsonObject js = json_Create();
  js->selfContained = 1;
  return js;
}

JsonElement json_Helper_Json(PJsonObject obj) {
  return (JsonElement){
    .value = obj,
    .type = JSON_JSON
  };
}

JsonElement json_Helper_Array() {
  return (JsonElement){
    .value = arr_Init(sizeof(JsonElement)),
    .type = JSON_ARRAY
  };
}

void json_Helper_Array_Push(JsonElement elemArr, JsonElement elem) {
  arr_Push(elemArr.value, &elem);
}

JsonElement json_Helper_String(char *nmb) {
  const size_t sz = strlen(nmb);
  char *buffer = crm_Alloc(sz * sizeof(char));
  memcpy(buffer, nmb, sz * sizeof(char));
  PHttpString crt = crm_Alloc(sizeof(HttpString));
  crt->buffer = buffer;
  crt->sz = sz;
  return (JsonElement){
    .value = crt,
    .type = JSON_STRING
  };
}