#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "HttpParser.h"
#include <stdlib.h>
#include "GameNetworkManager.h"
#include "Manager_Helper_test.h"
#include "Socket_Helper_test.h"
#include "SocketClient.h"
#include "Json_Helper_test.h"

uint16_t port = 34321;
uint16_t httpPort = 64000;

static void test_manager_create(void **state) {
  const uint16_t cPort = port--;
  PManager manager = man_Create(cPort);
  assert_ptr_not_equal(manager, NULL);
  man_Delete(manager);
}

static void test_manager_login_succesfully(void **state) {
  const uint16_t cPort = port--;
  char *secret = "DSjifdsgFDSFggsgsdgFDSAFDSA";
  PManager self = man_Create(cPort);
  man_Helper_AddUser(self, 324);
  man_SetSecret(self, (HttpString) {
    .buffer = secret,
    .sz = strlen(secret)
  });
  JsonElement payload = test_Helper_Json_Parse("\
{\
    \"user_id\": 324\
}\
");
  PConnection cnn = man_Helper_Login(self, cPort, payload, secret);
  assert_ptr_not_equal(cnn, NULL);
  PUser currentUser = man_User_Get(self, 324);
  assert_ptr_not_equal(currentUser, NULL);
  assert_true(currentUser->active);
  man_Delete(self);
  sock_Client_Free(cnn);
  json_DeleteElement(payload);
}

static void test_manager_login_helper_higher_level(void **state) {
  const uint16_t cPort = port--;
  char *secret = "DSjifdsgFDSFggsgsdgFDSAFDSA";
  PManager self = man_Create(cPort);
  man_Helper_AddUser(self, 324);
  man_SetSecret(self, (HttpString) {
    .buffer = secret,
    .sz = strlen(secret)
  });
  PConnection cnn = man_Helper_LoginHigherLevel(self, 324, secret);
  assert_ptr_not_equal(cnn, NULL);
  PUser currentUser = man_User_Get(self, 324);
  assert_true(currentUser->active);
  man_Delete(self);
  sock_Client_Free(cnn);
}

static void test_manager_login_helper_failed_login_missing_user(void **state) {
  const uint16_t cPort = port--;
  char *secret = "DSjifdsgFDSFggsgsdgFDSAFDSA";
  PManager self = man_Create(cPort);
  man_Helper_AddUser(self, 324);
  man_SetSecret(self, (HttpString) {
    .buffer = secret,
    .sz = strlen(secret)
  });
  PConnection cnn = man_Helper_LoginHigherLevel(self, 3242, secret);
  assert_ptr_not_equal(cnn, NULL);
  PUser currentUser = man_User_Get(self, 324);
  assert_false(currentUser->active);
  man_Delete(self);
  sock_Client_Free(cnn);
}

static void test_manager_login_helper_failed_login_invalid_key(void **state) {
  const uint16_t cPort = port--;
  char *secret = "DSjifdsgFDSFggsgsdgFDSAFDSA";
  char *givenSecret = "fake_key";
  PManager self = man_Create(cPort);
  man_Helper_AddUser(self, 324);
  man_SetSecret(self, (HttpString) {
    .buffer = secret,
    .sz = strlen(secret)
  });
  PConnection cnn = man_Helper_LoginHigherLevel(self, 324, givenSecret);
  assert_ptr_not_equal(cnn, NULL);
  PUser currentUser = man_User_Get(self, 324);
  assert_false(currentUser->active);
  man_Delete(self);
  sock_Client_Free(cnn);
}

static void test_manager_http_server_init(void **state) {
  const uint16_t cPort = port--;
  const uint16_t cHttpPort = httpPort--;
  char *secret = "DSjifdsgFDSFggsgsdgFDSAFDSA";
  PManager self = man_Create(cPort);
  man_InitHTTPServer(self, cHttpPort);
  man_SetSecret(self, (HttpString) {
    .buffer = secret,
    .sz = strlen(secret)
  });
  assert_ptr_not_equal(self->httpServer, NULL);
  man_Delete(self);
}

static void test_manager_http_request_register_player(void **state) {
  const uint16_t cPort = port--;
  const uint16_t cHttpPort = httpPort--;
  char *secret = "DSjifdsgFDSFggsgsdgFDSAFDSA";
  PManager self = man_Create(cPort);
  man_InitHTTPServer(self, cHttpPort);
  man_SetSecret(self, (HttpString) {
    .buffer = secret,
    .sz = strlen(secret)
  });
  PHttpResponse response = man_Helper_RegisterPlayer(self, 342455, secret);
  assert_ptr_not_equal(self->httpServer, NULL);
  assert_ptr_not_equal(response, NULL);
  assert_int_equal(response->response, 200);
  assert_int_equal(man_Users(self)->size, 1);
  http_Response_Delete(response);
  man_Delete(self);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_manager_create),
    cmocka_unit_test(test_manager_login_succesfully),
    cmocka_unit_test(test_manager_login_helper_higher_level),
    cmocka_unit_test(test_manager_login_helper_failed_login_missing_user),
    cmocka_unit_test(test_manager_login_helper_failed_login_invalid_key),
    cmocka_unit_test(test_manager_http_server_init),
    cmocka_unit_test(test_manager_http_request_register_player),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}