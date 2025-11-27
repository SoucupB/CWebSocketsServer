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

static void test_string_parse_simple_element(void **state) {
  PJsonObject jsonObj = json_Create();
  HttpString key = json_Helper_Add("some_key");
  int64_t integerElement = 32425;
  JsonElement elem = {
    .value = &integerElement,
    .type = JSON_INTEGER
  };
  json_Add(jsonObj, &key, elem);
  HttpString toS = json_ToString(jsonObj);
  assert_memory_equal(toS.buffer, "{\"some_key\":32425}", sizeof("{\"some_key\":32425}") - 1);
  json_Delete(jsonObj);
  free(toS.buffer);
}

static void test_string_parse_simple_multiple_elements(void **state) {
  PJsonObject jsonObj = json_Create();
  HttpString key1 = json_Helper_Add("some_key_1");
  HttpString key2 = json_Helper_Add("some_key_2");
  json_Add(jsonObj, &key1, json_Helper_Integer(32425LL));
  json_Add(jsonObj, &key2, json_Helper_Integer(4434325252611LL));
  HttpString toS = json_ToString(jsonObj);

  printf("ZZZZ %.*s\n", toS.sz, toS.buffer);
  // assert_memory_equal(toS.buffer, "{\"some_key\":32425}", sizeof("{\"some_key\":32425}") - 1);
  json_Delete(jsonObj);
  free(toS.buffer);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_string_parse_simple_element, NULL),
    cmocka_unit_test_prestate(test_string_parse_simple_multiple_elements, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}