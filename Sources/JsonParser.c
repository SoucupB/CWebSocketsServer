#include "JsonParser.h"
#include "TrieHash.h"

PJsonObject json_Create() {
  PJsonObject self = malloc(sizeof(JsonObject));
  self->hsh = trh_Create();
  return self;
}

void json_Delete(PJsonObject self) {
  trh_Delete(self->hsh);
  free(self);
}

PHttpString json_ToString(PJsonObject self) {
  return NULL;
}