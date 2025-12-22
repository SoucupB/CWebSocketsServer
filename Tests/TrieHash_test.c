#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include "Array.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "Hsh.h"
#include "TimeFragment.h"
#include "TrieHash_Helper_test.h"

static void test_trie_hash_insertion_v1(void **state) {
  PHsh hash = hsh_Create();
  hsh_Integer32_Insert(hash, 1, 2);
  assert_true(hash != NULL);
  assert_true(hsh_Integer32_Get(hash, 1) != NULL && ((uint32_t *)hsh_Integer32_Get(hash, 1))[0] == 2);
  assert_true(hsh_Integer32_Get(hash, 2) == NULL);
  hsh_Integer32_RemoveElement(hash, 1);
  assert_true(hsh_Integer32_Get(hash, 1) == NULL);
  hsh_Delete(hash);
}

static void test_trie_hash_insertion_v2(void **state) {
  PHsh hash = hsh_Create();
  for(uint32_t i = 1; i <= 10000; i++) {
    hsh_Integer32_Insert(hash, i, 10000 - i);
  }
  for(uint32_t i = 20000; i <= 30000; i++) {
    hsh_Integer32_Insert(hash, i, 30000 - i);
  }
  for(uint32_t i = 1; i <= 10000; i++) {
     assert_true(hsh_Integer32_Get(hash, i) != NULL && ((uint32_t *)hsh_Integer32_Get(hash, i))[0] == 10000 - i);
  }
  for(uint32_t i = 10001; i < 20000; i++) {
     assert_true(hsh_Integer32_Get(hash, i) == NULL);
  }
  for(uint32_t i = 20000; i <= 30000; i++) {
     assert_true(hsh_Integer32_Get(hash, i) != NULL && ((uint32_t *)hsh_Integer32_Get(hash, i))[0] == 30000 - i);
  }
  for(uint32_t i = 20000; i <= 30000; i++) {
    hsh_Integer32_RemoveElement(hash, i);
  }
  for(uint32_t i = 20000; i <= 30000; i++) {
    assert_true(hsh_Integer32_Get(hash, i) == NULL);
  }
  for(uint32_t i = 1; i <= 10000; i++) {
    hsh_Integer32_RemoveElement(hash, i);
  }
  for(uint32_t i = 1; i <= 10000; i++) {
     assert_true(hsh_Integer32_Get(hash, i) == NULL);
  }
  hsh_Delete(hash);
}

static void test_trie_hash_insertion_v3(void **state) {
  PHsh hash = hsh_Create();
  // The zero also has to be added.
  hsh_Buffer_AddToIndex(hash, 1, "Testing string", strlen("Testing string") + 1);
  assert_true(hsh_Buffer_GetFromIndex(hash, 1) != NULL);
  assert_true(hsh_Buffer_GetFromIndex(hash, 2) == NULL);
  assert_true(strcmp(hsh_Buffer_GetFromIndex(hash, 1), "Testing string") == 0);
  hsh_Buffer_RemoveAtIndex(hash, 1);
  assert_true(hsh_Buffer_GetFromIndex(hash, 1) == NULL);
  hsh_Delete(hash);
}

static void test_trie_hash_insertion_v4(void **state) {
  PHsh hash = hsh_Create();
  // The zero also has to be added.
  hsh_Buffer_AddToIndex(hash, 1351131451, "Testing_string_v1", strlen("Testing_string_v1") + 1);
  hsh_Buffer_AddToIndex(hash, 1251425451, "Testing_string_v2", strlen("Testing_string_v2") + 1);
  hsh_Buffer_AddToIndex(hash, 1251324451, "Testing_string_v3", strlen("Testing_string_v3") + 1);
  assert_true(hsh_Buffer_GetFromIndex(hash, 1) == NULL);
  assert_true(hsh_Buffer_GetFromIndex(hash, 2) == NULL);
  assert_true(hsh_Buffer_GetFromIndex(hash, 1351131451) != NULL);
  assert_true(strcmp(hsh_Buffer_GetFromIndex(hash, 1351131451), "Testing_string_v1") == 0);
  assert_true(strcmp(hsh_Buffer_GetFromIndex(hash, 1251425451), "Testing_string_v2") == 0);
  assert_true(strcmp(hsh_Buffer_GetFromIndex(hash, 1251324451), "Testing_string_v3") == 0);
  hsh_Buffer_RemoveAtIndex(hash, 1351131451);
  assert_true(hsh_Buffer_GetFromIndex(hash, 1351131451) == NULL);
  hsh_Buffer_AddToIndex(hash, 1251324451, "Testing_string_v4", strlen("Testing_string_v4") + 1);
  assert_true(strcmp(hsh_Buffer_GetFromIndex(hash, 1251324451), "Testing_string_v4") == 0);
  hsh_Delete(hash);
}

