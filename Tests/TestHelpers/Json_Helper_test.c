#include "Json_Helper_test.h"
#include <string.h>

JsonElement test_Helper_Json_Parse(char *map) {
  return json_Parse((HttpString) {
    .buffer = map,
    .sz = strlen(map)
  }, NULL);
}