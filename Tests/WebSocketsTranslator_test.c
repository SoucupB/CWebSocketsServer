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

static void test_websockets_message_validity_single_message_valid(void **state) {
  char *buffer = test_Util_RepeatMessage("abcdefgh", sizeof("abcdefgh") - 1, 1);
  WebSocketObject drr = test_Util_Transform(buffer, sizeof("abcdefgh") - 1);
  char *bff = wbs_ToWebSocket(drr);
  assert_true(wbs_IsBufferValid(bff, wbs_FullMessageSize(bff)));
  test_Util_Delete(drr);
  free(bff);
  free(buffer);
}

static void test_websockets_message_validity_single_message_invalid_overflow(void **state) {
  char *buffer = test_Util_RepeatMessage("abcdefgh", sizeof("abcdefgh") - 1, 1);
  WebSocketObject drr = test_Util_Transform(buffer, sizeof("abcdefgh") - 1);
  char *bff = wbs_ToWebSocket(drr);
  assert_false(wbs_IsBufferValid(bff, wbs_FullMessageSize(bff) + 1));
  test_Util_Delete(drr);
  free(bff);
  free(buffer);
}

static void test_websockets_message_validity_single_message_invalid_underflow(void **state) {
  char *buffer = test_Util_RepeatMessage("abcdefgh", sizeof("abcdefgh") - 1, 1);
  WebSocketObject drr = test_Util_Transform(buffer, sizeof("abcdefgh") - 1);
  char *bff = wbs_ToWebSocket(drr);
  assert_false(wbs_IsBufferValid(bff, wbs_FullMessageSize(bff) - 1));
  test_Util_Delete(drr);
  free(bff);
  free(buffer);
}

static void test_websockets_message_validity_multiple_message_valid(void **state) {
  char *messages[] = {
    "some_message",
    "next_message",
    "last_message"
  };
  char *mergedMessages = test_Util_CreateMessages(messages, sizeof(messages) / sizeof(char *));
  assert_true(wbs_IsBufferValid(mergedMessages, strlen(mergedMessages)));
  free(mergedMessages);
}

static void test_websockets_message_validity_multiple_message_invalid_underflow_10(void **state) {
  char *messages[] = {
    "some_message",
    "next_message",
    "last_message"
  };
  char *mergedMessages = test_Util_CreateMessages(messages, sizeof(messages) / sizeof(char *));
  assert_false(wbs_IsBufferValid(mergedMessages, strlen(mergedMessages) - 10));
  free(mergedMessages);
}

static void test_websockets_message_validity_multiple_message_invalid_underflow_2(void **state) {
  char *messages[] = {
    "some_message",
    "next_message",
    "last_message"
  };
  char *mergedMessages = test_Util_CreateMessages(messages, sizeof(messages) / sizeof(char *));
  assert_false(wbs_IsBufferValid(mergedMessages, strlen(mergedMessages) - 2));
  free(mergedMessages);
}

static void test_websockets_message_split_messages_non_masked(void **state) {
  char *messages[] = {
    "some_message",
    "next_message",
    "last_message"
  };
  char *mergedMessages = test_Util_CreateMessages(messages, sizeof(messages) / sizeof(char *));
  Vector wbsMessages = wbs_FromWebSocket(mergedMessages, strlen(mergedMessages));
  assert_true(wbsMessages->size == 3);
  wbs_Clear_FromWebSocket(wbsMessages);
  free(mergedMessages);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_websockets_payload_size_small),
    cmocka_unit_test(test_websockets_payload_size_medium),
    cmocka_unit_test(test_websockets_payload_size_big),
    cmocka_unit_test(test_websockets_message_validity_single_message_valid),
    cmocka_unit_test(test_websockets_message_validity_single_message_invalid_overflow),
    cmocka_unit_test(test_websockets_message_validity_single_message_invalid_underflow),
    cmocka_unit_test(test_websockets_message_validity_multiple_message_valid),
    cmocka_unit_test(test_websockets_message_validity_multiple_message_invalid_underflow_10),
    cmocka_unit_test(test_websockets_message_validity_multiple_message_invalid_underflow_2),
    cmocka_unit_test(test_websockets_message_split_messages_non_masked),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}