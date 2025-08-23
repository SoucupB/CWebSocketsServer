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