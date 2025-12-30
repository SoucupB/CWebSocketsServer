#pragma once
#include "Structs.h"

HttpString jwt_Encode(JsonElement payload, HttpString secret, uint64_t expirationInMS);
size_t jwt_Base64_Size_Public(size_t sz);
uint8_t jwt_IsSigned(HttpString str, HttpString secret);
uint8_t jwt_IsValid(HttpString str, HttpString secret);
PJWT jwt_Parse(HttpString jwtStr, HttpString secret);
void jwt_Delete(PJWT self);