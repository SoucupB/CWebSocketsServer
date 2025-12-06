#include <stdarg.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmocka.h"
#include "Vector.h"
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
  HttpString crm = jwt_Encode_t(mapToSend, secret, cTime, cTime);
  char *jwt = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjMyMzI0MjU1NTI1LCJpYXQiOjMyMzI0MjU1NTI1LCJzb21lX2ZpZWxkIjozMTMxNH0.Dkc_NeEmf2cHLRsSXz8I4rF8sgPm77Aq0xF1fj5osuM";
  assert_memory_equal(jwt, crm.buffer, strlen(jwt));
  json_DeleteElement(mapToSend);
  free(crm.buffer);
}

int main() {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_prestate(test_jwt_hmac_create, NULL),
    cmocka_unit_test_prestate(test_jwt_create_field, NULL),
  };
  const uint32_t value = cmocka_run_group_tests(tests, NULL, NULL);
  return value;
}