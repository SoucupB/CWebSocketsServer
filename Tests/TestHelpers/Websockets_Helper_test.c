#include "Websockets_Helper_test.h"
#include <string.h>
#include <stdlib.h>

WebSocketObject test_Util_Transform(char *buffer, size_t sz) {
  WebSocketObject sockObj = (WebSocketObject) {
    .buffer = crm_Alloc(sz),
    .sz = sz,
    .opcode = OPCODE_BINARY
  };
  memcpy(sockObj.buffer, buffer, sz);
  return sockObj;
}

void test_Util_Delete(WebSocketObject obj) {
  crm_Free(obj.buffer);
}

char *test_Util_RepeatMessage(char *msg, size_t sz, size_t count) {
  char *response = crm_Alloc(count * sz + 1);
  for(size_t i = 0, c = 0; i < count; i++) {
    for(size_t j = 0; j < sz; j++) {
      response[c++] = msg[j];
    }
  }
  response[count * sz] = 0;
  return response;
}

void test_Util_PushString(char *src, char *dst, size_t sz) {
  memcpy(src, dst, sz);
}

WebSocketObject test_Util_CreateMessages(char **messages, size_t sz, uint8_t masked) {
  size_t totalSize = 0;
  size_t finalMessageSize = 0;
  for(size_t i = 0; i < sz; i++) {
    totalSize += strlen(messages[i]);
  }
  char *response = crm_Alloc(2 * (totalSize + 1));
  memset(response, 0, 2 * (totalSize + 1));
  char *rspCpy = response;
  for(size_t i = 0; i < sz; i++) {
    WebSocketObject drr = test_Util_Transform(messages[i], strlen(messages[i]));
    char *newMessage = masked ? wbs_Masked_ToWebSocket(drr) : wbs_ToWebSocket(drr);
    size_t msgSize = wbs_FullMessageSize(newMessage);
    test_Util_PushString(response, newMessage, msgSize);
    response += msgSize;
    finalMessageSize += msgSize;
    test_Util_Delete(drr);
    crm_Free(newMessage);
  }
  return (WebSocketObject) {
    .buffer = rspCpy,
    .sz = finalMessageSize
  };
}