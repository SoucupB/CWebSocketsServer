#include <stdio.h>
#include <stdint.h>

int main() {
  uint8_t bytes[] = {1, 2, 3, 4, 5, 6, 7, 8};
  uint64_t *plm = bytes;
  printf("%ld\n", *plm);
}