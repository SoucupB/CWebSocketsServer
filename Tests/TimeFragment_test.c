#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include "TimeFragment.h"
#include <string.h>
#include <stdio.h>

static void test_object_creation(void **state) {
  PTimeServer tm = tf_Create();
  assert_non_null(tm);
  tf_Delete(tm);
}

void methodToExecuteAfter(void *buffer) {
  uint32_t *bff = (uint32_t *)buffer;
  (*bff)++;
}

static void test_execute_after_before_times_runs_out(void **state) {
  PTimeServer tm = tf_Create();
  uint32_t executionCount = 0;
  assert_non_null(tm);
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)methodToExecuteAfter,
    .buffer = &executionCount
  };
  tf_ExecuteAfter(tm, timeFragment, 5000);
  tf_OnFrame(tm, 4999);
  assert_int_equal(executionCount, 0);
  tf_Delete(tm);
}

static void test_execute_after_times_runs_out(void **state) {
  PTimeServer tm = tf_Create();
  uint32_t executionCount = 0;
  assert_non_null(tm);
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)methodToExecuteAfter,
    .buffer = &executionCount
  };
  tf_ExecuteAfter(tm, timeFragment, 5000);
  tf_OnFrame(tm, 5001);
  assert_int_equal(executionCount, 1);
  tf_Delete(tm);
}

static void test_execute_after_single_run(void **state) {
  PTimeServer tm = tf_Create();
  uint32_t executionCount = 0;
  assert_non_null(tm);
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)methodToExecuteAfter,
    .buffer = &executionCount
  };
  tf_ExecuteAfter(tm, timeFragment, 5000);
  for(size_t i = 0; i < 10; i++) {
    tf_OnFrame(tm, 2500);
  }
  assert_int_equal(executionCount, 1);
  tf_Delete(tm);
}

static void test_execute_loop_before_times_runs_out(void **state) {
  PTimeServer tm = tf_Create();
  uint32_t executionCount = 0;
  assert_non_null(tm);
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)methodToExecuteAfter,
    .buffer = &executionCount
  };
  tf_ExecuteLoop(tm, timeFragment, 5000);
  tf_OnFrame(tm, 2500);
  assert_int_equal(executionCount, 0);
  tf_Delete(tm);
}

static void test_execute_loop_after_time_runs_out_multiple_ticks(void **state) {
  PTimeServer tm = tf_Create();
  uint32_t executionCount = 0;
  assert_non_null(tm);
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)methodToExecuteAfter,
    .buffer = &executionCount
  };
  tf_ExecuteLoop(tm, timeFragment, 5000);
  for(size_t i = 0; i < 10; i++) {
    tf_OnFrame(tm, 2500);
  }
  assert_int_equal(executionCount, 5);
  tf_Delete(tm);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_object_creation),
    cmocka_unit_test(test_execute_after_before_times_runs_out),
    cmocka_unit_test(test_execute_after_times_runs_out),
    cmocka_unit_test(test_execute_after_single_run),
    cmocka_unit_test(test_execute_loop_before_times_runs_out),
    cmocka_unit_test(test_execute_loop_after_time_runs_out_multiple_ticks),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}