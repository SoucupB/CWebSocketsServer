#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include "Vector.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "Structs.h"
#include "JsonParser.h"
#include "JsonParser_Helper_test.h"

static void test_string_parse_simple_elements(void **state) {
  PJsonObject jsonObj = json_Create();
  HttpString key = json_Helper_Add("some_key");
  int64_t integerElement = 32425;
  JsonElement elem = {
    .value = &integerElement,
    .type = JSON_INTEGER
  };
  json_Add(jsonObj, &key, elem);
  json_Delete(jsonObj);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_string_parse_simple_elements, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}