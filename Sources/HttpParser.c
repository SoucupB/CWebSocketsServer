#include "HttpParser.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Array.h"
#include "Hsh.h"
#include "String.h"

static inline PHttpMetaData http_InitMetadata();
static inline PURL http_URL_Init();
static inline void http_UpdateString(PHttpString string, char *buffer, char *_endBuffer);
uint8_t http_Route_Parse(PHttpRequest parent, PHttpString buffer);
static inline char *http_ChompString(PHttpString buff, char *like, uint8_t repeat);
uint8_t http_Header_Parse(Hash self, char *endBuffer, PHttpString buffer);
char *http_GetToken(PHttpString buffer, PHttpString token);
static inline char *http_ChompLineSeparator(PHttpString buffer);
static inline Hash http_Hash_Create();
HttpString http_Body_Process(Hash self, char *_endBuffer, PHttpString buffer);
static inline void http_SetBuffer(HttpString buffer, PHttpString nextPart, char *next);
PHttpResponse _http_Response_Empty(Hash headers);

#define ALPHANUMERIC "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_."
#define ACCEPTED_ALPHANUMERIC_KEY "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-.^_`|~"
#define ACCEPTED_ALPHANUMERIC_VALUE "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./;:<=>?@[\\]^_`{|}~ "
#define NUMBERS "0123456789"

PHttpRequest http_Request_Parse(char *buffer, size_t sz) {
  PHttpRequest self = crm_Alloc(sizeof(HttpRequest));
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
  if(!http_Header_Parse(self->headers, self->_endBuffer, &input)) {
    http_Request_Delete(self);
    return NULL;
  }
  self->body = http_Body_Process(self->headers, self->_endBuffer, &input);
  if(input.sz) {
    http_Request_Delete(self);
    return NULL;
  }
  return self;
}

PHttpRequest http_Request_NB_Get(PNetworkBuffer netBuffer) {
  char *stBuffer = tpd_StartingBuffer(netBuffer);
  char *endingBuffer;
  PHttpRequest req = http_Request_Chomp((HttpString) {
    .buffer = stBuffer,
    .sz = tpd_Size(netBuffer)
  }, &endingBuffer);
  if(!req) {
    return NULL;
  }
  const size_t nextSize = (size_t)(endingBuffer - stBuffer);
  tpd_Retract(netBuffer, nextSize);
  return req;
}

PHttpRequest http_Request_Chomp(HttpString bff, char **endBuffer) {
  if(!bff.sz) {
    return NULL;
  }
  for(size_t i = bff.sz; i >= 1; i--) {
    PHttpRequest httpReq = http_Request_Parse(bff.buffer, i);
    if(httpReq) {
      *endBuffer = (char *)bff.buffer + i;
      return httpReq;
    }
  }
  return NULL;
}

PHttpResponse http_Response_Chomp(HttpString bff, char **endBuffer) {
  if(!bff.sz) {
    return NULL;
  }
  for(size_t i = bff.sz; i >= 1; i--) {
    PHttpResponse httpReq = http_Response_Parse((HttpString) {
      .buffer = bff.buffer,
      .sz = i
    });
    if(httpReq) {
      *endBuffer = (char *)bff.buffer + i;
      return httpReq;
    }
  }
  return NULL;
}

PHttpResponse http_Response_NB_Get(PNetworkBuffer netBuffer) {
  char *stBuffer = tpd_StartingBuffer(netBuffer);
  char *endingBuffer;
  PHttpResponse res = http_Response_Chomp((HttpString) {
    .buffer = stBuffer,
    .sz = tpd_Size(netBuffer)
  }, &endingBuffer);
  if(!res) {
    return NULL;
  }
  const size_t nextSize = (size_t)(endingBuffer - stBuffer);
  tpd_Retract(netBuffer, nextSize);
  return res;
}

static inline PURL http_URL_Init() {
  PURL self = crm_Alloc(sizeof(URL));
  memset(self, 0, sizeof(URL));
  self->path.buffer = crm_Alloc(sizeof(char));
  self->path.buffer[0] = '/';
  self->path.sz = 1;
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
  hsh_Add(self.hash, key, keySize, value, valueSize);
  hsh_Add(self.valuesSize, key, keySize, &valueSize, sizeof(size_t));
}

