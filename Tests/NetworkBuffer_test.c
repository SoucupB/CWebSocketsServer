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
#include "NetworkBuffer_Helper_test.h"

#define BUFFER_SIZE(x) (sizeof(x) / sizeof(x[0]))

static void test_network_buffer_create(void **state) {
  PNetworkBuffer buffer = tpd_Create(1024);
  assert_ptr_not_equal(buffer, NULL);
  tpd_Delete(buffer);
}

static void test_network_buffer_insert(void **state) {
  PNetworkBuffer buffer = tpd_Create(1024);
  uint32_t someNumbers[] = {1, 2, 3, 4, 5, 6, 7};
  tpd_Push(buffer, someNumbers, sizeof(someNumbers));
  assert_int_equal(tpd_Size(buffer), sizeof(someNumbers));
  assert_memory_equal(tpd_StartingBuffer(buffer), someNumbers, sizeof(someNumbers));
  tpd_Delete(buffer);
}

static void test_network_buffer_overflow(void **state) {
  PNetworkBuffer buffer = tpd_Create(1024 * 10);
  uint32_t someNumbers[1024];
  memset(someNumbers, 1, sizeof(someNumbers));
  tpd_Push(buffer, someNumbers, sizeof(someNumbers));
  assert_int_equal(tpd_Size(buffer), sizeof(someNumbers));
  assert_memory_equal(tpd_StartingBuffer(buffer), someNumbers, sizeof(someNumbers));
  tpd_Delete(buffer);
}

static void test_network_buffer_retract(void **state) {
  PNetworkBuffer buffer = tpd_Create(1024);
  uint32_t someNumbers[] = {1, 2, 3, 4, 5, 6, 7};
  uint32_t expectedBuffer[] = {5, 6, 7};
  tpd_Push(buffer, someNumbers, sizeof(someNumbers));
  tpd_Retract(buffer, 4 * sizeof(uint32_t));
  assert_int_equal(tpd_Size(buffer), sizeof(expectedBuffer));
  assert_memory_equal(tpd_StartingBuffer(buffer), expectedBuffer, sizeof(expectedBuffer));
  tpd_Delete(buffer);
}

static void test_network_buffer_with_overflow(void **state) {
  const size_t bffSize = 1024 * 1024;
  const size_t bufferSize = sizeof(uint32_t) * bffSize;
  PNetworkBuffer buffer = tpd_Create(bufferSize + 1);
  uint32_t *someNumbers = malloc(bufferSize);
  test_Helper_Fill(someNumbers, bffSize);

  tpd_Push(buffer, someNumbers, bufferSize);
  assert_int_equal(tpd_Size(buffer), bufferSize);
  for(size_t i = 0; i < bffSize - 1ULL; i++) {
    tpd_Retract(buffer, sizeof(uint32_t));
  }
  uint32_t expectedLastNumber = bffSize - 1;
  assert_int_equal(tpd_Size(buffer), sizeof(uint32_t));
  assert_memory_equal(tpd_StartingBuffer(buffer), &expectedLastNumber, sizeof(uint32_t));
  tpd_Delete(buffer);
  free(someNumbers);
}

static void test_network_buffer_retract_overflow(void **state) {
  PNetworkBuffer buffer = tpd_Create(10000);
  const size_t bffSize = 1250;
  const size_t bufferSize = sizeof(uint32_t) * bffSize;
  uint32_t *someNumbers = malloc(bufferSize);
  test_Helper_Fill(someNumbers, bffSize);

  tpd_Push(buffer, someNumbers, bufferSize);
  assert_int_equal(tpd_Size(buffer), bufferSize);
  tpd_Retract(buffer, bufferSize + 1000);
  assert_int_equal(tpd_Size(buffer), 0);
  tpd_Delete(buffer);
  free(someNumbers);
}

static void test_network_buffer_retract_special_case(void **state) {
  PNetworkBuffer buffer = tpd_Create(10000);
  uint8_t buff[14];
  uint8_t newBuffer[5];
  uint8_t expected[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  memset(buff, 1, sizeof(buff));
  memset(newBuffer, 2, sizeof(newBuffer));
  tpd_Push(buffer, buff, sizeof(buff));
  tpd_Retract(buffer, 6);
  tpd_Push(buffer, newBuffer, sizeof(newBuffer));
  assert_int_equal(tpd_Size(buffer), sizeof(expected));
  assert_memory_equal(tpd_StartingBuffer(buffer), expected, sizeof(expected));
  tpd_Delete(buffer);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_network_buffer_create, NULL),
    cmocka_unit_test_prestate(test_network_buffer_insert, NULL),
    cmocka_unit_test_prestate(test_network_buffer_overflow, NULL),
    cmocka_unit_test_prestate(test_network_buffer_retract, NULL),
    cmocka_unit_test_prestate(test_network_buffer_with_overflow, NULL),
    cmocka_unit_test_prestate(test_network_buffer_retract_overflow, NULL),
    cmocka_unit_test_prestate(test_network_buffer_retract_special_case, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}