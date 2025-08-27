#include "TrieHash_Helper_test.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

size_t test_Util_RandomElement() {
  char buffer[sizeof(size_t)];
  for(size_t i = 0, c = sizeof(size_t); i < c; i++) {
    buffer[i] = (rand() & 255);
  }

  return *((size_t *)buffer);
}

size_t *test_Util_CreateBuffer(size_t size) {
  size_t *buffer = malloc(sizeof(size_t) * size);
  for(size_t i = 0; i < size; i++) {
    buffer[i] = test_Util_RandomElement();
  }
  return buffer;
}

int compareIntegers(const void *a, const void *b) {
  size_t int_a = *(const size_t *)a;
  size_t int_b = *(const size_t *)b;
  return (int_a > int_b) - (int_a < int_b); 
}

void test_Util_TestEquivalency(size_t *buffer, size_t *realArray, size_t size) {
  qsort(buffer, size, sizeof(size_t), compareIntegers);
  qsort(realArray, size, sizeof(size_t), compareIntegers);
  for(size_t i = 0; i < size; i++) {
    assert_true(buffer[i] == realArray[i]);
  }
}

int compareStrings(const void *a, const void *b) {
  const char *str_a = *(const char **)a;
  const char *str_b = *(const char **)b;
  return strcmp(str_a, str_b);
}

int compareKeys(const void *a, const void *b) {
  const Key *sa = (const Key *)a;
  const Key *sb = (const Key *)b;
  int cmp = memcmp(sa->key, sb->key, sa->keySize < sb->keySize ? sa->keySize : sb->keySize);
  if (cmp != 0) {
    return cmp;
  }

  if (sa->keySize < sb->keySize) return -1;
  if (sa->keySize > sb->keySize) return 1;
  return 0;
}

void test_Util_TestStringEquivalency(char **buffer, Key *keys, size_t size) {
  qsort(buffer, size, sizeof(char *), compareStrings);
  qsort(keys, size, sizeof(Key), compareKeys);
  for(size_t i = 0; i < size; i++) {
    assert_true(strlen(buffer[i]) == keys[i].keySize);
    assert_true(memcmp(buffer[i], keys[i].key, keys[i].keySize) == 0);
  }
}