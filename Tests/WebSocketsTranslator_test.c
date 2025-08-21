#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "WebSocketsTranslator.h"
#include "Websockets_Helper_test.h"
#include <stdlib.h>

static void test_websockets_payload_size_small(void **state) {
  WebSocketObject drr = test_Util_Transform("some super specs", sizeof("some super specs") - 1);
  char *bff = wbs_ToWebSocket(drr);
  assert_true(wbs_Public_PayloadSize(bff) == sizeof("some super specs") - 1);
  assert_true(wbs_Raw_Public_HeaderSize(bff) == 2);
  test_Util_Delete(drr);
  free(bff);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_websockets_payload_size_small),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}