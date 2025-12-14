#include "String.h"
#include <string.h>
#include <stdlib.h>

HttpString string_DeepCopy(HttpString str) {
  HttpString response = {
    .buffer = NULL,
    .sz = 0
  };
  if(!str.buffer) {
    return response;
  }
  response.buffer = malloc(str.sz);
  memcpy(response.buffer, str.buffer, str.sz);
  response.sz = str.sz;
  return response;
}