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

typedef struct Body_t {
  char *body;
  size_t sz;
} Body;

typedef Body *PBody;

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

typedef struct Http_t {
  PTrieHash headers;
  PURL url;
  PBody body;
  char *_endBuffer;
  PHttpMetaData metadata;
} Http;

typedef Http *PHttp;

PHttp http_Parse(char *buffer, size_t sz);
void http_Delete(PHttp self);