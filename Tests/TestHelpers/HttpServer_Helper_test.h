#pragma once
#include <string.h>
#include "HttpServer.h"
#include "Structs.h"
#include "JWT.h"
#include "JsonParser.h"
#include "TimeFragment.h"

void http_Helper_AddMethod(PHttpServer server, void *method);
void http_Helper_Free(PHttpServer server);
PHttpResponse http_Helper_Send(PHttpServer server, uint16_t port, PHttpRequest req);