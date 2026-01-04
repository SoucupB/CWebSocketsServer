#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

HttpString string_DeepCopy(HttpString str) {
  HttpString response = {
    .buffer = NULL,
    .sz = 0
  };
  if(!str.buffer) {
    return response;
  }
  response.buffer = crm_Alloc(str.sz);
  memcpy(response.buffer, str.buffer, str.sz);
  response.sz = str.sz;
  return response;
}

void string_Print(HttpString str) {
  printf("%.*s\n", (int32_t)str.sz, str.buffer);
}