#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include "SocketServer.h"

static void test_connect_to_server(void **state) {

}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_connect_to_server),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}