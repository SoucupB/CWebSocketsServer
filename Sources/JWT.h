#pragma once
#include "Structs.h"

HttpString jwt_Encode(JsonElement payload, HttpString secret, uint64_t expirationMS);
size_t jwt_Base64_Size_Public(size_t sz);