#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "EventMessage.h"
#include <stdlib.h>

static void test_event_message_non_authed_parse(void **state) {
  EventMessage regularMessage = {
    .headerCode = 157,
    .isAuthed = 0,
    .str = (EventBuffer) {
      .buffer = "some_test_message",
      .size = sizeof("some_test_message")
    }
  };
  EventBuffer msg = evm_New_Transform(&regularMessage);
  assert_non_null(msg.buffer);
  free(msg.buffer);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_event_message_non_authed_parse),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}