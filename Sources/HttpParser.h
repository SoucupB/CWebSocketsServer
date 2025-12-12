#pragma once

#include <stdint.h>
#include <stddef.h>
#include "Structs.h"

PHttpRequest http_Request_Parse(char *buffer, size_t sz);
HttpString http_Request_ToString(PHttpRequest self);
HttpString http_Request_GetValue(PHttpRequest self, char *buffer);
void http_Request_Delete(PHttpRequest self);
PHttpRequest http_Request_Create();
void http_Request_SetBody(PHttpRequest self, HttpString str);
HttpString http_Request_GetBody(PHttpRequest self);
HttpString http_Request_GetPath(PHttpRequest self);

HttpString http_Hash_GetValue(Hash self, char *buffer, size_t bufferLen);
PHttpResponse http_Response_Create();
void http_Response_SetBody(PHttpResponse self, PHttpString buffer);
void http_Response_Delete(PHttpResponse self);
HttpString http_Response_ToString(PHttpResponse self);
PHttpResponse http_Response_Empty();
void http_Response_Set(PHttpResponse self, char *key, size_t keySize, char *value, size_t valueSize);
void http_Response_SetJSON(PHttpResponse self);