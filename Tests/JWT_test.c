#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include "Array.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "Structs.h"
#include "JWT.h"
#include "JsonParser.h"
#include "TimeFragment.h"

#define EPSILON 1e-5f

void jwt_HMAC(HttpString key, HttpString secret, uint8_t *hmacResult, size_t *currentSize);
HttpString jwt_Encode_t(JsonElement payload, HttpString secret, uint64_t iam, uint64_t expirationMS);
void jwt_PrintHMAC(uint8_t *hmacCode, size_t sz);
uint8_t jwt_DecodeURLEncodedBase64(HttpString str, uint8_t *response, size_t *responseSz);
void jwt_ToBase64UrlEncoded(HttpString str, uint8_t *response, size_t *finalSize);
uint8_t jwt_IsHeaderValid(HttpString str);
uint8_t jwt_IsPayloadValid(HttpString str);
uint8_t jwt_IsJWTCorrectlyFormatted(HttpString str);

static void test_jwt_hmac_create(void **state) {
  HttpString key = {
    .buffer = "some_key_data",
    .sz = sizeof("some_key_data") - 1
  };
  HttpString secret = {
    .buffer = "Hello world!",
    .sz = sizeof("Hello world!") - 1
  };
  uint8_t hmacResult[jwt_Base64_Size_Public(32) + 1];
  jwt_HMAC(key, secret, hmacResult, NULL);
  char *digest = "7VcD4ohA6GDuMdwWeLNrQ81_kE9CJ3HM";
  assert_memory_equal(digest, hmacResult, strlen(digest));
}

static void test_jwt_create_field(void **state) {
  JsonElement mapToSend = json_Map_Create();
  json_Map_Add(mapToSend, "some_field", json_Integer_Create(31314));

  HttpString secret = {
    .buffer = "some_key_data",
    .sz = sizeof("some_key_data") - 1
  };
  uint64_t cTime = 32324255525LL;
  HttpString crm = jwt_Encode_t(mapToSend, secret, cTime, 324LL);
  char *jwt = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjMyMzI0MjU1ODQ5LCJpYXQiOjMyMzI0MjU1NTI1LCJzb21lX2ZpZWxkIjozMTMxNH0.7zOdXbes1bt_8gnBpACpntvUQoVifLj6WsijL8DvrLI";
  assert_memory_equal(jwt, crm.buffer, strlen(jwt));
  json_DeleteElement(mapToSend);
  free(crm.buffer);
}

static void test_jwt_signed_correctly(void **state) {
  JsonElement mapToSend = json_Map_Create();
  json_Map_Add(mapToSend, "some_field", json_Integer_Create(31314));

  HttpString secret = {
    .buffer = "some_key_data",
    .sz = sizeof("some_key_data") - 1
  };
  uint64_t cTime = 32324255525LL;
  HttpString crm = jwt_Encode_t(mapToSend, secret, cTime, cTime);
  assert_true(jwt_IsSigned(crm, secret));
  json_DeleteElement(mapToSend);
  free(crm.buffer);
}

static void test_jwt_invalid_signed(void **state) {
  JsonElement mapToSend = json_Map_Create();
  json_Map_Add(mapToSend, "some_field", json_Integer_Create(31314));

  HttpString secret = {
    .buffer = "some_key_data",
    .sz = sizeof("some_key_data") - 1
  };
  HttpString invalidSecret = {
    .buffer = "some_key_data_1",
    .sz = sizeof("some_key_data_1") - 1
  };
  uint64_t cTime = 32324255525LL;
  HttpString crm = jwt_Encode_t(mapToSend, invalidSecret, cTime, cTime);
  assert_false(jwt_IsSigned(crm, secret));
  json_DeleteElement(mapToSend);
  free(crm.buffer);
}

static void test_jwt_decode_base64_string_header(void **state) {
  const char *input = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9";
  const char *expected = "{\"alg\":\"HS256\",\"typ\":\"JWT\"}";
  const size_t sz = strlen(input);
  uint8_t response[sz + 1];
  size_t responseSz;
  assert_true(jwt_DecodeURLEncodedBase64((HttpString) {
    .buffer = (char *)input,
    .sz = sz
  }, response, &responseSz));
  assert_int_equal(strlen(expected), responseSz);
  assert_memory_equal(expected, response, responseSz);
}

static void test_jwt_decode_base64_string_payload(void **state) {
  const char *input = "eyJleHAiOjMyMzI0MjU1ODQ5LCJpYXQiOjMyMzI0MjU1NTI1LCJzb21lX2ZpZWxkIjozMTMxNH0";
  const char *expected = "{\"exp\":32324255849,\"iat\":32324255525,\"some_field\":31314}";
  const size_t sz = strlen(input);
  uint8_t response[sz + 1];
  size_t responseSz;
  assert_true(jwt_DecodeURLEncodedBase64((HttpString) {
    .buffer = (char *)input,
    .sz = sz
  }, response, &responseSz));
  assert_int_equal(strlen(expected), responseSz);
  assert_memory_equal(expected, response, responseSz);
}