static void test_trie_hash_insertion_v5(void **state) {
  PHsh hash = hsh_Create();
  size_t currentTime = tf_CurrentTimeMS();
  for(uint32_t i = 1; i <= 100000; i++) {
    hsh_Integer32_Insert(hash, i, 100000 - i);
  }
  for(uint32_t i = 200000; i <= 300000; i++) {
    hsh_Integer32_Insert(hash, i, 300000 - i);
  }
  for(uint32_t i = 1; i <= 100000; i++) {
    assert_true(hsh_Integer32_Get(hash, i) != NULL && ((uint32_t *)hsh_Integer32_Get(hash, i))[0] == 100000 - i);
  }
  for(uint32_t i = 100001; i < 200000; i++) {
    assert_true(hsh_Integer32_Get(hash, i) == NULL);
  }
  for(uint32_t i = 200000; i <= 300000; i++) {
    assert_true(hsh_Integer32_Get(hash, i) != NULL && ((uint32_t *)hsh_Integer32_Get(hash, i))[0] == 300000 - i);
  }
  for(uint32_t i = 200000; i <= 300000; i++) {
    hsh_Integer32_RemoveElement(hash, i);
  }
  for(uint32_t i = 200000; i <= 300000; i++) {
    assert_true(hsh_Integer32_Get(hash, i) == NULL);
  }
  for(uint32_t i = 1; i <= 100000; i++) {
    hsh_Integer32_RemoveElement(hash, i);
  }
  for(uint32_t i = 1; i <= 100000; i++) {
    assert_true(hsh_Integer32_Get(hash, i) == NULL);
  }
  size_t endTime = tf_CurrentTimeMS() - currentTime;
  printf("Time for trh inserts, checks and removals is %lu\n", endTime);
  hsh_Delete(hash);
}

static void test_trie_hash_insertion_get_values_v1(void **state) {
  PHsh hash = hsh_Create();
  uint32_t firstValue = 5;
  hsh_Buffer_AddToIndex(hash, 1, &firstValue, sizeof(uint32_t));
  Array response = hsh_GetValues(hash, sizeof(uint32_t));
  uint32_t *values = response->buffer;
  assert_true(response->size == 1);
  assert_true(values[0] == 5);
  arr_Delete(response);
  hsh_Delete(hash);
}

static void test_trie_hash_insertion_get_values_v2(void **state) {
  PHsh hash = hsh_Create();
  uint32_t values[] = {5, 2, 1, 3, 7, 4, 11, 34};
  for(size_t i = 0, c = sizeof(values) / sizeof(uint32_t); i < c; i++) {
    hsh_Buffer_AddToIndex(hash, i, &values[i], sizeof(uint32_t));
  }
  Array response = hsh_GetValues(hash, sizeof(uint32_t));
  uint32_t *vecValues = response->buffer;
  assert_true(response->size == sizeof(values) / sizeof(uint32_t));
  for(size_t i = 0, c = response->size; i < c; i++) {
    assert_true(vecValues[i] == values[i]);
  }
  arr_Delete(response);
  hsh_Delete(hash);
}

static void test_trie_hash_collect_integer_keys(void **state) {
  PHsh hash = hsh_Create();
  uint32_t values[] = {5, 2, 1, 3, 7, 4, 11, 34};
  uint32_t sortedValues[] = {1, 2, 3, 4, 5, 7, 11, 34};
  for(size_t i = 0, c = sizeof(values) / sizeof(uint32_t); i < c; i++) {
    hsh_Buffer_AddToIndex(hash, values[i], &i, sizeof(size_t));
  }
  Array response = hsh_GetKeys(hash);
  Key *buffer = response->buffer;
  for(size_t i = 0, c = response->size; i < c; i++) {
    uint32_t *currentPointer = (uint32_t *)buffer[i].key;
    assert_true(buffer[i].keySize == sizeof(uint32_t));
    assert_true(*currentPointer == sortedValues[i]);
  }
  hsh_FreeKeys(response);
  hsh_Delete(hash);
}

