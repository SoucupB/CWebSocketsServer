#include "HttpParser.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Vector.h"
#include "TrieHash.h"

static inline PHttpMetaData http_InitMetadata();
static inline PURL http_URL_Init();
static inline void http_UpdateString(PHttpRequest self, PHttpString string, char *buffer);
uint8_t http_Route_Parse(PHttpRequest parent, PHttpString buffer);
static inline char *http_ChompString(PHttpString buff, char *like, uint8_t repeat);
uint8_t http_Header_Parse(PHttpRequest self, PHttpString buffer);
char *http_GetToken(PHttpString buffer, PHttpString token);
static inline char *http_ChompLineSeparator(PHttpString buffer);
static inline Hash http_Hash_Create();
void http_Body_Process(PHttpRequest self, PHttpString buffer);

#define ALPHANUMERIC "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_."
#define ACCEPTED_ALPHANUMERIC_KEY "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-.^_`|~"
#define ACCEPTED_ALPHANUMERIC_VALUE "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./;:<=>?@[\\]^_`{|}~ "

PHttpRequest http_Request_Parse(char *buffer, size_t sz) {
  PHttpRequest self = malloc(sizeof(HttpRequest));
  memset(self, 0, sizeof(HttpRequest));
  self->headers = http_Hash_Create();
  self->_endBuffer = buffer + sz;
  self->metadata = http_InitMetadata();
  self->url = http_URL_Init();
  HttpString input = {
    .buffer = buffer,
    .sz = sz
  };
  if(!http_Route_Parse(self, &input)) {
    http_Request_Delete(self);
    return NULL;
  }
  if(!http_Header_Parse(self, &input)) {
    http_Request_Delete(self);
    return NULL;
  }
  http_Body_Process(self, &input);
  if(input.sz) {
    http_Request_Delete(self);
    return NULL;
  }
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

static inline void http_Hash_Add(Hash self, char *key, size_t keySize, char *value, size_t valueSize) {
  trh_Add(self.hash, key, keySize, value, valueSize);
  trh_Add(self.valuesSize, key, keySize, &valueSize, sizeof(size_t));
}

char *http_Header_ParseLine(PHttpRequest self, PHttpString buffer) {
  char *key = http_ChompString(buffer, ACCEPTED_ALPHANUMERIC_KEY, 1);
  if(!key) {
    return NULL;
  }
  size_t keySize = (size_t)(key - buffer->buffer);
  char *keyOffset = buffer->buffer;
  http_UpdateString(self, buffer, key);

  char *separator = http_ChompString(buffer, ":", 0);
  if(!separator) {
    return NULL;
  }
  http_UpdateString(self, buffer, separator);

  char *space = http_ChompString(buffer, " ", 0);
  if(space) {
    http_UpdateString(self, buffer, space);
  }
  char *value = http_ChompString(buffer, ACCEPTED_ALPHANUMERIC_VALUE, 1);
  if(!value) {
    return NULL;
  }
  size_t valueSize = (size_t)(value - buffer->buffer);
  char *valueOffset = buffer->buffer;
  http_UpdateString(self, buffer, value);

  http_Hash_Add(self->headers, keyOffset, keySize, valueOffset, valueSize);
  char *endOfLine = http_ChompLineSeparator(buffer);
  if(!endOfLine) {
    return NULL;
  }
  http_UpdateString(self, buffer, endOfLine);
  return endOfLine;
}

static inline Hash http_Hash_Create() {
  Hash hash;
  hash.hash = trh_Create();
  hash.valuesSize = trh_Create();
  return hash;
}

static inline char *http_ChompLineSeparator(PHttpString buffer) {
  HttpString lineSeparator = {
    .buffer = "\r\n",
    .sz = sizeof("\r\n") - 1
  };
  return http_GetToken(buffer, &lineSeparator);
}

HttpString http_Request_GetValue(PHttpRequest self, char *buffer) {
  size_t bufferLen = strlen(buffer);
  char *response = trh_GetBuffer(self->headers.hash, buffer, bufferLen);
  size_t *size = trh_GetBuffer(self->headers.valuesSize, buffer, bufferLen);
  return (HttpString){
    .buffer = response,
    .sz = size ? *size : 0
  };
}

HttpString http_Hash_GetValue(Hash self, char *buffer, size_t bufferLen) {
  char *response = trh_GetBuffer(self.hash, buffer, bufferLen);
  size_t *size = trh_GetBuffer(self.valuesSize, buffer, bufferLen);
  return (HttpString){
    .buffer = response,
    .sz = size ? *size : 0
  };
}

uint8_t http_Header_Parse(PHttpRequest self, PHttpString buffer) {
  char *buff;
  HttpString cpyStr = *buffer;
  while((buff = http_Header_ParseLine(self, &cpyStr)) && buff);
  char *endOfLine = http_ChompLineSeparator(&cpyStr);
  if(!endOfLine) {
    return 0;
  }
  http_UpdateString(self, buffer, endOfLine);
  return 1;
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

ssize_t http_Parse_Number(PHttpRequest self, char *buffer, size_t sz, char **endBufer) {
  size_t index = 0;
  ssize_t number = 0;
  while(index < sz && index < 15 && buffer[index] >= '0' && buffer[index] <= '9') {
    number *= 10LL;
    number += (ssize_t)(buffer[index] - '0');
    index++;
  }
  *endBufer = buffer + index;
  return number;
}

ssize_t http_Get_Number(PHttpRequest self, char *key, uint8_t *isValid) {
  *isValid = 0;
  HttpString value = http_Request_GetValue(self, key);
  if(!value.buffer) {
    return 0;
  }
  char *endPtr;
  ssize_t number = http_Parse_Number(self, value.buffer, value.sz, &endPtr);
  if(endPtr != value.buffer + value.sz) {
    return 0;
  }
  *isValid = 1;
  return number;
}

PHttpString http_Body_Chomp_t(PHttpRequest self, PHttpString buffer, ssize_t contentLength) {
  if(contentLength > buffer->sz) {
    return NULL;
  }
  PHttpString response = malloc(sizeof(HttpString));
  response->buffer = malloc(contentLength);
  response->sz = (size_t)contentLength;
  memcpy(response->buffer, buffer->buffer, response->sz);
  return response;
}

char *http_Body_Chomp(PHttpRequest self, PHttpString buffer, PHttpString *response) {
  uint8_t valid;
  ssize_t contentLength = http_Get_Number(self, "Content-Length", &valid);
  if(!valid || contentLength < 0) {
    return NULL;
  }
  PHttpString body = http_Body_Chomp_t(self, buffer, contentLength);
  if(!body) {
    return NULL;
  }
  *response = body;
  return buffer->buffer + body->sz;
}

void http_Body_Process(PHttpRequest self, PHttpString buffer) {
  PHttpString body;
  char *bodyBuffer = http_Body_Chomp(self, buffer, &body);
  if(!bodyBuffer) {
    return ;
  }
  self->body = body;
  http_UpdateString(self, buffer, bodyBuffer);
}

char *http_Route_ParseCodes(PHttpRequest parent, PHttpString buffer) {
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

static inline void http_UpdateString(PHttpRequest self, PHttpString string, char *buffer) {
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

char *http_Path_Parse(PHttpRequest parent, PHttpString buffer) {
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

char *http_Route_ParseType(PHttpRequest parent, PHttpString buffer) {
  HttpString cpyString = *buffer;
  char *bff = http_ChompString(&cpyString, ALPHANUMERIC, 1);
  if(!bff) {
    return NULL;
  }
  http_UpdateString(parent, &cpyString, bff);

  bff = http_ChompString(&cpyString, "/", 0);
  if(!bff) {
    return NULL;
  }
  http_UpdateString(parent, &cpyString, bff);

  bff = http_ChompString(&cpyString, ALPHANUMERIC, 1);
  if(!bff) {
    return NULL;
  }
  http_UpdateString(parent, &cpyString, bff);

  return bff;
}

char *http_Route_Parse_t(PHttpRequest parent, PHttpString buffer) {
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
  size_t mthSize = (size_t)(httpType - buffer->buffer);
  if(mthSize >= sizeof(parent->url->httpType)) {
    return NULL;
  }
  memcpy(parent->url->httpType, buffer->buffer, mthSize);
  http_UpdateString(parent, buffer, httpType);

  chompedSpace = http_ChompLineSeparator(buffer);
  if(!chompedSpace) {
    return NULL;
  }
  http_UpdateString(parent, buffer, chompedSpace);
  return buffer->buffer;
}

uint8_t http_Route_Parse(PHttpRequest parent, PHttpString buffer) {
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

static inline void http_Hash_Delete(Hash self) {
  trh_Delete(self.hash);
  trh_Delete(self.valuesSize);
}

void http_Metadata_Delete(PHttpMetaData self) {
  free(self);
}

void http_Request_Delete(PHttpRequest self) {
  if(self->body) {
    free(self->body->buffer);
    free(self->body);
  }
  http_URL_Free(self->url);
  http_Hash_Delete(self->headers);
  http_Metadata_Delete(self->metadata);
  free(self);
}

void http_Request_SetBodySize(PHttpResponse self, size_t sz) {
  char buffer[20] = {0};
  snprintf(buffer, sizeof(buffer), "%zu", sz);
  http_Hash_Add(self->headers, "Content-Length", sizeof("Content-Length") - 1, buffer, strlen(buffer));
}

void http_Response_SetBody(PHttpResponse self, PHttpString buffer) {
  if(self->body.buffer) {
    free(self->body.buffer);
  }
  self->body.buffer = malloc(buffer->sz);
  memcpy(self->body.buffer, buffer->buffer, buffer->sz);
  self->body.sz = buffer->sz;
  http_Request_SetBodySize(self, buffer->sz);
}

static inline size_t http_Response_Size(Hash headers, Vector headersArr) {
  size_t totalSize = 0;
  Key *headerBuffer = headersArr->buffer;
  for(size_t i = 0, c = headersArr->size; i < c; i++) {
    HttpString valueBuffer = http_Hash_GetValue(headers, headerBuffer[i].key, headerBuffer[i].keySize);
    if(!valueBuffer.buffer) {
      continue;
    } 
    totalSize += snprintf(NULL, 0, "%.*s: %.*s\r\n", (int)headerBuffer[i].keySize, (char *)headerBuffer[i].key, (int)valueBuffer.sz, valueBuffer.buffer);
  }
  return totalSize;
}

char *http_FormatHeaders(Hash headers, Vector headersArr, char *buffer, size_t bufferSize) {
  Key *headerBuffer = headersArr->buffer;
  for(size_t i = 0, c = headersArr->size; i < c; i++) {
    HttpString valueBuffer = http_Hash_GetValue(headers, headerBuffer[i].key, headerBuffer[i].keySize);
    if(!valueBuffer.buffer) {
      continue;
    }
    size_t bufferBytesCount = snprintf(NULL, 0, "%.*s: %.*s\r\n", (int)headerBuffer[i].keySize, (char *)headerBuffer[i].key, (int)valueBuffer.sz, (char *)valueBuffer.buffer);
    char tempBuffer[bufferBytesCount + 3];
    snprintf(tempBuffer, bufferBytesCount + 3, "%.*s: %.*s\r\n", (int)headerBuffer[i].keySize, (char *)headerBuffer[i].key, (int)valueBuffer.sz, (char *)valueBuffer.buffer);
    memcpy(buffer, tempBuffer, bufferBytesCount);
    buffer += (bufferBytesCount);
  }
  memcpy(buffer, "\r\n", sizeof("\r\n") - 1);
  buffer += sizeof("\r\n") - 1;
  return buffer;
}

HttpString http_Response_ToString(PHttpResponse self) {
  char messageHeader[64] = {0};
  snprintf(messageHeader, sizeof(messageHeader), "%s %u\r\n", self->httpCode, self->response);
  Vector headersArr = trh_GetKeys(self->headers.hash);
  size_t requestSize = http_Response_Size(self->headers, headersArr);
  size_t headerSizeCode = strlen(messageHeader);
  size_t bufferSize = headerSizeCode + requestSize + self->body.sz + 5;
  char *buffer = malloc(bufferSize);
  char *cpyBuffer = buffer;
  memcpy(cpyBuffer, messageHeader, headerSizeCode);
  cpyBuffer += headerSizeCode;
  cpyBuffer = http_FormatHeaders(self->headers, headersArr, cpyBuffer, requestSize);
  if(self->body.buffer) {
    memcpy(cpyBuffer, self->body.buffer, self->body.sz);
    cpyBuffer += self->body.sz;
  }
  trh_FreeKeys(headersArr);
  return (HttpString) {
    .buffer = buffer,
    .sz = (size_t)(cpyBuffer - buffer)
  };
}

void http_Response_SetDefault(PHttpResponse self) {
  http_Hash_Add(self->headers, "Content-Type", sizeof("Content-Type") - 1, "text/plain", sizeof("text/plain") - 1);
  http_Hash_Add(self->headers, "Connection", sizeof("Connection") - 1, "close", sizeof("close") - 1);
}

static inline void http_PushString(Vector str, HttpString buffer) {
  char *bff = buffer.buffer;
  for(size_t i = 0, c = buffer.sz; i < c; i++) {
    vct_Push(str, &bff[i]);
  }
}

static inline void http_PushCharArray(Vector str, char *buffer) {
  for(size_t i = 0, c = strlen(buffer); i < c; i++) {
    vct_Push(str, &buffer[i]);
  }
}


void http_Request_AddTopString(PHttpRequest self, Vector str) {
  switch (self->url->method)
  {
    case GET: {
      http_PushString(str, (HttpString) {
        .buffer = "GET",
        .sz = sizeof("GET") - 1
      });
      break;
    }
    case POST: {
      http_PushString(str, (HttpString) {
        .buffer = "POST",
        .sz = sizeof("POST") - 1
      });
      break;
    }
    case PUT: {
      http_PushString(str, (HttpString) {
        .buffer = "PUT",
        .sz = sizeof("PUT") - 1
      });
      break;
    }
    case DELETE: {
      http_PushString(str, (HttpString) {
        .buffer = "DELETE",
        .sz = sizeof("DELETE") - 1
      });
      break;
    }
    case PATCH: {
      http_PushString(str, (HttpString) {
        .buffer = "PATCH",
        .sz = sizeof("PATCH") - 1
      });
      break;
    }
    default:
      break;
  }
  http_PushCharArray(str, " ");
  http_PushString(str, self->url->path);
  http_PushCharArray(str, " ");
  http_PushString(str, (HttpString) {
    .buffer = self->url->httpType,
    .sz = strlen(self->url->httpType)
  });
  http_PushCharArray(str, "\r\n");
}

void http_Request_PushHeaders(Hash header, Vector str) {
  Vector headersArr = trh_GetKeys(header.hash);
  Key *keys = headersArr->buffer;
  for(size_t i = 0, c = headersArr->size; i < c; i++) {
    HttpString valueBuffer = http_Hash_GetValue(header, keys[i].key, keys[i].keySize);
    if(!valueBuffer.buffer) {
      continue;
    }
    int32_t sz = snprintf(NULL, 0, "%.*s: %.*s\r\n", (int)keys[i].keySize, (char *)keys[i].key, (int)valueBuffer.sz, valueBuffer.buffer);
    char response[sz + 2];
    snprintf(response, sz + 2, "%.*s: %.*s\r\n", (int)keys[i].keySize, (char *)keys[i].key, (int)valueBuffer.sz, valueBuffer.buffer);
    http_PushString(str, (HttpString) {
      .buffer = response,
      .sz = sz
    });
  }
  http_PushCharArray(str, "\r\n");
  trh_FreeKeys(headersArr);
}

static inline void http_Request_PushBody(PHttpRequest self, Vector str) {
  http_PushString(str, *self->body);
}

// to do.
HttpString http_Request_ToString(PHttpRequest self) {
  Vector response = vct_Init(sizeof(char));
  http_Request_AddTopString(self, response);
  http_Request_PushHeaders(self->headers, response);
  http_Request_PushBody(self, response);
  HttpString rsp = {
    .buffer = response->buffer,
    .sz = response->size
  };
  vct_DeleteWOBuffer(response);
  return rsp;
}

void http_Response_SetJSON(PHttpResponse self) {
  http_Hash_Add(self->headers, "Content-Type", sizeof("Content-Type") - 1, "json", sizeof("json") - 1);
}

void http_Response_Set(PHttpResponse self, char *key, size_t keySize, char *value, size_t valueSize) {
  http_Hash_Add(self->headers, key, keySize, value, valueSize);
}

PHttpResponse http_Response_Empty() {
  PHttpResponse self = malloc(sizeof(HttpResponse));
  memset(self, 0, sizeof(HttpResponse));
  self->headers = http_Hash_Create();
  self->httpCode = "HTTP/1.1";
  self->response = 200;
  http_Request_SetBodySize(self, 0);
  return self;
}

PHttpResponse http_Response_Create() {
  PHttpResponse self = http_Response_Empty();
  http_Response_SetDefault(self);
  return self;
}

void http_Response_Delete(PHttpResponse self) {
  if(self->body.buffer) {
    free(self->body.buffer);
  }
  http_Hash_Delete(self->headers);
  free(self);
}