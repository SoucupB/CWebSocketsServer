#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "HttpParser.h"
#include <stdlib.h>

static void test_http_parser_full_http_body(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
User-Agent: PostmanRuntime/7.37.3\r\n\
Accept: */*\r\n\
Postman-Token: 4415f19a-a8bf-4577-affa-84bed769a538\r\n\
Host: space_bots_instance_1.api.com\r\n\
Accept-Encoding: gzip, deflate, br\r\n\
Connection: keep-alive\r\n\
Content-Length: 0\r\n\
\r\n\
";
  PHttp httpObj = http_Parse(request, strlen(request));
  assert_non_null(httpObj);
  assert_string_equal(httpObj->url->httpType, "HTTP/1.1");
  assert_true(httpObj->url->path.sz == 8);
  assert_memory_equal(httpObj->url->path.buffer, "/connect", httpObj->url->path.sz);
  assert_memory_equal(http_GetValue(httpObj, "Postman-Token"), "4415f19a-a8bf-4577-affa-84bed769a538", sizeof("4415f19a-a8bf-4577-affa-84bed769a538") - 1);
  assert_memory_equal(http_GetValue(httpObj, "User-Agent"), "PostmanRuntime/7.37.3", sizeof("PostmanRuntime/7.37.3") - 1);
  assert_memory_equal(http_GetValue(httpObj, "Host"), "space_bots_instance_1.api.com", sizeof("space_bots_instance_1.api.com") - 1);
  assert_memory_equal(http_GetValue(httpObj, "Content-Length"), "0", sizeof("0") - 1);
  assert_memory_equal(http_GetValue(httpObj, "Connection"), "keep-alive", sizeof("keep-alive") - 1);
  assert_null(http_GetValue(httpObj, "Some-missing-key"));
  http_Delete(httpObj);
}

static void test_http_parser_missing_ending_string(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
User-Agent: PostmanRuntime/7.37.3\r\n\
Accept: */*\r\n\
Postman-Token: 4415f19a-a8bf-4577-affa-84bed769a538\r\n\
Host: space_bots_instance_1.api.com\r\n\
Accept-Encoding: gzip, deflate, br\r\n\
Connection: keep-alive\r\n\
Content-Length: 0\r\n\
";
  PHttp httpObj = http_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_missing_no_headers(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
\r\n\
";
  PHttp httpObj = http_Parse(request, strlen(request));
  assert_non_null(httpObj);
  http_Delete(httpObj);
}

static void test_http_parser_missing_ilegal_values(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
User-Agent: PostmanRuntime/7.37.3\r\n\
Accept: */*\r\n\
Postman-Token: 4415f19a-a8bf-4577-affa-84bed769a538\r\n\
Host: space_bots_instance_1.api.com\r\n\
Accept-Encoding: gzip, deflat:e, br\r\n\
Connection: keep-alive\r\n\
Content-Length: 0\r\n\
\r\n\
";
  PHttp httpObj = http_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_missing_ilegal_keys(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
User-Agen:t: PostmanRuntime/7.37.3\r\n\
Accept: */*\r\n\
Postman-Token: 4415f19a-a8bf-4577-affa-84bed769a538\r\n\
Host: space_bots_instance_1.api.com\r\n\
Accept-Encoding: gzip, deflate, br\r\n\
Connection: keep-alive\r\n\
Content-Length: 0\r\n\
\r\n\
";
  PHttp httpObj = http_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_missing_ilegal_path_chars(void **state) {
  char *request = "\
GET /connect: HTTP/1.1\r\n\
\r\n\
";
  PHttp httpObj = http_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_missing_missing_space(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Content-Type:application/json\r\n\
\r\n\
";
  PHttp httpObj = http_Parse(request, strlen(request));
  assert_non_null(httpObj);
  assert_memory_equal(http_GetValue(httpObj, "Content-Type"), "application/json", sizeof("application/json") - 1);
  http_Delete(httpObj);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_http_parser_full_http_body),
    cmocka_unit_test(test_http_parser_missing_ending_string),
    cmocka_unit_test(test_http_parser_missing_no_headers),
    cmocka_unit_test(test_http_parser_missing_ilegal_values),
    cmocka_unit_test(test_http_parser_missing_ilegal_keys),
    cmocka_unit_test(test_http_parser_missing_ilegal_path_chars),
    cmocka_unit_test(test_http_parser_missing_missing_space),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}