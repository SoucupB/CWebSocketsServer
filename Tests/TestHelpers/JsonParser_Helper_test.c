#include "JsonParser_Helper_test.h"

HttpString json_Helper_Add(char *buffer) {
  HttpString response = {
    .buffer = buffer,
    .sz = strlen(buffer)
  };
  return response;
}