char *http_Header_ParseLine(Hash self, char *endBuffer, PHttpString buffer) {
  char *key = http_ChompString(buffer, ACCEPTED_ALPHANUMERIC_KEY, 1);
  if(!key) {
    return NULL;
  }
  size_t keySize = (size_t)(key - buffer->buffer);
  char *keyOffset = buffer->buffer;
  http_UpdateString(buffer, key, endBuffer);

  char *separator = http_ChompString(buffer, ":", 0);
  if(!separator) {
    return NULL;
  }
  http_UpdateString(buffer, separator, endBuffer);

  char *space = http_ChompString(buffer, " ", 0);
  if(space) {
    http_UpdateString(buffer, space, endBuffer);
  }
  char *value = http_ChompString(buffer, ACCEPTED_ALPHANUMERIC_VALUE, 1);
  if(!value) {
    return NULL;
  }
  size_t valueSize = (size_t)(value - buffer->buffer);
  char *valueOffset = buffer->buffer;
  http_UpdateString(buffer, value, endBuffer);

  http_Hash_Add(self, keyOffset, keySize, valueOffset, valueSize);
  char *endOfLine = http_ChompLineSeparator(buffer);
  if(!endOfLine) {
    return NULL;
  }
  http_UpdateString(buffer, endOfLine, endBuffer);
  return endOfLine;
}

static inline Hash http_Hash_Create() {
  Hash hash;
  hash.hash = hsh_Create();
  hash.valuesSize = hsh_Create();
  return hash;
}

Hash http_Hash_DeepCopy(Hash hash) {
  Hash newHash = http_Hash_Create();
  Array keys = hsh_GetKeys(hash.hash);
  Key *bff = keys->buffer;
  for(size_t i = 0, c = keys->size; i < c; i++) {
    HttpString value = http_Hash_GetValue(hash, bff[i].key, bff[i].keySize);
    http_Hash_Add(newHash, bff[i].key, bff[i].keySize, value.buffer, value.sz);
  }
  hsh_FreeKeys(keys);
  return newHash;
}

static inline char *http_ChompLineSeparator(PHttpString buffer) {
  HttpString lineSeparator = {
    .buffer = "\r\n",
    .sz = sizeof("\r\n") - 1
  };
  return http_GetToken(buffer, &lineSeparator);
}

HttpString http_Request_GetValue(PHttpRequest self, char *buffer) {
  return http_Hash_GetValue(self->headers, buffer, strlen(buffer));
}

HttpString http_Hash_GetValue(Hash self, char *buffer, size_t bufferLen) {
  char *response = hsh_GetBuffer(self.hash, buffer, bufferLen);
  size_t *size = hsh_GetBuffer(self.valuesSize, buffer, bufferLen);
  return (HttpString){
    .buffer = response,
    .sz = size ? *size : 0
  };
}

uint8_t http_Header_Parse(Hash self, char *endBuffer, PHttpString buffer) {
  char *buff;
  HttpString cpyStr = *buffer;
  while((buff = http_Header_ParseLine(self, endBuffer, &cpyStr)) && buff);
  char *endOfLine = http_ChompLineSeparator(&cpyStr);
  if(!endOfLine) {
    return 0;
  }
  http_UpdateString(buffer, endOfLine, endBuffer);
  return 1;
}

