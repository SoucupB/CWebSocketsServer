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
#include "HttpServer_Helper_test.h"

#define EPSILON 1e-5f

uint16_t port = 10000;

static void test_http_server_creation(void **state) {
  const uint16_t cPort = port--;
  PHttpServer server = httpS_Create(cPort);
  assert_ptr_not_equal(server, NULL);
  httpS_Delete(server);
}

static void test_http_server_push_server(void **state) {
  const uint16_t cPort = port--;
  PHttpServer server = httpS_Create(cPort);
  http_Helper_AddMethod(server, /*default*/NULL);
  http_Helper_Free(server);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_http_server_creation, NULL),
    cmocka_unit_test_prestate(test_http_server_push_server, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}