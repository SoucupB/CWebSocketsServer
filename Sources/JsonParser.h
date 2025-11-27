#pragma once

#include "Structs.h"

PJsonObject json_Create();
void json_Delete(PJsonObject self);
void json_Add(PJsonObject self, PHttpString key, JsonElement element);