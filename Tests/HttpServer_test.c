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

static void test_http_server_parse_request(void **state) {
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
  PHttpRequest req = http_Request_Parse(request, strlen(request));
  HttpString str = http_Request_ToString(req);
  assert_ptr_not_equal(str.buffer, NULL);
  HttpString path = http_Request_GetPath(req);
  HttpString key = http_Request_GetValue(req, "User-Agent");
  HttpString body = http_Request_GetBody(req);
  assert_int_equal(path.sz, sizeof("/connect") - 1);
  assert_memory_equal(path.buffer, "/connect", path.sz);
  assert_int_equal(key.sz, sizeof("PostmanRuntime/7.37.3") - 1);
  assert_memory_equal(key.buffer, "PostmanRuntime/7.37.3", key.sz);
  assert_int_equal(body.sz, sizeof("abcd") - 1);
  assert_memory_equal(body.buffer, "abcd", body.sz);
  http_Request_Delete(req);
  free(str.buffer);
}

static void test_http_server_request_response(void **state) {
  
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_http_server_creation, NULL),
    cmocka_unit_test_prestate(test_http_server_push_method, NULL),
    cmocka_unit_test_prestate(test_http_server_parse_request, NULL),
    cmocka_unit_test_prestate(test_http_server_request_response, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}