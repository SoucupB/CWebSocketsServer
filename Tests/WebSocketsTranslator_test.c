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
  assert_true(memcmp(wbs_Public_PayloadBuffer(bff), drr.buffer, wbs_Public_PayloadSize(bff)) == 0);
  test_Util_Delete(drr);
  free(bff);
}

static void test_websockets_payload_size_medium(void **state) {
  char *buffer = test_Util_RepeatMessage("ab", sizeof("ab") - 1, 500);
  WebSocketObject drr = test_Util_Transform(buffer, 1000);
  char *bff = wbs_ToWebSocket(drr);
  assert_true(wbs_Public_PayloadSize(bff) == 1000);
  assert_true(wbs_Raw_Public_HeaderSize(bff) == 4);
  assert_true(memcmp(wbs_Public_PayloadBuffer(bff), buffer, wbs_Public_PayloadSize(bff)) == 0);
  test_Util_Delete(drr);
  free(bff);
  free(buffer);
}

static void test_websockets_payload_size_big(void **state) {
  char *buffer = test_Util_RepeatMessage("ab", sizeof("ab") - 1, 100000);
  WebSocketObject drr = test_Util_Transform(buffer, 200000);
  char *bff = wbs_ToWebSocket(drr);
  assert_true(wbs_Public_PayloadSize(bff) == 200000);
  assert_true(wbs_Raw_Public_HeaderSize(bff) == 10);
  assert_true(memcmp(wbs_Public_PayloadBuffer(bff), buffer, wbs_Public_PayloadSize(bff)) == 0);
  test_Util_Delete(drr);
  free(bff);
  free(buffer);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_websockets_payload_size_small),
    cmocka_unit_test(test_websockets_payload_size_medium),
    cmocka_unit_test(test_websockets_payload_size_big),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}