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

static void test_network_buffer_create(void **state) {
  PNetworkBuffer buffer = tpd_Create(1024);
  assert_ptr_not_equal(buffer, NULL);
  tpd_Delete(buffer);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_network_buffer_create, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}