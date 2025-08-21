#include "Websockets_Helper_test.h"
#include <string.h>
#include <stdlib.h>

WebSocketObject test_Util_Transform(char *buffer, size_t sz) {
  WebSocketObject sockObj = (WebSocketObject) {
    .buffer = malloc(sz),
    .sz = sz
  };
  memcpy(sockObj.buffer, buffer, sz);
  return sockObj;
}

void test_Util_Delete(WebSocketObject obj) {
  free(obj.buffer);
}

char *test_Util_RepeatMessage(char *msg, size_t sz, size_t count) {
  char *response = malloc(count * sz);
  for(size_t i = 0, c = 0; i < count; i++) {
    for(size_t j = 0; j < sz; j++) {
      response[c++] = msg[j];
    }
  }
  return response;
}