static inline PHttpMetaData http_InitMetadata() {
  PHttpMetaData metaData = crm_Alloc(sizeof(HttpMetaData));
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

ssize_t http_Parse_Number(char *buffer, size_t sz, char **endBufer) {
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

ssize_t http_Get_Number(Hash self, char *key, uint8_t *isValid) {
  *isValid = 0;
  HttpString value = http_Hash_GetValue(self, key, strlen(key));
  if(!value.buffer) {
    return 0;
  }
  char *endPtr;
  ssize_t number = http_Parse_Number(value.buffer, value.sz, &endPtr);
  if(endPtr != value.buffer + value.sz) {
    return 0;
  }
  *isValid = 1;
  return number;
}

HttpString http_Body_Chomp_t(PHttpString buffer, ssize_t contentLength) {
  if(contentLength > buffer->sz) {
    return (HttpString) {
      .buffer = NULL
    };
  }
  HttpString response;
  response.buffer = crm_Alloc(contentLength);
  response.sz = (size_t)contentLength;
  memcpy(response.buffer, buffer->buffer, response.sz);
  return response;
}

char *http_Body_Chomp(Hash self, PHttpString buffer, HttpString *response) {
  uint8_t valid;
  ssize_t contentLength = http_Get_Number(self, "Content-Length", &valid);
  if(!valid || contentLength < 0) {
    return NULL;
  }
  HttpString body = http_Body_Chomp_t(buffer, contentLength);
  if(!body.buffer) {
    return NULL;
  }
  *response = body;
  return buffer->buffer + body.sz;
}

HttpString http_Body_Process(Hash self, char *_endBuffer, PHttpString buffer) {
  HttpString body;
  char *bodyBuffer = http_Body_Chomp(self, buffer, &body);
  if(!bodyBuffer) {
    return (HttpString) {
      .buffer = NULL
    };
  }
  http_UpdateString(buffer, bodyBuffer, _endBuffer);
  return body;
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

static inline void http_UpdateString(PHttpString string, char *buffer, char *_endBuffer) {
  string->buffer = buffer;
  string->sz = (size_t)(_endBuffer - buffer);
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

PHttpResponse http_Response_DeepCopy(PHttpResponse self) {
  Hash newHeaders = http_Hash_DeepCopy(self->headers);
  PHttpResponse newResponse = _http_Response_Empty(newHeaders);
  newResponse->httpCode = self->httpCode;
  newResponse->response = self->response;
  newResponse->body = string_DeepCopy(self->body);
  return newResponse;
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
    http_UpdateString(&cpyBuffer, bff, parent->_endBuffer);
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
  http_UpdateString(&cpyString, bff, parent->_endBuffer);

  bff = http_ChompString(&cpyString, "/", 0);
  if(!bff) {
    return NULL;
  }
  http_UpdateString(&cpyString, bff, parent->_endBuffer);

  bff = http_ChompString(&cpyString, ALPHANUMERIC, 1);
  if(!bff) {
    return NULL;
  }
  http_UpdateString(&cpyString, bff, parent->_endBuffer);
  return bff;
}

void http_URL_Set(PURL url, HttpString buffer) {
  if(url->path.buffer) {
    crm_Free(url->path.buffer);
  }
  url->path.buffer = crm_Alloc(buffer.sz);
  memcpy(url->path.buffer, buffer.buffer, buffer.sz);
  url->path.sz = buffer.sz;
}

char *http_Route_Parse_t(PHttpRequest parent, PHttpString buffer) {
  char *codesBuffer = http_Route_ParseCodes(parent, buffer);
  if(!codesBuffer) {
    return NULL;
  }
  http_UpdateString(buffer, codesBuffer, parent->_endBuffer);

  char *chompedSpace = http_ChompString(buffer, " ", 0);
  if(!chompedSpace) {
    return NULL;
  }
  http_UpdateString(buffer, chompedSpace, parent->_endBuffer);

  char *path = http_Path_Parse(parent, buffer);
  if(!path) {
    return NULL;
  }
  size_t bffSize = (size_t)(path - buffer->buffer);
  http_URL_Set(parent->url, (HttpString) {
    .buffer = buffer->buffer,
    .sz = bffSize
  });
  http_UpdateString(buffer, path, parent->_endBuffer);
  
  chompedSpace = http_ChompString(buffer, " ", 0);
  if(!chompedSpace) {
    return NULL;
  }
  http_UpdateString(buffer, chompedSpace, parent->_endBuffer);

  char *httpType = http_Route_ParseType(parent, buffer);
  if(!httpType) {
    return NULL;
  }
  size_t mthSize = (size_t)(httpType - buffer->buffer);
  if(mthSize >= sizeof(parent->url->httpType)) {
    return NULL;
  }
  memcpy(parent->url->httpType, buffer->buffer, mthSize);
  http_UpdateString(buffer, httpType, parent->_endBuffer);

  chompedSpace = http_ChompLineSeparator(buffer);
  if(!chompedSpace) {
    return NULL;
  }
  http_UpdateString(buffer, chompedSpace, parent->_endBuffer);
  return buffer->buffer;
}

uint8_t http_Route_Parse(PHttpRequest parent, PHttpString buffer) {
  HttpString nextBuffer = *buffer;
  char *urlParse = http_Route_Parse_t(parent, &nextBuffer);
  if(!urlParse) {
    return 0;
  }
  http_UpdateString(buffer, urlParse, parent->_endBuffer);
  return 1;
}

void http_URL_Free(PURL self) {
  if(!self) {
    return ;
  }
  if(self->path.buffer) {
    crm_Free(self->path.buffer);
  }
  crm_Free(self);
}

static inline void http_Hash_Delete(Hash self) {
  hsh_Delete(self.hash);
  hsh_Delete(self.valuesSize);
}

void http_Metadata_Delete(PHttpMetaData self) {
  crm_Free(self);
}

void http_Request_Delete(PHttpRequest self) {
  if(self->body.buffer) {
    crm_Free(self->body.buffer);
  }
  http_URL_Free(self->url);
  http_Hash_Delete(self->headers);
  http_Metadata_Delete(self->metadata);
  crm_Free(self);
}

void http_SetBodySize(Hash hash, size_t sz) {
  char buffer[20] = {0};
  snprintf(buffer, sizeof(buffer), "%zu", sz);
  http_Hash_Add(hash, "Content-Length", sizeof("Content-Length") - 1, buffer, strlen(buffer));
}

static inline void http_Response_SetBodySize(PHttpResponse self, size_t sz) {
  http_SetBodySize(self->headers, sz);
}

static inline void http_Request_SetBodySize(PHttpRequest self, size_t sz) {
  http_SetBodySize(self->headers, sz);
}

void http_Response_SetBody(PHttpResponse self, PHttpString buffer) {
  if(self->body.buffer) {
    crm_Free(self->body.buffer);
  }
  self->body.buffer = crm_Alloc(buffer->sz);
  memcpy(self->body.buffer, buffer->buffer, buffer->sz);
  self->body.sz = buffer->sz;
  http_Response_SetBodySize(self, buffer->sz);
}

static inline size_t http_Response_Size(Hash headers, Array headersArr) {
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

char *http_FormatHeaders(Hash headers, Array headersArr, char *buffer, size_t bufferSize) {
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

char *http_Response_ResponseString(PHttpResponse self) {
  if(self->response >= 200 && self->response <= 299) {
    return "OK";
  }
  if(self->response >= 400 && self->response <= 499) {
    return "Bad Request";
  }
  return "Undefined";
}

HttpString http_Response_ToString(PHttpResponse self) {
  char messageHeader[64] = {0};
  // this is bugged, needs fix.
  snprintf(messageHeader, sizeof(messageHeader), "%s %u %s\r\n", self->httpCode, self->response, http_Response_ResponseString(self));
  Array headersArr = hsh_GetKeys(self->headers.hash);
  size_t requestSize = http_Response_Size(self->headers, headersArr);
  size_t headerSizeCode = strlen(messageHeader);
  size_t bufferSize = headerSizeCode + requestSize + self->body.sz + 5;
  char *buffer = crm_Alloc(bufferSize);
  char *cpyBuffer = buffer;
  memcpy(cpyBuffer, messageHeader, headerSizeCode);
  cpyBuffer += headerSizeCode;
  cpyBuffer = http_FormatHeaders(self->headers, headersArr, cpyBuffer, requestSize);
  if(self->body.buffer) {
    memcpy(cpyBuffer, self->body.buffer, self->body.sz);
    cpyBuffer += self->body.sz;
  }
  hsh_FreeKeys(headersArr);
  return (HttpString) {
    .buffer = buffer,
    .sz = (size_t)(cpyBuffer - buffer)
  };
}

void http_Response_SetDefault(PHttpResponse self) {
  http_Hash_Add(self->headers, "Content-Type", sizeof("Content-Type") - 1, "text/plain", sizeof("text/plain") - 1);
  http_Hash_Add(self->headers, "Connection", sizeof("Connection") - 1, "close", sizeof("close") - 1);
}

static inline void http_PushString(Array str, HttpString buffer) {
  char *bff = buffer.buffer;
  for(size_t i = 0, c = buffer.sz; i < c; i++) {
    arr_Push(str, &bff[i]);
  }
}

static inline void http_PushCharArray(Array str, char *buffer) {
  for(size_t i = 0, c = strlen(buffer); i < c; i++) {
    arr_Push(str, &buffer[i]);
  }
}


void http_Request_AddTopString(PHttpRequest self, Array str) {
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

void http_Request_PushHeaders(Hash header, Array str) {
  Array headersArr = hsh_GetKeys(header.hash);
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
  hsh_FreeKeys(headersArr);
}

static inline void http_Request_PushBody(PHttpRequest self, Array str) {
  http_PushString(str, self->body);
}

HttpString http_Request_ToString(PHttpRequest self) {
  Array response = arr_Init(sizeof(char));
  http_Request_AddTopString(self, response);
  http_Request_PushHeaders(self->headers, response);
  http_Request_PushBody(self, response);
  HttpString rsp = {
    .buffer = response->buffer,
    .sz = response->size
  };
  arr_DeleteWOBuffer(response);
  return rsp;
}

HttpString http_Request_GetPath(PHttpRequest self) {
  return self->url->path;
}

HttpString http_Request_GetBody(PHttpRequest self) {
  return self->body;
}

PHttpRequest http_Request_Create() {
  PHttpRequest self = crm_Alloc(sizeof(HttpRequest));
  memset(self, 0, sizeof(HttpRequest));
  self->url = http_URL_Init();
  self->metadata = http_InitMetadata();
  self->headers = http_Hash_Create();
  self->url->method = GET;
  memcpy(self->url->httpType, "HTTP/1.1", sizeof("HTTP/1.1"));
  return self;
}

PHttpRequest http_Request_Basic() {
  PHttpRequest self = crm_Alloc(sizeof(HttpRequest));
  memset(self, 0, sizeof(HttpRequest));
  self->url = http_URL_Init();
  self->metadata = http_InitMetadata();
  self->headers = http_Hash_Create();
  self->url->method = GET;
  http_Request_AddHeader(self, "Accept", "*/*");
  http_Request_AddHeader(self, "Accept-Encoding", "gzip, deflate, br");
  http_Request_AddHeader(self, "Connection", "keep-alive");
  memcpy(self->url->httpType, "HTTP/1.1", sizeof("HTTP/1.1"));
  return self;
}

void http_Request_AddHeader(PHttpRequest self, char *key, char *value) {
  http_Hash_Add(self->headers, key, strlen(key), value, strlen(value));
}

HttpString http_String_Copy(HttpString str) {
  HttpString response;
  response.sz = str.sz;
  response.buffer = crm_Alloc(str.sz);
  memcpy(response.buffer, str.buffer, str.sz);
  return response;
}

void http_Request_SetBody(PHttpRequest self, HttpString str) {
  HttpString resp;
  resp = http_String_Copy(str);
  self->body = resp;
  http_Request_SetBodySize(self, str.sz);
}

void http_Response_SetJSON(PHttpResponse self) {
  http_Hash_Add(self->headers, "Content-Type", sizeof("Content-Type") - 1, "json", sizeof("json") - 1);
}

void http_Response_Set(PHttpResponse self, char *key, size_t keySize, char *value, size_t valueSize) {
  http_Hash_Add(self->headers, key, keySize, value, valueSize);
}

PHttpResponse _http_Response_Empty(Hash headers) {
  PHttpResponse self = crm_Alloc(sizeof(HttpResponse));
  memset(self, 0, sizeof(HttpResponse));
  self->headers = headers;
  self->httpCode = "HTTP/1.1";
  self->response = 200;
  http_Response_SetBodySize(self, 0);
  return self;
}

PHttpResponse http_Response_Empty() {
  Hash newHash = http_Hash_Create();
  return _http_Response_Empty(newHash);
  // PHttpResponse self = crm_Alloc(sizeof(HttpResponse));
  // memset(self, 0, sizeof(HttpResponse));
  // self->headers = http_Hash_Create();
  // self->httpCode = "HTTP/1.1";
  // self->response = 200;
  // http_Response_SetBodySize(self, 0);
  // return self;
}

uint8_t http_Response_ParseCurrentToken(PHttpString buffer, PHttpString token, PHttpString nextPart) {
  char *next = http_GetToken(buffer, token);
  if(!next) {
    return 0;
  }
  http_SetBuffer(*buffer, nextPart, next);
  return 1;
}

uint8_t http_Response_ParseHttpVersion(PHttpString buffer) {
  size_t index = 0;
  while(index < buffer->sz && (buffer->buffer[index] != ' ')) {
    if(buffer->buffer[index] == '\n' || buffer->buffer[index] == '\r') {
      return 0;
    }
    index++;
  }
  buffer->sz = buffer->sz - index;
  buffer->buffer += (size_t)index;
  return 1;
}

uint8_t http_Response_ParseCode(PHttpString buffer) {
  HttpString token = {
    .buffer = "HTTP/",
    .sz = sizeof("HTTP/") - 1
  };
  if(!http_Response_ParseCurrentToken(buffer, &token, buffer)) {
    return 0;
  }
  return http_Response_ParseHttpVersion(buffer);
}

uint8_t http_Response_ParseEmptySpace(PHttpString buffer) {
  HttpString token = {
    .buffer = " ",
    .sz = sizeof(" ") - 1
  };
  return http_Response_ParseCurrentToken(buffer, &token, buffer);
}

uint8_t http_Response_ParseLineSeparator(PHttpString buffer) {
  HttpString token = {
    .buffer = "\r\n",
    .sz = sizeof("\r\n") - 1
  };
  return http_Response_ParseCurrentToken(buffer, &token, buffer);
}

static inline void http_Response_SetCode(PHttpResponse self, char *buffer) {
  self->response = (buffer[0] - '0') * 100 + (buffer[1] - '0') * 10 + (buffer[2] - '0');
}

static inline void http_SetBuffer(HttpString buffer, PHttpString nextPart, char *next) {
  *nextPart = (HttpString) {
    .buffer = next,
    .sz = (size_t)((buffer.buffer + buffer.sz) - next)
  };
}

uint8_t http_Response_ParseHttpCode(PHttpResponse self, PHttpString buffer) {
  char *next = http_ChompString(buffer, NUMBERS, 1);
  if(!next || (next - buffer->buffer != 0x3)) {
    return 0;
  }
  http_Response_SetCode(self, buffer->buffer);
  http_SetBuffer(*buffer, buffer, next);
  return 1;
}

uint8_t http_Response_ParseMessage(PHttpString buffer) {
  char *next = http_ChompString(buffer, ACCEPTED_ALPHANUMERIC_VALUE, 1);
  if(!next) {
    return 0;
  }
  http_SetBuffer(*buffer, buffer, next);
  return 1;
}

uint8_t http_Response_ParseBody(PHttpResponse self, PHttpServer buffer) {
  return 1;
}

PHttpResponse http_Response_Parse(HttpString buffer) {
  HttpString cpyBuffer = buffer;
  if(!http_Response_ParseCode(&cpyBuffer)) {
    return NULL;
  }
  if(!http_Response_ParseEmptySpace(&cpyBuffer)) {
    return NULL;
  }
  char *_endBuffer = buffer.buffer + buffer.sz;
  PHttpResponse self = http_Response_Empty();
  if(!http_Response_ParseHttpCode(self, &cpyBuffer)) {
    http_Response_Delete(self);
    return NULL;
  }
  if(!http_Response_ParseEmptySpace(&cpyBuffer)) {
    http_Response_Delete(self);
    return NULL;
  }
  if(!http_Response_ParseMessage(&cpyBuffer)) {
    http_Response_Delete(self);
    return NULL;
  }
  if(!http_Response_ParseLineSeparator(&cpyBuffer)) {
    http_Response_Delete(self);
    return NULL;
  }
  if(!http_Header_Parse(self->headers, _endBuffer, &cpyBuffer)) {
    http_Response_Delete(self);
    return NULL;
  }
  self->body = http_Body_Process(self->headers, _endBuffer, &cpyBuffer);
  if(cpyBuffer.sz) {
    http_Response_Delete(self);
    return NULL;
  }
  return self;
}

HttpString http_Response_GetValue(PHttpResponse self, char *buffer) {
  return http_Hash_GetValue(self->headers, buffer, strlen(buffer));
}

PHttpResponse http_Response_Create() {
  PHttpResponse self = http_Response_Empty();
  http_Response_SetDefault(self);
  return self;
}

void http_Response_Delete(PHttpResponse self) {
  if(self->body.buffer) {
    crm_Free(self->body.buffer);
  }
  http_Hash_Delete(self->headers);
  crm_Free(self);
}