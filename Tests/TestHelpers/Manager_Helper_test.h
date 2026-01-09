#pragma once

#include "GameNetworkManager.h"
#include "JsonParser.h"

PConnection man_Helper_Login(PManager self, uint16_t port, JsonElement payload, char *secret);
void man_Helper_AddUser(PManager self, uint64_t userID);
PConnection man_Helper_LoginHigherLevel(PManager self, uint64_t userID, char *secret);
PHttpResponse man_Helper_RegisterPlayer(PManager self, uint64_t userID, char *secret);