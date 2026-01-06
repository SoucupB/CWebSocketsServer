#pragma once
#include <string.h>
#include "HttpServer.h"
#include "Structs.h"
#include "JWT.h"
#include "JsonParser.h"
#include "TimeFragment.h"

void http_Helper_AddMethod(PHttpServer server, void *method);
void http_Helper_Free(PHttpServer server);
PHttpResponse http_Helper_Send(uint16_t port, PHttpRequest req, PSocketMethod method);
PHttpResponse http_Helper_Process(PHttpServer server, PHttpRequest req);
PSocketMethod http_Helper_MirrorMethod(void *mirror);
Array http_Helper_StreamRequest(PHttpServer server, Array requests);
Array http_Helper_StreamRequestStrings(PHttpServer server, char **strs, size_t count);
void http_Helper_FreeStrArray(const Array arr);
void http_Helper_PrintArray(Array arr);