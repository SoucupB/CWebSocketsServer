#include "JsonParser_Helper_test.h"
#include <stdlib.h>

HttpString json_Helper_Add(char *buffer) {
  HttpString response = {
    .buffer = buffer,
    .sz = strlen(buffer)
  };
  return response;
}

JsonElement json_Helper_Integer(int64_t element) {
  int64_t *bff = malloc(sizeof(int64_t));
  memcpy(bff, &element, sizeof(int64_t));
  return (JsonElement){
    .value = bff,
    .type = JSON_INTEGER
  };
}