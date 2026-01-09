#pragma once

#include "GameNetworkManager.h"
#include "JsonParser.h"

typedef struct MessageResponse_t {
  PUser user;
  HttpString str;
} MessageResponse;

typedef struct {
  PConnection conn;
  HttpString str;
} ManInput;

PConnection man_Helper_Login(PManager self, uint16_t port, JsonElement payload, char *secret);
void man_Helper_AddUser(PManager self, uint64_t userID);
PConnection man_Helper_LoginHigherLevel(PManager self, uint64_t userID, char *secret);
PHttpResponse man_Helper_RegisterPlayer(PManager self, uint64_t userID, uint8_t admin, char *secret);
Array man_Helper_SendRequest(PManager self, PConnection conn, ManInput *message, size_t count);
void man_Helper_DeleteArray(Array arr);