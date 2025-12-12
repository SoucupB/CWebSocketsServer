#pragma once
#include "Structs.h"
#include "SocketServer.h"

PHttpServer httpS_Create(uint16_t port);
void httpS_Delete(PHttpServer self);
JsonElement httpS_Json_Get(PHttpRequest req);
PHttpResponse httpS_Json_Post(JsonElement jsn);
void httpS_OnFrame(PHttpServer self, uint64_t deltaMS);

PHttpRequestServer httpS_Request_Create(int64_t timeoutMS);
void httpS_Request_Delete(PHttpRequestServer self);
void httpS_Request_OnFrame(PHttpRequestServer self, uint64_t deltaMS);