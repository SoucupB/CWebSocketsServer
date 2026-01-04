#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include "Array.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "Structs.h"
#include "NetworkBuffer.h"

#define BUFFER_SIZE(x) (sizeof(x) / sizeof(x[0]))

static void test_network_buffer_create(void **state) {
  PNetworkBuffer buffer = tpd_Create(1024);
  assert_ptr_not_equal(buffer, NULL);
  tpd_Delete(buffer);
}

static void test_network_buffer_insert(void **state) {
  PNetworkBuffer buffer = tpd_Create(1024);
  uint32_t someNumbers[] = {1, 2, 3, 4, 5, 6, 7};
  tpd_Push(buffer, someNumbers, BUFFER_SIZE(someNumbers));
  assert_int_equal(tpd_Size(buffer), BUFFER_SIZE(someNumbers));
  assert_memory_equal(tpd_StartingBuffer(buffer), someNumbers, BUFFER_SIZE(someNumbers));
  tpd_Delete(buffer);
}

static void test_network_buffer_overflow(void **state) {
  PNetworkBuffer buffer = tpd_Create(1024);
  uint32_t someNumbers[] = {1, 2, 3, 4, 5, 6, 7};
  tpd_Push(buffer, someNumbers, BUFFER_SIZE(someNumbers));
  assert_int_equal(tpd_Size(buffer), BUFFER_SIZE(someNumbers));
  assert_memory_equal(tpd_StartingBuffer(buffer), someNumbers, BUFFER_SIZE(someNumbers));
  tpd_Delete(buffer);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_network_buffer_create, NULL),
    cmocka_unit_test_prestate(test_network_buffer_insert, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}