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

typedef struct TokenParser_t {
  char *startingBuffer;
  char *endingBuffer;
} TokenParser;

typedef TokenParser *PTokenParser;

static void test_string_parse_simple_element(void **state) {
  PJsonObject jsonObj = json_Helper_Create();
  HttpString key = json_Helper_Add("some_key");
  json_Add(jsonObj, &key, json_Helper_Integer(32425LL));
  HttpString toS = json_ToString(jsonObj);
  assert_memory_equal(toS.buffer, "{\"some_key\":32425}", sizeof("{\"some_key\":32425}") - 1);
  json_Delete(jsonObj);
  free(toS.buffer);
}

static void test_string_parse_simple_multiple_elements(void **state) {
  PJsonObject jsonObj = json_Helper_Create();
  HttpString key1 = json_Helper_Add("some_key_1");
  HttpString key2 = json_Helper_Add("some_key_2");
  HttpString key3 = json_Helper_Add("some_key_3");
  HttpString key4 = json_Helper_Add("some_key_4");
  json_Add(jsonObj, &key1, json_Helper_Integer(32425LL));
  json_Add(jsonObj, &key2, json_Helper_Integer(4434325252611LL));
  json_Add(jsonObj, &key3, json_Helper_Number(25.5f));
  json_Add(jsonObj, &key4, json_Helper_String("some_value_data"));
  HttpString toS = json_ToString(jsonObj);
  assert_memory_equal(toS.buffer, "{\"some_key_1\":32425,\"some_key_2\":4434325252611,\"so\
me_key_3\":25.500000,\"some_key_4\":\"some_value_data\"}", sizeof("{\"some_key_1\":32425,\"some_key_2\":4434325252611,\"so\
me_key_3\":25.500000,\"some_key_4\":\"some_value_data\"}") - 1);
  json_Delete(jsonObj);
  free(toS.buffer);
}

static void test_string_parse_recursive(void **state) {
  PJsonObject jsonObj = json_Helper_Create();
  HttpString key1 = json_Helper_Add("some_key_1");
  HttpString key2 = json_Helper_Add("some_key_2");
  HttpString key3 = json_Helper_Add("some_key_3");
  json_Add(jsonObj, &key1, json_Helper_Integer(32425LL));
  json_Add(jsonObj, &key3, json_Helper_Number(324.5f));
  PJsonObject jsonObj2 = json_Helper_Create();
  json_Add(jsonObj2, &key1, json_Helper_Integer(332LL));
  json_Add(jsonObj, &key2, json_Helper_Json(jsonObj2));
  HttpString toS = json_ToString(jsonObj);
  assert_memory_equal(toS.buffer, "{\"some_key_1\":32425,\"some_key_2\":{\"some\
_key_1\":332},\"some_key_3\":324.500000}", sizeof("{\"some_key_1\":32425,\"some_key_2\":{\"some\
_key_1\":332},\"some_key_3\":324.500000}") - 1);
  json_Delete(jsonObj);
  free(toS.buffer);
}

static void test_string_parse_list_array(void **state) {
  PJsonObject jsonObj = json_Helper_Create();
  HttpString key1 = json_Helper_Add("some_key_1");
  JsonElement objArr = json_Helper_Array();
  json_Add(jsonObj, &key1, objArr);
  json_Helper_Array_Push(objArr, json_Helper_Integer(332LL));
  json_Helper_Array_Push(objArr, json_Helper_Integer(11LL));
  json_Helper_Array_Push(objArr, json_Helper_Number(25.5f));
  json_Helper_Array_Push(objArr, json_Helper_String("some_value_data"));
  json_Helper_Array_Push(objArr, json_Helper_Json(json_Helper_Create()));

  HttpString toS = json_ToString(jsonObj);
  assert_memory_equal(toS.buffer, "{\"some_key_1\":[332,11,25.\
500000,\"some_value_data\",{}]}", sizeof("{\"some_key_1\":[332,11,25.\
500000,\"some_value_data\",{}]}") - 1);
  json_Delete(jsonObj);
  free(toS.buffer);
}

static void test_string_parse_list_array_of_json_objects(void **state) {
  PJsonObject jsonObj = json_Helper_Create();
  HttpString key1 = json_Helper_Add("some_key_1");
  JsonElement objArr = json_Helper_Array();
  json_Add(jsonObj, &key1, objArr);
  json_Helper_Array_Push(objArr, json_Helper_Integer(332LL));
  json_Helper_Array_Push(objArr, json_Helper_Integer(11LL));
  json_Helper_Array_Push(objArr, json_Helper_Number(25.5f));
  json_Helper_Array_Push(objArr, json_Helper_String("some_value_data"));
  PJsonObject jsonObj2 = json_Helper_Create();
  json_Helper_Array_Push(objArr, json_Helper_Json(jsonObj2));
  HttpString key2 = json_Helper_Add("some_key_2");
  HttpString key3 = json_Helper_Add("some_key_3");
  json_Add(jsonObj2, &key2, json_Helper_Integer(32425LL));
  json_Add(jsonObj2, &key3, json_Helper_Integer(123LL));

  HttpString toS = json_ToString(jsonObj);
  assert_memory_equal(toS.buffer, "{\"some_key_1\":[332,11,25.500000,\"some_value_\
data\",{\"some_key_2\":32425,\"some_key_3\":123}]}", sizeof("{\"some_key_1\":[332,11,25.500000,\"some_value_\
data\",{\"some_key_2\":32425,\"some_key_3\":123}]}") - 1);
  json_Delete(jsonObj);
  free(toS.buffer);
}

TokenParser json_Parser_String(TokenParser tck);

static void test_string_parse_str_string(void **state) {
  char *arr = "\"Some str value\"";
  TokenParser parseData = json_Parser_String((TokenParser) {
    .startingBuffer = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.startingBuffer, NULL);
  assert_ptr_equal(parseData.startingBuffer, parseData.endingBuffer);
}

static void test_string_parse_str_string_with_special_chars(void **state) {
  char *arr = "\"Some str \\\"value\"";
  TokenParser parseData = json_Parser_String((TokenParser) {
    .startingBuffer = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.startingBuffer, NULL);
  assert_ptr_equal(parseData.startingBuffer, parseData.endingBuffer);
}

static void test_string_parse_str_without_ending_char(void **state) {
  char *arr = "\"Some str \"value\"";
  TokenParser parseData = json_Parser_String((TokenParser) {
    .startingBuffer = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.startingBuffer, NULL);
  assert_ptr_not_equal(parseData.startingBuffer, parseData.endingBuffer);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_string_parse_simple_element, NULL),
    cmocka_unit_test_prestate(test_string_parse_simple_multiple_elements, NULL),
    cmocka_unit_test_prestate(test_string_parse_recursive, NULL),
    cmocka_unit_test_prestate(test_string_parse_list_array, NULL),
    cmocka_unit_test_prestate(test_string_parse_list_array_of_json_objects, NULL),
    cmocka_unit_test_prestate(test_string_parse_str_string, NULL),
    cmocka_unit_test_prestate(test_string_parse_str_string_with_special_chars, NULL),
    cmocka_unit_test_prestate(test_string_parse_str_without_ending_char, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}