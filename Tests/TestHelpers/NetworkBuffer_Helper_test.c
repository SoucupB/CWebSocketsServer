#include "NetworkBuffer_Helper_test.h"

void test_Helper_Fill(uint32_t *buffer, size_t size) {
  for(size_t i = 0; i < size; i++) {
    buffer[i] = i;
  }
}