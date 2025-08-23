#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "HttpParser.h"
#include <stdlib.h>

static void test_http_parser_header(void **state) {
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
  http_Delete(httpObj);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_http_parser_header),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}