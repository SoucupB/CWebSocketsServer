#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "WebSocketsTranslator.h"

static void test_connect_to_server_with_single_client(void **state) {
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_connect_to_server_with_single_client),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}