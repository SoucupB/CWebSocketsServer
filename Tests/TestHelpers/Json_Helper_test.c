#include "Json_Helper_test.h"
#include "HttpParser.h"
#include <string.h>

JsonElement test_Helper_Json_Parse(char *map) {
  return json_Parse((HttpString) {
    .buffer = map,
    .sz = strlen(map)
  }, NULL);
}

PHttpRequest test_Helper_Json_Create(JsonElement element){
  PHttpRequest req = http_Request_Basic();
  HttpString strElement = json_Element_ToString(element);
  http_Request_SetBody(req, strElement);
  crm_Free(strElement.buffer);
  return req;
}