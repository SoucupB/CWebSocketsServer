#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include <stdio.h>
#include <stdint.h>
#include "FixedMemoryPool.h"
#include <unistd.h>
#include <string.h>

static void test_fixed_memory_alloc(void **state) {
  PFixedMemoryPool memory = fmp_Init(sizeof(uint32_t), 10);
  fmp_Delete(memory);
}
int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_fixed_memory_alloc, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}