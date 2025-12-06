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

#define EPSILON 1e-5f

typedef struct TokenParser_t {
  char *startToken;
  char *endToken;
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
TokenParser json_Parser_Integer(TokenParser tck);
TokenParser json_Parser_Number(TokenParser tck);
TokenParser json_Parser_Map(TokenParser tck);
TokenParser json_Parser_Array(TokenParser tck);
JsonElement json_Parser_Get_String(TokenParser tck, PTokenParser next);
JsonElement json_Parser_Get_Integer(TokenParser tck, PTokenParser next);
JsonElement json_Parser_Get_Number(TokenParser tck, PTokenParser next);
JsonElement json_Parser_Get_Map(TokenParser tck, PTokenParser next);

void json_DeleteElement(JsonElement element);

static void test_string_parse_str_string(void **state) {
  char *arr = "\"Some str value\"";
  TokenParser parseData = json_Parser_String((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
}

static void test_string_parse_str_string_with_special_chars(void **state) {
  char *arr = "\"Some str \\\"value\"";
  TokenParser parseData = json_Parser_String((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
}

static void test_string_parse_str_without_ending_char(void **state) {
  char *arr = "\"Some str \"value\"";
  TokenParser parseData = json_Parser_String((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_not_equal(parseData.endToken, parseData.endingBuffer);
}

static void test_string_parse_str_with_spaces(void **state) {
  char *arr = "    \"Some str value\"";
  TokenParser parseData = json_Parser_String((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
}

static void test_string_parse_str_invalid(void **state) {
  char *arr = "    Some str value\"";
  TokenParser parseData = json_Parser_String((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_integer(void **state) {
  char *arr = "  99314";
  TokenParser parseData = json_Parser_Integer((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
}

static void test_string_parse_integer_with_non_digits(void **state) {
  char *arr = "  99314a";
  TokenParser parseData = json_Parser_Integer((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_not_equal(parseData.endToken, parseData.endingBuffer);
}

static void test_string_parse_non_integer(void **state) {
  char *arr = "  a99314";
  TokenParser parseData = json_Parser_Integer((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_number(void **state) {
  char *arr = "32.344";
  TokenParser parseData = json_Parser_Number((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
}

static void test_string_parse_number_invalid(void **state) {
  char *arr = "32";
  TokenParser parseData = json_Parser_Number((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_number_invalid_with_chars(void **state) {
  char *arr = "a32.34";
  TokenParser parseData = json_Parser_Number((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_number_invalid_missing_exponent(void **state) {
  char *arr = "32.";
  TokenParser parseData = json_Parser_Number((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_number_multiple_pnts(void **state) {
  char *arr = "32.12.42";
  TokenParser parseData = json_Parser_Number((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_not_equal(parseData.endToken, parseData.endingBuffer);
}

static void test_string_parse_get(void **state) {
  char *arr = "    \"Some str value\"";
  JsonElement parseData = json_Parser_Get_String((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  assert_ptr_not_equal(parseData.value, NULL);
  assert_memory_equal(((PHttpString)parseData.value)->buffer, "Some str value", sizeof("Some str value") - 1);
  json_DeleteElement(parseData);
}

static void test_string_parse_get_with_special(void **state) {
  char *arr = "    \"Some str \\\" ddd value\"";
  JsonElement parseData = json_Parser_Get_String((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  assert_ptr_not_equal(parseData.value, NULL);
  assert_memory_equal(((PHttpString)parseData.value)->buffer, "Some str \\\" ddd value", sizeof("Some str \\\" ddd value") - 1);
  json_DeleteElement(parseData);
}

static void test_string_parse_numbers(void **state) {
  char *arr = " 9932";
  JsonElement parseData = json_Parser_Get_Integer((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  assert_ptr_not_equal(parseData.value, NULL);
  assert_int_equal(*(int64_t *)parseData.value, 9932);
  json_DeleteElement(parseData);
}

static void test_string_parse_numbers_negative(void **state) {
  char *arr = " -9932";
  JsonElement parseData = json_Parser_Get_Integer((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  assert_ptr_not_equal(parseData.value, NULL);
  assert_int_equal(*(int64_t *)parseData.value, -9932);
  json_DeleteElement(parseData);
}

static void test_string_parse_numbers_with_alpha_values(void **state) {
  char *arr = " -99da32";
  JsonElement parseData = json_Parser_Get_Integer((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  assert_ptr_not_equal(parseData.value, NULL);
  assert_int_equal(*(int64_t *)parseData.value, -99);
  json_DeleteElement(parseData);
}

static void test_string_parse_numbers_invalid(void **state) {
  char *arr = " -";
  JsonElement parseData = json_Parser_Get_Integer((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_equal(parseData.type, JSON_INVALID);
}

static void test_string_parse_numbers_invalid_overflow(void **state) {
  char *arr = " 99999999999999999999";
  JsonElement parseData = json_Parser_Get_Integer((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_equal(parseData.type, JSON_INVALID);
}

static void test_string_parse_numbers_invalid_with_multiple_negative_signs(void **state) {
  char *arr = " --3242";
  JsonElement parseData = json_Parser_Get_Integer((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_equal(parseData.type, JSON_INVALID);
}

static void test_string_parse_float_negative(void **state) {
  char *arr = " -9932.532";
  JsonElement parseData = json_Parser_Get_Number((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  assert_ptr_not_equal(parseData.value, NULL);
  assert_float_equal(*(float *)parseData.value, -9932.532f, EPSILON);
  json_DeleteElement(parseData);
}

static void test_string_parse_float_positive(void **state) {
  char *arr = "9932.532";
  JsonElement parseData = json_Parser_Get_Number((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  assert_ptr_not_equal(parseData.value, NULL);
  assert_float_equal(*(float *)parseData.value, 9932.532f, EPSILON);
  json_DeleteElement(parseData);
}

static void test_string_parse_float_combination(void **state) {
  char *arr = "993.2ada32.532";
  JsonElement parseData = json_Parser_Get_Number((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  assert_ptr_not_equal(parseData.value, NULL);
  assert_float_equal(*(float *)parseData.value, 993.2f, EPSILON);
  json_DeleteElement(parseData);
}

static void test_string_parse_simple_map(void **state) {
  char *arr = "{\"tenis\": 3241}";
  TokenParser parseData = json_Parser_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
  assert_int_equal(parseData.endToken - parseData.startToken, 15);
}

static void test_string_parse_invalid_map(void **state) {
  char *arr = "dsa{\"tenis\": 3241}";
  TokenParser parseData = json_Parser_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_complex_map(void **state) {
  char *arr = "  {\"tenis\": \"hika\"}";
  TokenParser parseData = json_Parser_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
  assert_int_equal(parseData.endToken - parseData.startToken, 17);
}

static void test_string_parse_all_data_map(void **state) {
  char *arr = "  {\"tenis\": \"hika\", \"ddddd\": 12.3142, \"aaa\": 44}";
  TokenParser parseData = json_Parser_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
  assert_memory_equal("{\"tenis\": \"hika\", \"ddddd\": 12.3142, \"aaa\": 44}", parseData.startToken, 
               sizeof("{\"tenis\": \"hika\", \"ddddd\": 12.3142, \"aaa\": 44}") - 1);
}

static void test_string_parse_embeded_data(void **state) {
  char *arr = "  {\"tenis\": \"hika\", \"ddddd\": 12.3142, \"aaa\": 44, \"aba\": {  \"ggg\": 32, \"tr\": \"daggg\"}}";
  TokenParser parseData = json_Parser_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
  char *toTest = "{\"tenis\": \"hika\", \"ddddd\": 12.3142, \"aaa\": 44, \"aba\": {  \"ggg\": 32, \"tr\": \"daggg\"}}";
  assert_memory_equal(toTest, parseData.startToken, strlen(toTest));
}

static void test_string_parse_embeded_invalid(void **state) {
  char *arr = "  {\"tenis\": \"hika\", \"ddddd\": 12.3142, \"aaa\": 44, \"aba\": {   \"ggg\":    32, \"tr\": \"daggg\"}";
  TokenParser parseData = json_Parser_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_invalid_comma_json(void **state) {
  char *arr = "  {\"tenis\": \"hika\",}";
  TokenParser parseData = json_Parser_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_invalid_string(void **state) {
  char *arr = "  {\"tenis: \"hika\"}";
  TokenParser parseData = json_Parser_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_array(void **state) {
  char *arr = " [1, 2, 3, 3.4, \"aaadb\"]";
  TokenParser parseData = json_Parser_Array((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
  char *toTest = "[1, 2, 3, 3.4, \"aaadb\"]";
  assert_int_equal(parseData.endToken - parseData.startToken, strlen(toTest));
  assert_memory_equal(toTest, parseData.startToken, strlen(toTest));
}

static void test_string_parse_array_embeded(void **state) {
  char *arr = "   [1, 2, [1, \"azzz\"], 3, 3.4, \"aaadb\"]";
  TokenParser parseData = json_Parser_Array((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
  char *toTest = "[1, 2, [1, \"azzz\"], 3, 3.4, \"aaadb\"]";
  assert_int_equal(parseData.endToken - parseData.startToken, strlen(toTest));
  assert_memory_equal(toTest, parseData.startToken, strlen(toTest));
}

static void test_string_parse_array_invalid(void **state) {
  char *arr = "  [1, 2, [1, \"azzz\", 3, 3.4, \"aaadb\"]";
  TokenParser parseData = json_Parser_Array((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_equal(parseData.endToken, NULL);
}

static void test_string_parse_array_with_map(void **state) {
  char *arr = "   [1, 2, [1, \"azzz\", 3, 3.4], {\"aad\": 32, \"ssd\": [1, 2]}, \"aaadb\"]";
  TokenParser parseData = json_Parser_Array((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  });
  assert_ptr_not_equal(parseData.endToken, NULL);
  assert_ptr_equal(parseData.endToken, parseData.endingBuffer);
  char *toTest = "[1, 2, [1, \"azzz\", 3, 3.4], {\"aad\": 32, \"ssd\": [1, 2]}, \"aaadb\"]";
  assert_memory_equal(toTest, parseData.startToken, strlen(toTest));
  assert_int_equal(parseData.endToken - parseData.startToken, strlen(toTest));
}

static void test_string_parse_map_data(void **state) {
  // char *arr = "{\"aada\": 3, \"daff\": \"113\"}";
  char *arr = "{\"aada\": 3}";
  JsonElement parseData = json_Parser_Get_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  HttpString strResponse = json_Element_ToString(parseData);
  char *expected = "{\"aada\":3}";
  assert_int_equal(strResponse.sz, strlen(expected));
  assert_memory_equal(strResponse.buffer, expected, strResponse.sz);
  // printf("%.*s\n", strResponse.sz, strResponse.buffer);
  free(strResponse.buffer);
  json_DeleteElement(parseData);
}

static void test_string_parse_map_data_composite(void **state) {
  char *arr = "{\"aada\": 3, \"daff\": \"113\"}";
  JsonElement parseData = json_Parser_Get_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  HttpString strResponse = json_Element_ToString(parseData);
  char *expected = "{\"aada\":3,\"daff\":\"113\"}";
  assert_int_equal(strResponse.sz, strlen(expected));
  assert_memory_equal(strResponse.buffer, expected, strResponse.sz);
  free(strResponse.buffer);
  json_DeleteElement(parseData);
}

static void test_string_parse_map_data_recursive(void **state) {
  char *arr = "{\"aada\": 3, \"daff\": \"113\", \"some_other_key\":{\"a\": 5}}";
  JsonElement parseData = json_Parser_Get_Map((TokenParser) {
    .endToken = arr,
    .endingBuffer = arr + strlen(arr)
  }, NULL);
  assert_int_not_equal(parseData.type, JSON_INVALID);
  HttpString strResponse = json_Element_ToString(parseData);
  char *expected = "{\"aada\":3,\"daff\":\"113\",\"some_other_key\":{\"a\":5}}";
  assert_int_equal(strResponse.sz, strlen(expected));
  assert_memory_equal(strResponse.buffer, expected, strResponse.sz);
  free(strResponse.buffer);
  json_DeleteElement(parseData);
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
    cmocka_unit_test_prestate(test_string_parse_str_with_spaces, NULL),
    cmocka_unit_test_prestate(test_string_parse_str_invalid, NULL),
    cmocka_unit_test_prestate(test_string_parse_integer, NULL),
    cmocka_unit_test_prestate(test_string_parse_integer_with_non_digits, NULL),
    cmocka_unit_test_prestate(test_string_parse_non_integer, NULL),
    cmocka_unit_test_prestate(test_string_parse_number, NULL),
    cmocka_unit_test_prestate(test_string_parse_number_invalid, NULL),
    cmocka_unit_test_prestate(test_string_parse_number_invalid_with_chars, NULL),
    cmocka_unit_test_prestate(test_string_parse_number_invalid_missing_exponent, NULL),
    cmocka_unit_test_prestate(test_string_parse_number_multiple_pnts, NULL),
    cmocka_unit_test_prestate(test_string_parse_get, NULL),
    cmocka_unit_test_prestate(test_string_parse_get_with_special, NULL),
    cmocka_unit_test_prestate(test_string_parse_numbers, NULL),
    cmocka_unit_test_prestate(test_string_parse_numbers_negative, NULL),
    cmocka_unit_test_prestate(test_string_parse_numbers_with_alpha_values, NULL),
    cmocka_unit_test_prestate(test_string_parse_numbers_invalid, NULL),
    cmocka_unit_test_prestate(test_string_parse_numbers_invalid_with_multiple_negative_signs, NULL),
    cmocka_unit_test_prestate(test_string_parse_numbers_invalid_overflow, NULL),
    cmocka_unit_test_prestate(test_string_parse_float_negative, NULL),
    cmocka_unit_test_prestate(test_string_parse_float_positive, NULL),
    cmocka_unit_test_prestate(test_string_parse_float_combination, NULL),
    cmocka_unit_test_prestate(test_string_parse_simple_map, NULL),
    cmocka_unit_test_prestate(test_string_parse_invalid_map, NULL),
    cmocka_unit_test_prestate(test_string_parse_complex_map, NULL),
    cmocka_unit_test_prestate(test_string_parse_all_data_map, NULL),
    cmocka_unit_test_prestate(test_string_parse_embeded_data, NULL),
    cmocka_unit_test_prestate(test_string_parse_embeded_invalid, NULL),
    cmocka_unit_test_prestate(test_string_parse_invalid_comma_json, NULL),
    cmocka_unit_test_prestate(test_string_parse_invalid_string, NULL),
    cmocka_unit_test_prestate(test_string_parse_array, NULL),
    cmocka_unit_test_prestate(test_string_parse_array_embeded, NULL),
    cmocka_unit_test_prestate(test_string_parse_array_invalid, NULL),
    cmocka_unit_test_prestate(test_string_parse_array_with_map, NULL),
    cmocka_unit_test_prestate(test_string_parse_map_data, NULL),
    cmocka_unit_test_prestate(test_string_parse_map_data_composite, NULL),
    cmocka_unit_test_prestate(test_string_parse_map_data_recursive, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}