static void test_trie_hash_collect_multiple_integer_keys(void **state) {
  PHsh hash = hsh_Create();
  const size_t count = 50000;
  size_t *inputBuffer = test_Util_CreateBuffer(count);
  for(size_t i = 0; i < count; i++) {
    hsh_Buffer_AddToIndex64(hash, inputBuffer[i], &i, sizeof(size_t));
  }
  Array response = hsh_GetKeys(hash);
  Key *buffer = response->buffer;
  size_t *keyValues = malloc(sizeof(size_t) * count);
  for(size_t i = 0, c = response->size; i < c; i++) {
    size_t *currentPointer = (size_t *)buffer[i].key;
    assert_true(buffer[i].keySize == sizeof(size_t));
    keyValues[i] = *currentPointer;
  }
  test_Util_TestEquivalency(inputBuffer, keyValues, count);
  hsh_FreeKeys(response);
  hsh_Delete(hash);
  free(inputBuffer);
  free(keyValues);
}

static void test_trie_hash_collect_string_keys(void **state) {
  PHsh hash = hsh_Create();
  char *bufferInput[] = {
    "string_1", "string_222", "string_31", "string_4", "string_5"
  };
  const size_t count = sizeof(bufferInput) / sizeof(char *);
  for(size_t i = 0; i < count; i++) {
    hsh_Add(hash, bufferInput[i], strlen(bufferInput[i]), &i, sizeof(size_t));
  }
  Array response = hsh_GetKeys(hash);
  Key *buffer = response->buffer;
  test_Util_TestStringEquivalency(bufferInput, buffer, count);
  hsh_FreeKeys(response);
  hsh_Delete(hash);
}

static void test_trie_hash_insert_1_mil_32_bits_values(void **state) {
  PHsh hash = hsh_Create();
  size_t currentTime = tf_CurrentTimeMS();
  for(uint32_t i = 0; i <= 1000000; i++) {
    hsh_Integer32_Insert(hash, i, 1000000 - i);
  }
  size_t endTime = tf_CurrentTimeMS() - currentTime;
  printf("Time for trh inserts is %lu\n", endTime);
  hsh_Delete(hash);
}

static void test_trie_hash_get_1_mil_values(void **state) {
  PHsh hash = hsh_Create();
  for(uint32_t i = 0; i <= 1000000; i++) {
    hsh_Integer32_Insert(hash, i, 1000000 - i);
  }
  size_t currentTime = tf_CurrentTimeMS();
  for(uint32_t i = 0; i <= 1000000; i++) {
    assert_int_equal(*(uint32_t *)hsh_Integer32_Get(hash, i), 1000000 - i);
  }
  size_t endTime = tf_CurrentTimeMS() - currentTime;
  printf("Time for trh gets is %lu\n", endTime);
  hsh_Delete(hash);
}

static void test_trie_hash_del_1_mil_values(void **state) {
  PHsh hash = hsh_Create();
  for(uint32_t i = 0; i <= 1000000; i++) {
    hsh_Integer32_Insert(hash, i, 1000000 - i);
  }
  size_t currentTime = tf_CurrentTimeMS();
  for(uint32_t i = 0; i <= 1000000; i++) {
    hsh_Integer32_RemoveElement(hash, i);
  }
  size_t endTime = tf_CurrentTimeMS() - currentTime;
  for(uint32_t i = 0; i <= 1000000; i++) {
    hsh_Integer32_RemoveElement(hash, i);
    assert_null(hsh_Integer32_Get(hash, i));
  }
  printf("Time for trh deletes is %lu\n", endTime);
  hsh_Delete(hash);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_trie_hash_insertion_v1, NULL),
    cmocka_unit_test_prestate(test_trie_hash_insertion_v2, NULL),
    cmocka_unit_test_prestate(test_trie_hash_insertion_v3, NULL),
    cmocka_unit_test_prestate(test_trie_hash_insertion_v4, NULL),
    cmocka_unit_test_prestate(test_trie_hash_insertion_v5, NULL),
    cmocka_unit_test_prestate(test_trie_hash_insertion_get_values_v1, NULL),
    cmocka_unit_test_prestate(test_trie_hash_insertion_get_values_v2, NULL),
    cmocka_unit_test_prestate(test_trie_hash_collect_integer_keys, NULL),
    cmocka_unit_test_prestate(test_trie_hash_collect_multiple_integer_keys, NULL),
    cmocka_unit_test_prestate(test_trie_hash_collect_string_keys, NULL),
    cmocka_unit_test_prestate(test_trie_hash_insert_1_mil_32_bits_values, NULL),
    cmocka_unit_test_prestate(test_trie_hash_get_1_mil_values, NULL),
    cmocka_unit_test_prestate(test_trie_hash_del_1_mil_values, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}