static void test_jwt_decode_base64_string_invalid(void **state) {
  const char *input = "eyJleHAiOjMyMzI0MjU1ODQ5LCJpY'XQiOjMyMzI0MjU1NTI1LCJzb21lX2ZpZWxkIjozMTMxNH0";
  const size_t sz = strlen(input);
  uint8_t response[sz + 1];
  size_t responseSz;
  assert_false(jwt_DecodeURLEncodedBase64((HttpString) {
    .buffer = (char *)input,
    .sz = sz
  }, response, &responseSz));
}

static void test_jwt_decode_base64_string_with_special_chars(void **state) {
  const char *input = "-wAA";
  const char *expected = "\xFB\x00\x00";
  const size_t sz = strlen(input);
  uint8_t response[sz + 1];
  size_t responseSz;
  assert_true(jwt_DecodeURLEncodedBase64((HttpString) {
    .buffer = (char *)input,
    .sz = sz
  }, response, &responseSz));
  assert_int_equal(responseSz, 3);
  assert_memory_equal(response, expected, responseSz);
}

static void test_jwt_decode_base64_string_with_padding_error(void **state) {
  const char *input = "AQI";
  const char *expected = "\x01\x02";
  const size_t sz = strlen(input);
  uint8_t response[sz + 1];
  size_t responseSz;
  assert_true(jwt_DecodeURLEncodedBase64((HttpString) {
    .buffer = (char *)input,
    .sz = sz
  }, response, &responseSz));
  assert_int_equal(responseSz, 2);
  assert_memory_equal(response, expected, responseSz);
}

