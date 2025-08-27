#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include <stdio.h>
#include <stdint.h>
#include "FixedMemoryPool.h"
#include <unistd.h>
#include <string.h>

static void test_fixed_memory_alloc_single_element(void **state) {
  PFixedMemoryPool memory = fmp_Init(sizeof(uint32_t), 10);
  uint32_t *element = fmp_Alloc(memory);
  *element = 43;
  assert_true(*element == 43);
  fmp_Delete(memory);
}

static void test_fixed_memory_alloc_single_element_free(void **state) {
  PFixedMemoryPool memory = fmp_Init(sizeof(uint32_t), 10);
  uint32_t *element = fmp_Alloc(memory);
  *element = 111;
  fmp_Free(memory, element);
  assert_true(memory->count == 0);
  fmp_Delete(memory);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_fixed_memory_alloc_single_element, NULL),
    cmocka_unit_test_prestate(test_fixed_memory_alloc_single_element_free, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}