#pragma once
#include "Structs.h"
#include "SocketServer.h"

PHttpServer httpS_Create(uint16_t port);
void httpS_Delete(PHttpServer self);
JsonElement httpS_Json_Get(PHttpRequest req);