#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include "Vector.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "HttpServer.h"
#include "Structs.h"
#include "JWT.h"
#include "JsonParser.h"
#include "TimeFragment.h"

#define EPSILON 1e-5f

static void test_http_server_creation(void **state) {
  PHttpServer server = httpS_Create(8080);
  assert_ptr_not_equal(server, NULL);
  httpS_Delete(server);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_http_server_creation, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}