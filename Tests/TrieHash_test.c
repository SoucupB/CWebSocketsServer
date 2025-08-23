#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "TrieHash.h"
#include "TimeFragment.h"

static void test_trie_hash_insertion_v1(void **state) {
  PTrieHash hash = trh_Create();
  trh_Integer32_Insert(hash, 1, 2);
  assert_true(hash != NULL);
  assert_true(trh_Integer32_Get(hash, 1) != NULL && ((uint32_t *)trh_Integer32_Get(hash, 1))[0] == 2);
  assert_true(trh_Integer32_Get(hash, 2) == NULL);
  trh_Integer32_RemoveElement(hash, 1);
  assert_true(trh_Integer32_Get(hash, 1) == NULL);
  trh_Delete(hash);
}

static void test_trie_hash_insertion_v2(void **state) {
  PTrieHash hash = trh_Create();
  for(uint32_t i = 1; i <= 10000; i++) {
    trh_Integer32_Insert(hash, i, 10000 - i);
  }
  for(uint32_t i = 20000; i <= 30000; i++) {
    trh_Integer32_Insert(hash, i, 30000 - i);
  }
  for(uint32_t i = 1; i <= 10000; i++) {
     assert_true(trh_Integer32_Get(hash, i) != NULL && ((uint32_t *)trh_Integer32_Get(hash, i))[0] == 10000 - i);
  }
  for(uint32_t i = 10001; i < 20000; i++) {
     assert_true(trh_Integer32_Get(hash, i) == NULL);
  }
  for(uint32_t i = 20000; i <= 30000; i++) {
     assert_true(trh_Integer32_Get(hash, i) != NULL && ((uint32_t *)trh_Integer32_Get(hash, i))[0] == 30000 - i);
  }
  for(uint32_t i = 20000; i <= 30000; i++) {
    trh_Integer32_RemoveElement(hash, i);
  }
  for(uint32_t i = 20000; i <= 30000; i++) {
    assert_true(trh_Integer32_Get(hash, i) == NULL);
  }
  for(uint32_t i = 1; i <= 10000; i++) {
    trh_Integer32_RemoveElement(hash, i);
  }
  for(uint32_t i = 1; i <= 10000; i++) {
     assert_true(trh_Integer32_Get(hash, i) == NULL);
  }
  trh_Delete(hash);
}

static void test_trie_hash_insertion_v3(void **state) {
  PTrieHash hash = trh_Create();
  // The zero also has to be added.
  trh_Buffer_AddToIndex(hash, 1, "Testing string", strlen("Testing string") + 1);
  assert_true(trh_Buffer_GetFromIndex(hash, 1) != NULL);
  assert_true(trh_Buffer_GetFromIndex(hash, 2) == NULL);
  assert_true(strcmp(trh_Buffer_GetFromIndex(hash, 1), "Testing string") == 0);
  trh_Buffer_RemoveAtIndex(hash, 1);
  assert_true(trh_Buffer_GetFromIndex(hash, 1) == NULL);
  trh_Delete(hash);
}

static void test_trie_hash_insertion_v4(void **state) {
  PTrieHash hash = trh_Create();
  // The zero also has to be added.
  trh_Buffer_AddToIndex(hash, 1351131451, "Testing_string_v1", strlen("Testing_string_v1") + 1);
  trh_Buffer_AddToIndex(hash, 1251425451, "Testing_string_v2", strlen("Testing_string_v2") + 1);
  trh_Buffer_AddToIndex(hash, 1251324451, "Testing_string_v3", strlen("Testing_string_v3") + 1);
  assert_true(trh_Buffer_GetFromIndex(hash, 1) == NULL);
  assert_true(trh_Buffer_GetFromIndex(hash, 2) == NULL);
  assert_true(trh_Buffer_GetFromIndex(hash, 1351131451) != NULL);
  assert_true(strcmp(trh_Buffer_GetFromIndex(hash, 1351131451), "Testing_string_v1") == 0);
  assert_true(strcmp(trh_Buffer_GetFromIndex(hash, 1251425451), "Testing_string_v2") == 0);
  assert_true(strcmp(trh_Buffer_GetFromIndex(hash, 1251324451), "Testing_string_v3") == 0);
  trh_Buffer_RemoveAtIndex(hash, 1351131451);
  assert_true(trh_Buffer_GetFromIndex(hash, 1351131451) == NULL);
  trh_Buffer_AddToIndex(hash, 1251324451, "Testing_string_v4", strlen("Testing_string_v4") + 1);
  assert_true(strcmp(trh_Buffer_GetFromIndex(hash, 1251324451), "Testing_string_v4") == 0);
  trh_Delete(hash);
}

static void test_trie_hash_insertion_v5(void **state) {
  PTrieHash hash = trh_Create();
  size_t currentTime = tf_CurrentTimeMS();
  for(uint32_t i = 1; i <= 100000; i++) {
    trh_Integer32_Insert(hash, i, 100000 - i);
  }
  for(uint32_t i = 200000; i <= 300000; i++) {
    trh_Integer32_Insert(hash, i, 300000 - i);
  }
  for(uint32_t i = 1; i <= 100000; i++) {
    assert_true(trh_Integer32_Get(hash, i) != NULL && ((uint32_t *)trh_Integer32_Get(hash, i))[0] == 100000 - i);
  }
  for(uint32_t i = 100001; i < 200000; i++) {
    assert_true(trh_Integer32_Get(hash, i) == NULL);
  }
  for(uint32_t i = 200000; i <= 300000; i++) {
    assert_true(trh_Integer32_Get(hash, i) != NULL && ((uint32_t *)trh_Integer32_Get(hash, i))[0] == 300000 - i);
  }
  for(uint32_t i = 200000; i <= 300000; i++) {
    trh_Integer32_RemoveElement(hash, i);
  }
  for(uint32_t i = 200000; i <= 300000; i++) {
    assert_true(trh_Integer32_Get(hash, i) == NULL);
  }
  for(uint32_t i = 1; i <= 100000; i++) {
    trh_Integer32_RemoveElement(hash, i);
  }
  for(uint32_t i = 1; i <= 100000; i++) {
    assert_true(trh_Integer32_Get(hash, i) == NULL);
  }
  size_t endTime = tf_CurrentTimeMS() - currentTime;
  printf("Time for trh inserts, checks and removals is %lu\n", endTime);
  trh_Delete(hash);
}

static void test_trie_hash_insertion_get_values_v1(void **state) {
  PTrieHash hash = trh_Create();
  uint32_t firstValue = 5;
  trh_Buffer_AddToIndex(hash, 1, &firstValue, sizeof(uint32_t));
  Vector response = trh_GetValues(hash, sizeof(uint32_t));
  uint32_t *values = response->buffer;
  assert_true(response->size == 1);
  assert_true(values[0] == 5);
  vct_Delete(response);
  trh_Delete(hash);
}

static void test_trie_hash_insertion_get_values_v2(void **state) {
  PTrieHash hash = trh_Create();
  uint32_t values[] = {5, 2, 1, 3, 7, 4, 11, 34};
  for(size_t i = 0, c = sizeof(values) / sizeof(uint32_t); i < c; i++) {
    trh_Buffer_AddToIndex(hash, i, &values[i], sizeof(uint32_t));
  }
  Vector response = trh_GetValues(hash, sizeof(uint32_t));
  uint32_t *vecValues = response->buffer;
  assert_true(response->size == sizeof(values) / sizeof(uint32_t));
  for(size_t i = 0, c = response->size; i < c; i++) {
    assert_true(vecValues[i] == values[i]);
  }
  vct_Delete(response);
  trh_Delete(hash);
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
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}