#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "HttpParser.h"
#include <stdlib.h>
#include "NetBufferHelper.h"

#define SIZE(x) (sizeof(x) / sizeof(x[0]))
#define EPSILON 1e-5f

static void test_buffer_push_data(void **state) {
  NetBufferHelperWriter dw = ntb_Writer_Create(1024 * 1024);
  ntb_Write_PushINT8(dw, 5);
  ntb_Write_PushINT16(dw, 6);
  ntb_Write_PushINT32(dw, 7);
  ntb_Write_PushINT64(dw, 8);
  char *currentBuffer = ntb_Write_Buffer(dw);
  NetBufferHelperReader dr = ntb_Reader_Create(currentBuffer, ntb_Write_Size(dw));
  assert_int_equal(ntb_Reader_INT8(&dr), 5);
  assert_int_equal(ntb_Reader_INT16(&dr), 6);
  assert_int_equal(ntb_Reader_INT32(&dr), 7);
  assert_int_equal(ntb_Reader_INT64(&dr), 8);
  assert_true(ntb_Reader_IsComplete(&dr));
  ntb_Writer_Delete(dw);
}

static void test_buffer_invalid_data(void **state) {
  NetBufferHelperWriter dw = ntb_Writer_Create(1024 * 1024);
  ntb_Write_PushINT16(dw, 6);
  char *currentBuffer = ntb_Write_Buffer(dw);
  NetBufferHelperReader dr = ntb_Reader_Create(currentBuffer, ntb_Write_Size(dw));
  assert_int_equal(ntb_Reader_INT32(&dr), 0);
  assert_false(ntb_Reader_IsComplete(&dr));
  ntb_Writer_Delete(dw);
}

static void test_buffer_float_data(void **state) {
  NetBufferHelperWriter dw = ntb_Writer_Create(1024 * 1024);
  for(size_t i = 0; i < 1024 * 128; i++) {
    ntb_Write_PushF32(dw, (float)i);
  }
  char *currentBuffer = ntb_Write_Buffer(dw);
  NetBufferHelperReader dr = ntb_Reader_Create(currentBuffer, ntb_Write_Size(dw));
  for(size_t i = 0; i < 1024 * 128; i++) {
    assert_float_equal(ntb_Reader_FLOAT32(&dr), (float)i, EPSILON);
  }
  assert_true(ntb_Reader_IsComplete(&dr));
  ntb_Writer_Delete(dw);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_buffer_push_data),
    cmocka_unit_test(test_buffer_invalid_data),
    cmocka_unit_test(test_buffer_float_data),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}