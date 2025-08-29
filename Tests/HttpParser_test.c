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
POST /connect HTTP/1.1\r\n\
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
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_non_null(httpObj);
  assert_string_equal(httpObj->url->httpType, "HTTP/1.1");
  assert_true(httpObj->url->path.sz == 8);
  assert_memory_equal(httpObj->url->path.buffer, "/connect", httpObj->url->path.sz);
  assert_true(httpObj->url->method == POST);
  assert_memory_equal(http_Request_GetValue(httpObj, "Postman-Token").buffer, "4415f19a-a8bf-4577-affa-84bed769a538", sizeof("4415f19a-a8bf-4577-affa-84bed769a538") - 1);
  assert_memory_equal(http_Request_GetValue(httpObj, "User-Agent").buffer, "PostmanRuntime/7.37.3", sizeof("PostmanRuntime/7.37.3") - 1);
  assert_memory_equal(http_Request_GetValue(httpObj, "Host").buffer, "space_bots_instance_1.api.com", sizeof("space_bots_instance_1.api.com") - 1);
  assert_memory_equal(http_Request_GetValue(httpObj, "Content-Length").buffer, "0", sizeof("0") - 1);
  assert_memory_equal(http_Request_GetValue(httpObj, "Connection").buffer, "keep-alive", sizeof("keep-alive") - 1);
  assert_null(http_Request_GetValue(httpObj, "Some-missing-key").buffer);

  assert_true(http_Request_GetValue(httpObj, "Postman-Token").sz == sizeof("4415f19a-a8bf-4577-affa-84bed769a538") - 1);
  assert_true(http_Request_GetValue(httpObj, "User-Agent").sz == sizeof("PostmanRuntime/7.37.3") - 1);
  assert_true(http_Request_GetValue(httpObj, "Host").sz == sizeof("space_bots_instance_1.api.com") - 1);
  assert_true(http_Request_GetValue(httpObj, "Content-Length").sz == sizeof("0") - 1);
  assert_true(http_Request_GetValue(httpObj, "Connection").sz == sizeof("keep-alive") - 1);
  assert_true(http_Request_GetValue(httpObj, "Some-missing-key").sz == 0);
  http_Request_Delete(httpObj);
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
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_missing_no_headers(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
\r\n\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_non_null(httpObj);
  http_Request_Delete(httpObj);
}

