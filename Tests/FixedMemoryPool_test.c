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
  PFixedMemoryPool memory = fmp_InitWithCapacity(sizeof(uint32_t), 10);
  uint32_t *element = fmp_Alloc(memory);
  *element = 43;
  assert_true(*element == 43 && memory->count == 1);
  fmp_Delete(memory);
}

static void test_fixed_memory_alloc_single_element_free(void **state) {
  PFixedMemoryPool memory = fmp_InitWithCapacity(sizeof(uint32_t), 10);
  uint32_t *element = fmp_Alloc(memory);
  *element = 111;
  fmp_Free(memory, element);
  assert_true(memory->count == 0);
  fmp_Delete(memory);
}

static void test_fixed_memory_alloc_single_element_realloc(void **state) {
  PFixedMemoryPool memory = fmp_InitWithCapacity(sizeof(uint32_t), 10);
  uint32_t *element = fmp_Alloc(memory);
  *element = 111;
  fmp_Free(memory, element);
  assert_true(fmp_Alloc(memory) == element);
  fmp_Delete(memory);
}

static void test_fixed_memory_alloc_stack_order_allocations(void **state) {
  PFixedMemoryPool memory = fmp_InitWithCapacity(sizeof(uint32_t), 10);
  uint32_t *element[5];
  for(size_t i = 0; i < sizeof(element) / sizeof(uint32_t *); i++) {
    element[i] = fmp_Alloc(memory);
  }
  for(ssize_t i = sizeof(element) / sizeof(uint32_t *) - 1; i >= 0; i--) {
    fmp_Free(memory, element[i]);
  }
  for(size_t i = 0; i < sizeof(element) / sizeof(uint32_t *); i++) {
    assert_true(fmp_Alloc(memory) == element[i]);
  }
  fmp_Delete(memory);
}

static void test_fixed_memory_alloc_stack_order_allocations_over_multiple_pools(void **state) {
  PFixedMemoryPool memory = fmp_InitWithCapacity(sizeof(uint32_t), 1);
  uint32_t *element[50000];
  for(size_t i = 0; i < sizeof(element) / sizeof(uint32_t *); i++) {
    element[i] = fmp_Alloc(memory);
  }
  for(ssize_t i = sizeof(element) / sizeof(uint32_t *) - 1; i >= 0; i--) {
    fmp_Free(memory, element[i]);
  }
  for(size_t i = 0; i < sizeof(element) / sizeof(uint32_t *); i++) {
    assert_true(fmp_Alloc(memory) == element[i]);
  }
  fmp_Delete(memory);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_fixed_memory_alloc_single_element, NULL),
    cmocka_unit_test_prestate(test_fixed_memory_alloc_single_element_free, NULL),
    cmocka_unit_test_prestate(test_fixed_memory_alloc_single_element_realloc, NULL),
    cmocka_unit_test_prestate(test_fixed_memory_alloc_stack_order_allocations, NULL),
    cmocka_unit_test_prestate(test_fixed_memory_alloc_stack_order_allocations_over_multiple_pools, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}