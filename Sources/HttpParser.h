#pragma once

#include <stdint.h>
#include <stddef.h>
#include "TrieHash.h"

typedef enum {
  GET,
  POST,
  PUT,
  PATCH,
  DELETE
} HttpAction;

typedef struct HttpString_t {
  char *buffer;
  size_t sz;
} HttpString;

typedef HttpString *PHttpString;

typedef struct URL_t {
  HttpString path;
  char httpType[16];
  HttpAction method;
} URL;

typedef URL *PURL;

typedef struct HttpMetaData_t {
  HttpString codes[10];
  size_t actionsSz;
} HttpMetaData;

typedef HttpMetaData *PHttpMetaData;

typedef struct Hash_t {
  PTrieHash hash;
  PTrieHash valuesSize;
} Hash;

typedef struct HttpRequest_t {
  Hash headers;
  PURL url;
  PHttpString body;
  char *_endBuffer;
  PHttpMetaData metadata;
} HttpRequest;

typedef HttpRequest *PHttpRequest;

typedef struct HttpResponse_t {
  char *httpCode;
  Hash headers;
  HttpString body;
  uint16_t response;
} HttpResponse;

typedef HttpResponse *PHttpResponse;

PHttpRequest http_Request_Parse(char *buffer, size_t sz);
HttpString http_Request_GetValue(PHttpRequest self, char *buffer);
void http_Request_Delete(PHttpRequest self);

HttpString http_Hash_GetValue(Hash self, char *buffer, size_t bufferLen);
PHttpResponse http_Response_Create();
void http_Response_SetBody(PHttpResponse self, PHttpString buffer);
void http_Response_Delete(PHttpResponse self);
HttpString http_Response_ToString(PHttpResponse self);