static void test_jwt_is_header_valid(void **state) {
  const char *input = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjMyMzI0MjU1ODQ5LCJpYXQiOjMyMzI0MjU1NTI1LCJzb21lX2ZpZWxkIjozMTMxNH0.7zOdXbes1bt_8gnBpACpntvUQoVifLj6WsijL8DvrLI";
  assert_true(jwt_IsHeaderValid((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_header_invalid(void **state) {
  const char *input = "eyJhbGciOiJIUzI1NjciLCJ0eXAiOiJKV1QifQ.eyJleHAiOjMyMzI0MjU1ODQ5LCJpYXQiOjMyMzI0MjU1NTI1LCJzb21lX2ZpZWxkIjozMTMxNH0.7zOdXbes1bt_8gnBpACpntvUQoVifLj6WsijL8DvrLI";
  assert_false(jwt_IsHeaderValid((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_payload_valid_timestamp(void **state) {
  const char *input = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjM3NjUxMDc2Njg2NjgsImlhdCI6MTc2NTEwNzY2ODY2OCwic29tZV9maWVsZCI6MzEzMTR9.7zOdXbes1bt_8gnBpACpntvUQoVifLj6WsijL8DvrLI";
  assert_true(jwt_IsPayloadValid((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_payload_invalid_timestamp(void **state) {
  const char *input = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjE3NjUxMDc2Njg2NjgsImlhdCI6MTc2NTEwNzY2ODY2OCwic29tZV9maWVsZCI6MzEzMTR9.7zOdXbes1bt_8gnBpACpntvUQoVifLj6WsijL8DvrLI";
  assert_false(jwt_IsPayloadValid((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_payload_expiration_is_missing(void **state) {
  const char *input = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpYXQiOjE3NjUxMDc2Njg2NjgsInNvbWVfZmllbGQiOjMxMzE0fQ.7zOdXbes1bt_8gnBpACpntvUQoVifLj6WsijL8DvrLI";
  assert_true(jwt_IsPayloadValid((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_payload_expiration_is_another_type(void **state) {
  const char *input = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOiJkYWRhZmZhIiwiaWF0IjoxNzY1MTA3NjY4NjY4LCJzb21lX2ZpZWxkIjozMTMxNH0.7zOdXbes1bt_8gnBpACpntvUQoVifLj6WsijL8DvrLI";
  assert_false(jwt_IsPayloadValid((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_jwt_format_correct(void **state) {
  const char *input = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOiJkYWRhZmZhIiwiaWF0IjoxNzY1MTA3NjY4NjY4LCJzb21lX2ZpZWxkIjozMTMxNH0.7zOdXbes1bt_8gnBpACpntvUQoVifLj6WsijL8DvrLI";
  assert_true(jwt_IsJWTCorrectlyFormatted((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_jwt_format_invalid_chars(void **state) {
  const char *input = "eyJhbGciOiJIUzI1NiIsInR5c(I6IkpXVCJ9.eyJleHAiOiJkYWRhZmZhIiwiaWF0IjoxNzY1MTA3NjY4NjY4LCJzb21lX2ZpZWxkIjozMTMxNH0.7zOdXbes1bt_8gnBpACpntvUQoVifLj6WsijL8DvrLI";
  assert_false(jwt_IsJWTCorrectlyFormatted((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_jwt_format_invalid_spacing_mid(void **state) {
  const char *input = "A..C";
  assert_false(jwt_IsJWTCorrectlyFormatted((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_jwt_format_invalid_spacing_front(void **state) {
  const char *input = ".B.C";
  assert_false(jwt_IsJWTCorrectlyFormatted((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_jwt_format_invalid_spacing_back(void **state) {
  const char *input = "B.A.";
  assert_false(jwt_IsJWTCorrectlyFormatted((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_jwt_format_invalid_spacing_missing_points(void **state) {
  const char *input = "BA.CC";
  assert_false(jwt_IsJWTCorrectlyFormatted((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_is_jwt_format_valid_small(void **state) {
  const char *input = "A.B.D";
  assert_true(jwt_IsJWTCorrectlyFormatted((HttpString) {
    .buffer = (char *)input,
    .sz = strlen(input)
  }));
}

static void test_jwt_parse_correct(void **state) {
  char *jwtCode = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiYWRtaW4iOnRydWUsImlhdCI6MTUxNjIzOTAyMn0.KMUFsIDTnFmyG3nMiGM6H9FNFUROf3wh7SmqJp-QV30";
  PJWT jwt = jwt_Parse((HttpString) {
    .buffer = jwtCode,
    .sz = strlen(jwtCode)
  }, (HttpString) {
    .buffer = "a-string-secret-at-least-256-bits-long",
    .sz = strlen("a-string-secret-at-least-256-bits-long")
  });
  assert_ptr_not_equal(jwt, NULL);
  assert_int_equal(jwt->header.type, JSON_JSON);
  assert_int_equal(jwt->payload.type, JSON_JSON);
  jwt_Delete(jwt);
}

static void test_jwt_parse_correct_invalid_header(void **state) {
  char *jwtCode = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVC9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiYWRtaW4iOnRydWUsImlhdCI6MTUxNjIzOTAyMn0.KMUFsIDTnFmyG3nMiGM6H9FNFUROf3wh7SmqJp-QV30";
  PJWT jwt = jwt_Parse((HttpString) {
    .buffer = jwtCode,
    .sz = strlen(jwtCode)
  }, (HttpString) {
    .buffer = "a-string-secret-at-least-256-bits-long",
    .sz = strlen("a-string-secret-at-least-256-bits-long")
  });
  assert_ptr_equal(jwt, NULL);
}

static void test_jwt_parse_correct_invalid_payload(void **state) {
  char *jwtCode = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiYWRtaW4iOnRydWUsImlhdCI6MTUxNjIzOTAyMn.KMUFsIDTnFmyG3nMiGM6H9FNFUROf3wh7SmqJp-QV30";
  PJWT jwt = jwt_Parse((HttpString) {
    .buffer = jwtCode,
    .sz = strlen(jwtCode)
  }, (HttpString) {
    .buffer = "a-string-secret-at-least-256-bits-long",
    .sz = strlen("a-string-secret-at-least-256-bits-long")
  });
  assert_ptr_equal(jwt, NULL);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_jwt_hmac_create, NULL),
    cmocka_unit_test_prestate(test_jwt_create_field, NULL),
    cmocka_unit_test_prestate(test_jwt_signed_correctly, NULL),
    cmocka_unit_test_prestate(test_jwt_invalid_signed, NULL),
    cmocka_unit_test_prestate(test_jwt_decode_base64_string_header, NULL),
    cmocka_unit_test_prestate(test_jwt_decode_base64_string_payload, NULL),
    cmocka_unit_test_prestate(test_jwt_decode_base64_string_invalid, NULL),
    cmocka_unit_test_prestate(test_jwt_decode_base64_string_with_special_chars, NULL),
    cmocka_unit_test_prestate(test_jwt_decode_base64_string_with_padding_error, NULL),
    cmocka_unit_test_prestate(test_jwt_is_header_valid, NULL),
    cmocka_unit_test_prestate(test_jwt_is_header_invalid, NULL),
    cmocka_unit_test_prestate(test_jwt_is_payload_valid_timestamp, NULL),
    cmocka_unit_test_prestate(test_jwt_is_payload_invalid_timestamp, NULL),
    cmocka_unit_test_prestate(test_jwt_is_payload_expiration_is_missing, NULL),
    cmocka_unit_test_prestate(test_jwt_is_payload_expiration_is_another_type, NULL),
    cmocka_unit_test_prestate(test_jwt_is_jwt_format_correct, NULL),
    cmocka_unit_test_prestate(test_jwt_is_jwt_format_invalid_chars, NULL),
    cmocka_unit_test_prestate(test_jwt_is_jwt_format_invalid_spacing_mid, NULL),
    cmocka_unit_test_prestate(test_jwt_is_jwt_format_invalid_spacing_front, NULL),
    cmocka_unit_test_prestate(test_jwt_is_jwt_format_invalid_spacing_back, NULL),
    cmocka_unit_test_prestate(test_jwt_is_jwt_format_invalid_spacing_missing_points, NULL),
    cmocka_unit_test_prestate(test_jwt_is_jwt_format_valid_small, NULL),
    cmocka_unit_test_prestate(test_jwt_parse_correct, NULL),
    cmocka_unit_test_prestate(test_jwt_parse_correct_invalid_header, NULL),
    cmocka_unit_test_prestate(test_jwt_parse_correct_invalid_payload, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}