static void test_http_parser_postman_requests(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6MSwiaWF0IjoxNzU1MjY2MDM0LCJleHAiOjE3NTUyNzMyMzR9.2tBZhjQ6VVFnkwV9ubO4gbmY9Mmmt-FzBRWCRERJ1ss\r\n\
User-Agent: PostmanRuntime/7.37.3\r\n\
Accept: */*\r\n\
Postman-Token: 5a5c413c-6676-4c67-96e0-d00ea870a010\r\n\
Host: 127.0.0.1:8080\r\n\
Accept-Encoding: gzip, deflate, br\r\n\
Connection: keep-alive\r\n\
\r\n\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_non_null(httpObj);
  http_Request_Delete(httpObj);
}

static void test_http_parser_missing_ilegal_values(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
User-Agent: PostmanRuntime/7.37.3\r\n\
Accept: */*\r\n\
Postman-Token: 4415f19a-a8bf-4577-affa-84bed769a538\r\n\
Host: space_bots_instance_1.api.com\r\n\
Accept-Encoding: gzip, deflat\x08e, br\r\n\
Connection: keep-alive\r\n\
Content-Length: 0\r\n\
\r\n\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_missing_ilegal_path_chars(void **state) {
  char *request = "\
GET /connect: HTTP/1.1\r\n\
\r\n\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_missing_space(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Content-Type:application/json\r\n\
\r\n\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_non_null(httpObj);
  assert_memory_equal(http_Request_GetValue(httpObj, "Content-Type").buffer, "application/json", sizeof("application/json") - 1);
  http_Request_Delete(httpObj);
}

static void test_http_parser_unknown_method(void **state) {
  char *request = "\
TEST /connect HTTP/1.1\r\n\
Content-Type:application/json\r\n\
\r\n\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_non_writable_bytes_in_value(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Content-Type:applicati\x03on/json\r\n\
\r\n\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_non_writable_bytes_in_key(void **state) {
  char *request = "\
GET /connect HTTP/1.1\r\n\
Content-Ty\x03pe:application/json\r\n\
\r\n\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_too_big_type(void **state) {
  char *request = "\
GET /connect HTTP/1.132324252\r\n\
Content-Type:application/json\r\n\
\r\n\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_body_present(void **state) {
  char *request = "\
POST /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
Content-Length: 3\r\n\
\r\n\
abc\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_non_null(httpObj);
  assert_memory_equal(httpObj->body->buffer, "abc", sizeof("abc") - 1);
  http_Request_Delete(httpObj);
}

static void test_http_parser_body_invalid_underflow(void **state) {
  char *request = "\
POST /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
Content-Length: 2\r\n\
\r\n\
abc\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_body_invalid_missing_newline(void **state) {
  char *request = "\
POST /connect HTTP/1.1\r\n\
Content-Type: application/json\r\
Content-Length: 3\r\n\
\r\n\
abc\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_body_invalid_missing_content_length(void **state) {
  char *request = "\
POST /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
\r\n\
abc\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_body_invalid_overlow(void **state) {
  char *request = "\
POST /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
Content-Length: 4\r\n\
\r\n\
abc\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_parser_body_without_length(void **state) {
  char *request = "\
POST /connect HTTP/1.1\r\n\
Content-Type: application/json\r\n\
\r\n\
abc\
";
  PHttpRequest httpObj = http_Request_Parse(request, strlen(request));
  assert_null(httpObj);
}

static void test_http_response_to_string(void **state) {
  PHttpResponse response = http_Response_Create();
  response->httpCode = "HTTP/1.1";
  response->response = 200;
  HttpString body = {
    .buffer = "Hello, World!",
    .sz = sizeof("Hello, World!") - 1
  };
  http_Response_SetBody(response, &body);
  HttpString responseStr = http_Response_ToString(response);
  const char *expectedResponse = "\
HTTP/1.1 200\r\n\
Connection: close\r\n\
Content-Length: 13\r\n\
Content-Type: text/plain\r\n\
\r\n\
Hello, World!";
  assert_true(responseStr.sz == strlen(expectedResponse));
  assert_memory_equal(responseStr.buffer, expectedResponse, responseStr.sz);
  
  free(responseStr.buffer);
  http_Response_Delete(response);
}

static void test_http_response_to_small_string_reject(void **state) {
  PHttpResponse response = http_Response_Create();
  response->httpCode = "HTTP/1.1";
  response->response = 400;
  HttpString body = {
    .buffer = "Hello",
    .sz = sizeof("Hello") - 1
  };
  http_Response_SetBody(response, &body);
  HttpString responseStr = http_Response_ToString(response);
  const char *expectedResponse = "\
HTTP/1.1 400\r\n\
Connection: close\r\n\
Content-Length: 5\r\n\
Content-Type: text/plain\r\n\
\r\n\
Hello";
  assert_true(responseStr.sz == strlen(expectedResponse));
  assert_memory_equal(responseStr.buffer, expectedResponse, responseStr.sz);
  
  free(responseStr.buffer);
  http_Response_Delete(response);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_http_parser_full_http_body),
    cmocka_unit_test(test_http_parser_missing_ending_string),
    cmocka_unit_test(test_http_parser_missing_no_headers),
    cmocka_unit_test(test_http_parser_missing_ilegal_values),
    cmocka_unit_test(test_http_parser_missing_ilegal_path_chars),
    cmocka_unit_test(test_http_parser_missing_space),
    cmocka_unit_test(test_http_parser_body_invalid_missing_newline),
    cmocka_unit_test(test_http_parser_body_invalid_missing_content_length),
    cmocka_unit_test(test_http_parser_unknown_method),
    cmocka_unit_test(test_http_parser_non_writable_bytes_in_value),
    cmocka_unit_test(test_http_parser_non_writable_bytes_in_key),
    cmocka_unit_test(test_http_parser_too_big_type),
    cmocka_unit_test(test_http_parser_body_present),
    cmocka_unit_test(test_http_parser_body_invalid_underflow),
    cmocka_unit_test(test_http_parser_body_invalid_overlow),
    cmocka_unit_test(test_http_parser_body_without_length),
    cmocka_unit_test(test_http_response_to_string),
    cmocka_unit_test(test_http_response_to_small_string_reject),
    cmocka_unit_test(test_http_parser_postman_requests),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}