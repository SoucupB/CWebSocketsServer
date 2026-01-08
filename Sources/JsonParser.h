#pragma once

#include "Structs.h"

PJsonObject json_Create();
JsonElement json_Map_Create();
void json_Delete(PJsonObject self);
void json_Add(PJsonObject self, PHttpString key, JsonElement element);
HttpString json_ToString(PJsonObject self);
void json_RemoveSelfContainedData(PJsonObject self);
JsonElement json_Parse(HttpString buffer, char **nextBuffer);
HttpString json_Element_ToString(JsonElement self);
void json_Parser_Print(JsonElement self);
void json_DeleteElement(JsonElement element);

JsonElement json_Map_Get(JsonElement jsonMap, HttpString str);
JsonElement json_Array_At(JsonElement arr, size_t index);
size_t json_Array_Size(JsonElement arr);
int64_t json_Integer_Get(JsonElement arr);
float json_Number_Get(JsonElement arr);
JsonElement json_Map_GetString(JsonElement jsonMap, const char *key);
void json_Map_Add(JsonElement map, char *key, JsonElement element);
void json_Map_String_String_Add(JsonElement map, char *key, char *value);

JsonElement json_Integer_Create(int64_t val);
JsonElement json_Number_Create(float val);
JsonElement json_String_Create(char *string);
JsonElement json_String_CreateFromHttpString(HttpString string);