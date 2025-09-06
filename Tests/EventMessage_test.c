#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "EventMessage.h"
#include <stdlib.h>

EventMessage eventDefaultNonAuth() {
  return (EventMessage) {
    .headerCode = 157,
    .isAuthed = 0,
    .str = (EventBuffer) {
      .buffer = "some_test_message",
      .size = sizeof("some_test_message") - 1
    }
  };
}

static void test_event_message_create_non_authed(void **state) {
  EventMessage regularMessage = eventDefaultNonAuth();
  EventBuffer msg = evm_New_Transform(&regularMessage);
  assert_non_null(msg.buffer);
  free(msg.buffer);
}

static void test_event_message_create_non_authed_check_data(void **state) {
  EventMessage regularMessage = eventDefaultNonAuth();
  EventBuffer msg = evm_New_Transform(&regularMessage);
  assert_non_null(msg.buffer);
  uint8_t valid = 0;
  EventMessage response = evm_Parse(msg, &valid);
  assert_true(valid);
  assert_true(response.headerCode == 157);
  assert_true(response.isAuthed == 0);
  assert_true(response.str.size == sizeof("some_test_message") - 1);
  assert_memory_equal(response.str.buffer, "some_test_message", response.str.size);
  free(msg.buffer);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_event_message_create_non_authed),
    cmocka_unit_test(test_event_message_create_non_authed_check_data),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}