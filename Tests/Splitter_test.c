#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include <stdio.h>
#include <stdint.h>
#include "Splitter.h"
#include <unistd.h>
#include <string.h>

static void test_splitter_single_characters_test(void **state) {
  char *buffer = "This is some sentence";
  char *lines[] = {
    "This",
    "is",
    "some",
    "sentence"
  };
  Splitter splitter = split(buffer, strlen(buffer), " ", 1);
  assert_true(splitter.lines->size == sizeof(lines) / sizeof(lines[0]));
  for(size_t i = 0; i < splitter.lines->size; i++) {
    assert_true(strcmp(splitter_GetLine(splitter, i), lines[i]) == 0);
  }
  splitter_Free(splitter);
}

static void test_splitter_multiple_characters_test(void **state) {
  char *buffer = "This$$@is$$@some$$@sentence";
  char *lines[] = {
    "This",
    "is",
    "some",
    "sentence"
  };
  Splitter splitter = split(buffer, strlen(buffer), "$$@", 3);
  assert_true(splitter.lines->size == sizeof(lines) / sizeof(lines[0]));
  for(size_t i = 0; i < splitter.lines->size; i++) {
    assert_true(strcmp(splitter_GetLine(splitter, i), lines[i]) == 0);
  }
  splitter_Free(splitter);
}

static void test_splitter_no_characters_test(void **state) {
  char *buffer = "This$$@is$$@some$$@sentence";
  char *lines[] = {
    "This$$@is$$@some$$@sentence",
  };
  Splitter splitter = split(buffer, strlen(buffer), "TTE", 3);
  assert_true(splitter.lines->size == sizeof(lines) / sizeof(lines[0]));
  for(size_t i = 0; i < splitter.lines->size; i++) {
    assert_true(strcmp(splitter_GetLine(splitter, i), lines[i]) == 0);
  }
  splitter_Free(splitter);
}

static void test_splitter_splitters_neighbours_test(void **state) {
  char *buffer = "This$$is$$some$$sentence";
  char *lines[] = {
    "This",
    "",
    "is",
    "",
    "some",
    "",
    "sentence"
  };
  Splitter splitter = split(buffer, strlen(buffer), "$", 1);
  assert_true(splitter.lines->size == sizeof(lines) / sizeof(lines[0]));
  for(size_t i = 0; i < splitter.lines->size; i++) {
    assert_true(strcmp(splitter_GetLine(splitter, i), lines[i]) == 0);
  }
  splitter_Free(splitter);
}

static void test_splitter_empty_string_test(void **state) {
  char *buffer = "";
  Splitter splitter = split(buffer, strlen(buffer), "$", 1);
  assert_true(splitter.lines->size == 0);
  splitter_Free(splitter);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_splitter_single_characters_test, NULL),
    cmocka_unit_test_prestate(test_splitter_multiple_characters_test, NULL),
    cmocka_unit_test_prestate(test_splitter_no_characters_test, NULL),
    cmocka_unit_test_prestate(test_splitter_splitters_neighbours_test, NULL),
    cmocka_unit_test_prestate(test_splitter_empty_string_test, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}