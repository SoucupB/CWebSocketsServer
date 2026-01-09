#pragma once

#include <stdint.h>
#include <stddef.h>
#include "Structs.h"
#include "NetworkBuffer.h"

PHttpRequest http_Request_Parse(char *buffer, size_t sz);
HttpString http_Request_ToString(PHttpRequest self);
HttpString http_Request_GetValue(PHttpRequest self, char *buffer);
void http_Request_Delete(PHttpRequest self);
PHttpRequest http_Request_Create();
void http_Request_SetBody(PHttpRequest self, HttpString str);
HttpString http_Request_GetBody(PHttpRequest self);
HttpString http_Request_GetPath(PHttpRequest self);
void http_Request_AddHeader(PHttpRequest self, char *key, char *value);
PHttpRequest http_Request_Basic();
PHttpRequest http_Request_Chomp(HttpString bff, char **endBuffer);
PHttpRequest http_Request_NB_Get(PNetworkBuffer netBuffer);
void http_Request_Print(PHttpRequest self);

HttpString http_Hash_GetValue(Hash self, char *buffer, size_t bufferLen);

PHttpResponse http_Response_Create();
PHttpResponse http_Response_Basic(uint16_t code);
PHttpResponse http_Response_DeepCopy(PHttpResponse self);
void http_Response_SetBody(PHttpResponse self, PHttpString buffer);
void http_Response_Delete(PHttpResponse self);
HttpString http_Response_ToString(PHttpResponse self);
PHttpResponse http_Response_Empty();
void http_Response_Set(PHttpResponse self, char *key, size_t keySize, char *value, size_t valueSize);
void http_Response_SetJSON(PHttpResponse self);
PHttpResponse http_Response_Parse(HttpString buffer);
HttpString http_Response_GetValue(PHttpResponse self, char *buffer);
PHttpResponse http_Response_Chomp(HttpString bff, char **endBuffer);
PHttpResponse http_Response_NB_Get(PNetworkBuffer netBuffer);