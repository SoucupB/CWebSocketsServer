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
#include "HttpParser.h"
#include "HttpServer_Helper_test.h"

#define EPSILON 1e-5f

uint16_t port = 10000;

static void test_http_server_creation(void **state) {
  const uint16_t cPort = port--;
  PHttpServer server = httpS_Create(cPort);
  assert_ptr_not_equal(server, NULL);
  httpS_Delete(server);
}

static void test_http_server_push_method(void **state) {
  const uint16_t cPort = port--;
  PHttpServer server = httpS_Create(cPort);
  http_Helper_AddMethod(server, /*default*/NULL);
  http_Helper_Free(server);
}

static void test_http_server_test_response(void **state) {
  const uint16_t cPort = port--;
  char *request = "\
POST /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
User-Agent: PostmanRuntime/7.37.3\r\n\
Accept: */*\r\n\
Postman-Token: 4415f19a-a8bf-4577-affa-84bed769a538\r\n\
Host: space_bots_instance_1.api.com\r\n\
Accept-Encoding: gzip, deflate, br\r\n\
Connection: keep-alive\r\n\
Content-Length: 4\r\n\
\r\n\
abcd\
";
  // PHttpServer server = httpS_Create(cPort);
  // http_Helper_AddMethod(server, /*default*/NULL);
  // http_Helper_Free(server);
  PHttpRequest req = http_Request_Parse(request, strlen(request));
  HttpString str = http_Request_ToString(req);
  // for(size_t i = 0; i < str.sz; i++) {
  //   if(str.buffer[i] == '\r') {
  //     printf("\\r");
  //   }
  //   else if(str.buffer[i] == '\n') {
  //     printf("\\n\n");
  //   } else {
  //     printf("%c", str.buffer[i]);
  //   }
  // }
  // printf("\n");

  // printf("%d %.*s\n", str.sz, str.sz, str.buffer);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_http_server_creation, NULL),
    cmocka_unit_test_prestate(test_http_server_push_method, NULL),
    cmocka_unit_test_prestate(test_http_server_test_response, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}