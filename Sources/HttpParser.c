#include "HttpParser.h"
#include <stdlib.h>
#include <string.h>

static inline PHttpMetaData http_InitMetadata();
static inline PURL http_URL_Init();
static inline void http_UpdateString(PHttp self, PHttpString string, char *buffer);
uint8_t http_Route_Parse(PHttp parent, PHttpString buffer);

#define ALPHANUMERIC "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_."

PHttp http_Parse(char *buffer, size_t sz) {
  PHttp self = malloc(sizeof(Http));
  memset(self, 0, sizeof(Http));
  self->headers = trh_Create();
  self->_endBuffer = buffer + sz;
  self->metadata = http_InitMetadata();
  self->url = http_URL_Init();
  HttpString input = {
    .buffer = buffer,
    .sz = sz
  };
  http_Route_Parse(self, &input);
  return self;
}

static inline PURL http_URL_Init() {
  PURL self = malloc(sizeof(URL));
  memset(self, 0, sizeof(URL));
  return self;
}

static inline void http_Meta_InitCodes(PHttpMetaData self) {
  char *codes[] = {"GET", "POST", "PUT", "PATCH", "DELETE"};
  self->actionsSz = 0;
  for(size_t i = 0; i < sizeof(codes) / sizeof(char *); i++) {
    self->codes[i] = (HttpString) {
      .buffer = codes[i],
      .sz = strlen(codes[i])
    };
    self->actionsSz++;
  }
}

static inline PHttpMetaData http_InitMetadata() {
  PHttpMetaData metaData = malloc(sizeof(HttpMetaData));
  http_Meta_InitCodes(metaData);
  return metaData;
}

char *http_GetToken(PHttpString buffer, PHttpString token) {
  if(buffer->sz < token->sz) {
    return NULL;
  }
  for(size_t i = 0, c = token->sz; i < c; i++) {
    if(token->buffer[i] != buffer->buffer[i]) {
      return NULL;
    }
  }
  return buffer->buffer + token->sz;
}

char *http_Route_ParseCodes(PHttp parent, PHttpString buffer) {
  PHttpMetaData meta = parent->metadata;
  for(size_t i = 0, c = meta->actionsSz; i < c; i++) {
    char *currentToken = http_GetToken(buffer, &meta->codes[i]);
    if(!currentToken) {
      continue;
    }
    parent->url->method = i;
    return currentToken;
  }
  return NULL;
}

static inline void http_UpdateString(PHttp self, PHttpString string, char *buffer) {
  string->buffer = buffer;
  string->sz = (size_t)(self->_endBuffer - buffer);
}

static inline char *http_ChompString(PHttpString buff, char *like, uint8_t repeat) {
  char presence[257] = {0};
  for(size_t i = 0, c = strlen(like); i < c; i++) {
    presence[(uint8_t)like[i]] = 1;
  }
  size_t index = 0;
  while(repeat && index < buff->sz && presence[(uint8_t)buff->buffer[index]]) {
    index++;
  }
  if(!repeat && index < buff->sz && presence[(uint8_t)buff->buffer[index]]) {
    index++;
  }
  if(!index) {
    return NULL;
  }
  return buff->buffer + index; 
}

char *http_Path_Parse(PHttp parent, PHttpString buffer) {
  HttpString cpyBuffer = *buffer;
  char *strings[] = {
    "/",
    ALPHANUMERIC
  };
  uint8_t i = 0;
  char *bff;
  while((bff = http_ChompString(&cpyBuffer, strings[i], i)) && bff) {
    http_UpdateString(parent, &cpyBuffer, bff);
    i = !i;
  }
  return cpyBuffer.buffer;
}

char *http_Route_ParseType(PHttp parent, PHttpString buffer) {
  char *bff = http_ChompString(buffer, ALPHANUMERIC, 1);
  if(!bff) {
    return NULL;
  }
  bff = http_ChompString(buffer, "/", 0);
  if(!bff) {
    return NULL;
  }
  bff = http_ChompString(buffer, ALPHANUMERIC, 1);
  if(!bff) {
    return NULL;
  }
  return bff;
}

char *http_Route_Parse_t(PHttp parent, PHttpString buffer) {
  char *codesBuffer = http_Route_ParseCodes(parent, buffer);
  if(!codesBuffer) {
    return NULL;
  }
  http_UpdateString(parent, buffer, codesBuffer);

  char *chompedSpace = http_ChompString(buffer, " ", 0);
  if(!chompedSpace) {
    return NULL;
  }
  http_UpdateString(parent, buffer, chompedSpace);

  char *path = http_Path_Parse(parent, buffer);
  if(!path) {
    return NULL;
  }
  size_t bffSize = (size_t)(path - buffer->buffer);
  parent->url->path.buffer = malloc(bffSize);
  memcpy(parent->url->path.buffer, buffer->buffer, bffSize);
  parent->url->path.sz = bffSize;
  http_UpdateString(parent, buffer, path);
  
  chompedSpace = http_ChompString(buffer, " ", 0);
  if(!chompedSpace) {
    return NULL;
  }
  http_UpdateString(parent, buffer, chompedSpace);

  char *httpType = http_Route_ParseType(parent, buffer);
  if(!httpType) {
    return NULL;
  }
  memcpy(parent->url->httpType, httpType, (size_t)(httpType - buffer->buffer));
  http_UpdateString(parent, buffer, httpType);

  chompedSpace = http_ChompString(buffer, "\r\n", 0);
  if(!chompedSpace) {
    return NULL;
  }
  http_UpdateString(parent, buffer, chompedSpace);
  return buffer->buffer;
}

uint8_t http_Route_Parse(PHttp parent, PHttpString buffer) {
  HttpString nextBuffer = *buffer;
  char *urlParse = http_Route_Parse_t(parent, &nextBuffer);
  if(!urlParse) {
    return 0;
  }
  http_UpdateString(parent, buffer, urlParse);

  return 1;
}

void http_URL_Free(PURL self) {
  if(!self) {
    return ;
  }
  if(self->path.buffer) {
    free(self->path.buffer);
  }
  free(self);
}

void http_Delete(PHttp self) {
  http_URL_Free(self->url);
  trh_Delete(self->headers);
  free(self);
}