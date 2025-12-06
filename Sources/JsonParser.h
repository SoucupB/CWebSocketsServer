#pragma once

#include "Structs.h"

PJsonObject json_Create();
void json_Delete(PJsonObject self);
void json_Add(PJsonObject self, PHttpString key, JsonElement element);
HttpString json_ToString(PJsonObject self);
void json_RemoveSelfContainedData(PJsonObject self);
JsonElement json_Parse(PHttpString buffer, char **nextBuffer);
HttpString json_Element_ToString(JsonElement self);
void json_Parser_Print(JsonElement self);