#include "EventMessage.h"
#include <string.h>
#include <stdlib.h>

static inline uint8_t evm_Out_IsAuthed(const PEventMessage self) {
  return self->isAuthed;
}

static inline char *evm_Out_PayloadSizePointer(const PEventMessage self, char *buffer) {
  return buffer;
}

static inline char *evm_Out_HeaderPointer(const PEventMessage self, char *buffer) {
  return buffer + sizeof(self->str.size);
}

static inline char *evm_Out_HeaderAuthPointer(const PEventMessage self, char *buffer) {
  if(!evm_Out_IsAuthed(self)) {
    return NULL;
  }
  return evm_Out_HeaderPointer(self, buffer) + sizeof(self->headerCode);
}

static inline char *evm_Out_PayloadPointer(const PEventMessage self, char *buffer) {
  if(!evm_Out_IsAuthed(self)) {
    return evm_Out_HeaderPointer(self, buffer) + sizeof(self->headerCode);
  }
  return evm_Out_HeaderPointer(self, buffer) + sizeof(self->headerCode) + sizeof(Auth);
}

static inline char *evm_In_SizePointer(char *buffer) {
  return buffer;
}

static inline char *evm_In_HeaderPointer(char *buffer) {
  return evm_In_SizePointer(buffer) + sizeof(uint32_t);
}

static inline uint32_t evm_In_Size(char *buffer) {
  return *(uint32_t *)evm_In_SizePointer(buffer);
}

static inline uint32_t evm_In_Header(char *buffer) {
  return *(uint32_t *)evm_In_HeaderPointer(buffer);
}

static inline uint32_t evm_In_HeaderCode(char *buffer) {
  return (evm_In_Header(buffer) & 0xFFFFFF);
}

static inline uint8_t evm_In_HeaderIsAuth(char *buffer) {
  return (evm_In_Header(buffer) & (1<<24)) != 0; 
}

static inline char *evm_In_AuthPointer(char *buffer) {
  if(!evm_In_HeaderIsAuth(buffer)) {
    return NULL;
  }
  return evm_In_HeaderPointer(buffer) + sizeof(uint32_t);
}

static inline char *evm_In_PayloadPointer(char *buffer) {
  return evm_In_HeaderPointer(buffer) + ((size_t)evm_In_AuthPointer(buffer) != 0) * sizeof(Auth) + sizeof(uint32_t);
}

static inline char *evm_In_EndPointer(char *buffer) {
  return evm_In_PayloadPointer(buffer) + evm_In_Size(buffer);
}

static inline uint32_t evm_Out_TotalSize(const PEventMessage self) {
  return self->str.size + sizeof(self->headerCode) + sizeof(self->str.size) + sizeof(Auth) * evm_Out_IsAuthed(self);
}

uint32_t evm_Out_Public_TotalSize(PEventMessage self) {
  return evm_Out_TotalSize(self);
}

EventBuffer evm_Reuse_Transform(const PEventMessage self, char *buffer) {
  uint32_t totalSize = evm_Out_TotalSize(self);
  memcpy(evm_Out_PayloadSizePointer(self, buffer), &self->str.size, sizeof(self->str.size));
  uint32_t mergedHeaders = (self->headerCode | ((1<<24) * self->isAuthed));
  memcpy(evm_Out_HeaderPointer(self, buffer), &mergedHeaders, sizeof(mergedHeaders));
  char *headerPointer = evm_Out_HeaderAuthPointer(self, buffer);
  if(headerPointer) {
    memcpy(headerPointer, self->uniqueCode.bff, sizeof(self->uniqueCode));
  }
  memcpy(evm_Out_PayloadPointer(self, buffer), self->str.buffer, self->str.size);
  return (EventBuffer) {
    .buffer = buffer,
    .size = totalSize
  };
}

EventBuffer evm_New_Transform(const PEventMessage self) {
  uint32_t totalSize = evm_Out_TotalSize(self);
  char *buffer = malloc(totalSize);
  return evm_Reuse_Transform(self, buffer);
}

EventMessage evm_Parse(EventBuffer inp, uint8_t *valid) {
  *valid = 0;
  char *endBuffer = evm_In_EndPointer(inp.buffer);
  if(endBuffer != inp.size + inp.buffer) {
    return (EventMessage) {};
  }
  EventMessage response = (EventMessage) {
    .isAuthed = evm_In_HeaderIsAuth(inp.buffer),
    .headerCode = evm_In_HeaderCode(inp.buffer),
    .str = (EventBuffer) {
      .buffer = evm_In_PayloadPointer(inp.buffer),
      .size = evm_In_Size(inp.buffer)
    }
  };
  char *authCode = evm_In_AuthPointer(inp.buffer);
  if(authCode) {
    memcpy(response.uniqueCode.bff, authCode, sizeof(Auth));
  }
  *valid = 1;
  return response;
}
#include "EventServer.h"
#include <string.h>
#define MAX_BYTES_SWITCH_STACK (1<<12)

static inline void evs_ProcessClosingConn(PEventServer self, PConnection conn) {
  if(self->onClose) {
    void (*method)(PConnection, void *) = self->onClose->method;
    method(conn, self->onClose->mirrorBuffer);
  }
}

static inline void evs_PushEventBuffer(PEventServer self, PEventBuffer bff, PConnection conn) {
  DataFragment nextFrag = {
    .conn = *conn,
    .data = bff->buffer,
    .size = bff->size
  };
  wss_SendMessage(self->wsServer, &nextFrag);
}

void evs_PushMessage(PEventServer self, PResponseObject msg) {
  uint32_t msgSize = evm_Out_Public_TotalSize(&msg->metaData);
  if(msgSize < MAX_BYTES_SWITCH_STACK) {
    char buffer[MAX_BYTES_SWITCH_STACK];
    EventBuffer response = evm_Reuse_Transform(&msg->metaData, buffer);
    evs_PushEventBuffer(self, &response, msg->conn);
    return ;
  }
  char *buffer = malloc(msgSize);
  EventBuffer response = evm_Reuse_Transform(&msg->metaData, buffer);
  evs_PushEventBuffer(self, &response, msg->conn);
  free(buffer);
}

void _evs_OnClose(Connection conn, void *buffer) {
  evs_ProcessClosingConn(buffer, &conn);
}

void _evs_OnReceive(PDataFragment frag, void *buffer) {
  PEventServer self = buffer;
  uint8_t valid;
  EventMessage currentMessage = evm_Parse((EventBuffer) {
    .buffer = frag->data,
    .size = frag->size
  }, &valid);
  if(!valid) {
    evs_ProcessClosingConn(self, &frag->conn);
    sock_PushCloseConnections(self->wsServer->socketServer, &frag->conn);
    return ;
  }
  if(self->onReceive) {
    void (*method)(PResponseObject, void *) = self->onReceive->method;
    ResponseObject rsp = (ResponseObject) {
      .conn = &frag->conn,
      .metaData = currentMessage
    };
    method(&rsp, self->onReceive->mirrorBuffer);
  }
}

static inline void evs_RegisterMethods(PEventServer self) {
  PSocketMethod _onReceive = sock_Method_Create(
    _evs_OnReceive,
    self
  );
  self->wsServer->onReceiveMessage = _onReceive;
  PSocketMethod _onClose = sock_Method_Create(
    _evs_OnClose,
    self
  );
  self->wsServer->onRelease = _onClose;
}

PEventServer evs_Create(uint16_t port) {
  PEventServer self = malloc(sizeof(EventServer));
  memset(self, 0, sizeof(EventServer));
  self->wsServer = wss_Create(port);
  evs_RegisterMethods(self);
  return self;
}

void evs_FreeMethods(PEventServer self) {
  sock_Method_Delete(self->wsServer->onReceiveMessage);
  sock_Method_Delete(self->wsServer->onRelease);
}

void evs_OnFrame(PEventServer self, uint64_t deltaMS) {
  wss_OnFrame(self->wsServer, deltaMS);
}

void evs_Delete(PEventServer self) {
  evs_FreeMethods(self);
  wss_Delete(self->wsServer);
  free(self);
}
#include "FixedMemoryPool.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

static inline size_t fmp_MemoryFragmentSize(size_t objSize) {
  return sizeof(MemoryFragment) - sizeof(void *) + objSize;
}

static inline void fmp_PrepareMemory(const PFixedMemoryPool self) {
  if(self->bufferFragments) {
    return ;
  }
  self->bufferFragments = (MemoryFragment *)malloc(sizeof(MemoryFragment) * self->capacity);
  size_t totalSize = fmp_MemoryFragmentSize(self->objSize) * self->capacity;
  self->memory = malloc(totalSize);
  self->_endBuffer = (char *)self->memory + totalSize;
  char *memory = self->memory;
  for(size_t i = 0, c = self->capacity; i < c; i++) {
    self->bufferFragments[i] = (MemoryFragment) {
      .flag = (size_t *)memory,
      .self = (PMemoryFragment *)(memory + sizeof(size_t *)),
      .buffer = (void *)(memory + sizeof(size_t *) + sizeof(PMemoryFragment *))
    };
    *self->bufferFragments[i].flag = 0;
    *self->bufferFragments[i].self = &self->bufferFragments[i];
    memory += fmp_MemoryFragmentSize(self->objSize);
  }
}

void fmp_PrintMemory(PFixedMemoryPool self) {
  for(size_t i = 0, c = self->capacity * fmp_MemoryFragmentSize(self->objSize); i < c; i++) {
    printf("%d ", ((uint8_t *)self->memory)[i]);
  }
  printf("\n");
}

static inline FreeStackTracker stack_Init(size_t capacity) {
  FreeStackTracker self;
  self.stack = malloc(sizeof(PMemoryFragment) * capacity);
  self.sz = 0;
  return self;
}

PFixedMemoryPool fmp_InitWithCapacity(size_t objSize, size_t capacity) {
  PFixedMemoryPool self = malloc(sizeof(FixedMemoryPool));
  memset(self, 0, sizeof(FixedMemoryPool));
  self->objSize = objSize;
  self->capacity = capacity;
  self->freeStack = stack_Init(capacity);
  return self;
}

PFixedMemoryPool fmp_Init(size_t objSize) {
  return fmp_InitWithCapacity(objSize, 128);
}

static inline void *fmp_NormalMem(const PFixedMemoryPool self) {
  MemoryFragment fragment = self->bufferFragments[self->count];
  *fragment.flag = 1;
  self->count++;
  return fragment.buffer;
}

static inline PMemoryFragment fmp_StartingPointer(void *buffer) {
  return *(PMemoryFragment *)((char *)buffer - sizeof(PFixedMemoryPool *));
}

static inline void stack_Push(PFreeStackTracker self, PMemoryFragment *memory) {
  memcpy((char *)self->stack + self->sz * sizeof(PMemoryFragment), memory, sizeof(PMemoryFragment));
  self->sz++;
}

static inline PFixedMemoryPool fmp_FindPool(const PFixedMemoryPool self, const void *buffer) {
  PFixedMemoryPool current = self;
  while(1) {
    if(!current) {
      return NULL;
    }
    if(current->memory <= buffer && current->_endBuffer >= buffer) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void fmp_Free(PFixedMemoryPool self, void *buffer) {
  PFixedMemoryPool currentPool = fmp_FindPool(self, buffer);
  assert(currentPool != NULL);
  PMemoryFragment currentMemoryFragment = fmp_StartingPointer(buffer);
  assert(*currentMemoryFragment->flag == 1);
  stack_Push(&currentPool->freeStack, currentMemoryFragment->self);
  *currentMemoryFragment->flag = 0;
  currentPool->count--;
}

PMemoryFragment stack_Pop(PFixedMemoryPool self) {
  PFreeStackTracker currentStack = &self->freeStack;
  PMemoryFragment frag = *(PMemoryFragment *)(currentStack->stack + sizeof(PMemoryFragment) * (currentStack->sz - 1));
  currentStack->sz--;
  *frag->flag = 1;
  self->count++;
  return frag;
}

void fmp_Delete(PFixedMemoryPool self) {
  if(!self) {
    return ;
  }
  fmp_Delete(self->next);
  if(self->bufferFragments) {
    free(self->bufferFragments);
  }
  if(self->memory) {
    free(self->memory);
  }
  free(self->freeStack.stack);
  free(self);
}

void *fmp_NextBlock(PFixedMemoryPool self) {
  if(self->next) {
    return fmp_Alloc(self->next);
  }
  PFixedMemoryPool newBuffer = fmp_InitWithCapacity(self->objSize, self->capacity * 10);
  self->next = newBuffer;
  return fmp_Alloc(newBuffer);
}

void *fmp_Alloc(PFixedMemoryPool self) {
  if(self->count >= self->capacity) {
    return fmp_NextBlock(self);
  }
  fmp_PrepareMemory(self);
  if(self->freeStack.sz) {
    return stack_Pop(self)->buffer;
  }
  return fmp_NormalMem(self);
}
#include "HttpParser.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

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
#include "SocketServer.h"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>
#include <sys/ioctl.h>

#define SA struct sockaddr
#define MAX_CONNECTIONS_PER_SERVER 1024
#define MAX_BYTES_SWITCH_STACK (1<<12)

typedef struct CloseConnStruct_t {
  PSocketServer self;
  Connection conn;
  size_t index;
} CloseConnStruct;

typedef CloseConnStruct *PCloseConnStruct;

uint8_t _sock_StartConnections(PSocketServer self);

void sigpipe_handler(int signum) {
  return ;
}

PSocketServer sock_Create(uint16_t port) {
  PSocketServer server = malloc(sizeof(SocketServer));
  memset(server, 0, sizeof(SocketServer));
  server->connections = vct_Init(sizeof(Connection));
  server->port = port;
  server->maxActiveConnections = 16;
  server->maxBytesPerReadConnection = 1024 * 1024 * 10; /* 10 megabytes of reading per socket of total bytes */
  server->inputReads = vct_Init(sizeof(DataFragment));
  server->outputCommands = vct_Init(sizeof(DataFragment));
  server->closeConnectionsQueue = vct_Init(sizeof(Connection));
  if(!_sock_StartConnections(server)) {
    sock_Delete(server);
    return NULL;
  }
  return server;
}

void _sock_CloseConnection(void *buffer) {
  PCloseConnStruct conn = buffer;
  close(conn->conn.fd);
  vct_RemoveElement(conn->self->connections, conn->index);
  free(buffer);
}

void sock_PushCloseConnMethod(PSocketServer self, Connection conn, size_t index) {
  if(!self->timeServer.timeServer) {
    return ;
  }
  PCloseConnStruct closeCmd = malloc(sizeof(CloseConnStruct));
  closeCmd->conn = conn;
  closeCmd->self = self;
  closeCmd->index = index;
  TimeMethod timeFragment = (TimeMethod) {
    .method = (void *)_sock_CloseConnection,
    .buffer = closeCmd
  };
  tf_ExecuteAfter(self->timeServer.timeServer, timeFragment, self->timeServer.timeout);
}

void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections) {
  assert(maxActiveConnections < MAX_CONNECTIONS_PER_SERVER);
  self->maxActiveConnections = maxActiveConnections;
}

void sock_Write_Push(PSocketServer self, DataFragment *dt) {
  char *memory = dt->data;
  if(dt->persistent) {
    memory = malloc(dt->size);
    memcpy(memory, dt->data, dt->size);
  }
  DataFragment newDt = *dt;
  newDt.data = memory;
  vct_Push(self->outputCommands, &newDt);
}

uint8_t _sock_StartConnections(PSocketServer self) {
  int32_t sockfd;
  struct sockaddr_in servaddr;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    return 0;
  }
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(self->port);
  signal(SIGPIPE, sigpipe_handler);
  const int32_t trueFlag = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &trueFlag, sizeof(int)) < 0) {
    return 0;
  }
  if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
    return 0;
  }
  if ((listen(sockfd, 5)) != 0) {
    return 0;
  }
  self->serverFD.fd = sockfd;
  fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
  return 1;
}

static inline void sock_ExecuteMetaMethod(Connection *conn, PSocketMethod routine) {
  if(!routine) {
    return ;
  }
  void (*method)(Connection, void *) = routine->method;
  method(*conn, routine->mirrorBuffer);
}

static inline void sock_ExecuteOnReceiveMethod(DataFragment *dataFragment, PSocketMethod routine) {
  if(!routine) {
    return ;
  }
  void (*method)(DataFragment *, void *) = routine->method;
  method(dataFragment, routine->mirrorBuffer);
}

void sock_AddConnectionTimeout(PSocketServer self, int64_t expireAfter) {
  self->timeServer.timeServer = tf_Create();
  self->timeServer.timeout = expireAfter;
}

static inline void sock_ReadData(PSocketServer self, Connection *conn, char *buffer, size_t count) {
  (void)!read(conn->fd, buffer, count);
  DataFragment dt = (DataFragment) {
    .conn = *conn,
    .data = buffer,
    .persistent = 0,
    .size = count
  };
  sock_ExecuteOnReceiveMethod(&dt, self->onReceiveMessage);
}

static inline ssize_t sock_FindConnIndex(PSocketServer self, PConnection conn) {
  Connection *connections = self->connections->buffer;
  for(ssize_t i = 0, c = (ssize_t)self->connections->buffer; i < c; i++) {
    if(conn->fd == connections[i].fd) {
      return i;
    }
  }
  return -1;
}

void sock_CloseConnection(PSocketServer self, size_t index) {
  Connection conn = ((Connection *)self->connections->buffer)[index];
  close(conn.fd);
  vct_RemoveElement(self->connections, index);
}

// This method will not trigger a release callback.
void sock_PushCloseConnections(PSocketServer self, PConnection conn) {
  ssize_t connectionIndex = sock_FindConnIndex(self, conn);
  if(connectionIndex < 0) {
    return ;
  }
  vct_Push(self->closeConnectionsQueue, &conn);
}

uint8_t sock_DoesConnectionExists(PSocketServer self, PConnection conn) {
  Connection *connections = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    if(connections[i].fd == conn->fd) {
      return 1;
    }
  }
  return 0;
}

void sock_ClearPushedConnections(PSocketServer self) {
  Connection *connections = self->closeConnectionsQueue->buffer;
  for(size_t i = 0, c = self->closeConnectionsQueue->size; i < c; i++) {
    if(sock_DoesConnectionExists(self, &connections[i])) {
      close(connections[i].fd);
    }
  }
  vct_Clear(self->closeConnectionsQueue);
}

static inline void sock_OnReceiveMessage(PSocketServer self, Connection *conn, size_t index) {
  size_t count = 0;
  int32_t error = ioctl(conn->fd, FIONREAD, &count);
  if(!count || error == -1) {
    return ;
  }
  if(count >= self->maxBytesPerReadConnection) {
    sock_ExecuteMetaMethod(conn, self->onConnectionRelease);
    sock_CloseConnection(self, index);
    return ;
  }
  if(count <= MAX_BYTES_SWITCH_STACK) {
    char buffer[MAX_BYTES_SWITCH_STACK];
    sock_ReadData(self, conn, buffer, count);
    return ;
  }
  void *buffer = malloc(count);
  sock_ReadData(self, conn, buffer, count);
  free(buffer);
}

void sock_ProcessReadMessage(PSocketServer self) {
  Connection *conn = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    sock_OnReceiveMessage(self, &conn[i], i);
  }
}

static inline void sock_AcceptConnectionsRoutine(PSocketServer self) {
  if(self->maxActiveConnections <= self->connections->size) {
    return ;
  }
  struct sockaddr_in cli;
  socklen_t len;
  int32_t sockfd = self->serverFD.fd;
  len = sizeof( (struct sockaddr *) &len);
  int32_t connfd = accept(sockfd, (SA*)&cli, &len);
  if (connfd < 0) {
    return ;
  }
  Connection currentCon = (Connection) {
    .fd = connfd
  };
  sock_PushCloseConnMethod(self, currentCon, self->connections->size);
  vct_Push(self->connections, &currentCon);
  sock_ExecuteMetaMethod(&currentCon, self->onConnectionAquire);
}

static inline void sock_WriteBufferCleanup(PSocketServer self) {
  DataFragment *dataFragments = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    if(dataFragments[i].persistent) {
      free(dataFragments[i].data);
    }
  }
  vct_Clear(self->outputCommands);
}

PSocketMethod sock_Method_Create(void *method, void *mirrorBuffer) {
  PSocketMethod self = malloc(sizeof(SocketMethod));
  self->method = method;
  self->mirrorBuffer = mirrorBuffer;
  return self;
}

void sock_Method_Delete(PSocketMethod self) {
  free(self);
}

void sock_ProcessWriteRequests_t(PSocketServer self, Vector markedForDeletionRequests) {
  DataFragment *dataFragments = self->outputCommands->buffer;
  for(size_t i = 0, c = self->outputCommands->size; i < c; i++) {
    ssize_t response = send(dataFragments[i].conn.fd, dataFragments[i].data, dataFragments[i].size, MSG_DONTWAIT);
    if(response < 0) {
      vct_Push(markedForDeletionRequests, &i);
      sock_ExecuteMetaMethod(&dataFragments[i].conn, self->onConnectionRelease);
      close(dataFragments[i].conn.fd);
    }
  }
}

size_t sock_ConnectionCount(PSocketServer self) {
  return self->connections->size;
}

static inline void sock_ProcessWriteRequests(PSocketServer self)  {
  Vector markedForDeletionRequests = vct_Init(sizeof(size_t));
  sock_ProcessWriteRequests_t(self, markedForDeletionRequests);
  sock_WriteBufferCleanup(self);
  Vector prunnedArray = vct_RemoveElements(self->connections, markedForDeletionRequests);
  vct_Delete(self->connections);
  vct_Delete(markedForDeletionRequests);
  self->connections = prunnedArray;
  sock_ClearPushedConnections(self);
}

static inline void sock_ClearConnections(PSocketServer self) {
  Connection *conn = self->connections->buffer;
  for(size_t i = 0, c = self->connections->size; i < c; i++) {
    close(conn[i].fd);
  }
  vct_Delete(self->closeConnectionsQueue);
  vct_Delete(self->connections);
}

PConnection sock_FindConnectionByIndex(PSocketServer self, size_t index) {
  if(index >= self->connections->size) {
    return NULL;
  }
  Connection *conn = self->connections->buffer;
  return conn + index;
}

static inline void sock_Time_OnFrame(PSocketServer self, uint64_t deltaMS) {
  if(self->timeServer.timeServer) {
    tf_OnFrame(self->timeServer.timeServer, deltaMS);
  }
}

void sock_OnFrame(PSocketServer self, uint64_t deltaMS) {
  sock_AcceptConnectionsRoutine(self);
  sock_ProcessReadMessage(self);
  sock_ProcessWriteRequests(self);
  sock_Time_OnFrame(self, deltaMS);
}

static inline void sock_Time_Delete(PSocketServer self) {
  if(self->timeServer.timeServer) {
    tf_Delete(self->timeServer.timeServer);
  }
}

int32_t _sock_Client_Conn(uint16_t port, char *ip) {
  int32_t sock;
  struct sockaddr_in server_addr;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    return -1;
  }
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);

  if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
    close(sock);
    return -1;
  }
  if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    close(sock);
    return -1;
  }
  fcntl(sock, F_SETFL, fcntl(sock, F_GETFL, 0) | O_NONBLOCK);
  return sock;
}

PConnection sock_Client_Connect(uint16_t port, char *ip) {
  int32_t fd = _sock_Client_Conn(port, ip);
  if(fd == -1) {
    return NULL;
  }
  PConnection conn = malloc(sizeof(Connection));
  conn->fd = fd;
  return conn;
}

void sock_Client_SendMessage(PDataFragment frag) {
  (void)!send(frag->conn.fd, frag->data, frag->size, MSG_DONTWAIT);
}

DataFragment sock_Client_Receive(PConnection conn) {
  Vector dataToRead = vct_Init(sizeof(char));
  char bufferChunk[1024];
  ssize_t bytesRead = -1;
  while((bytesRead = recv(conn->fd, bufferChunk, sizeof(bufferChunk), 0)) && bytesRead != -1) {
    for(size_t i = 0; i < bytesRead; i++) {
      vct_Push(dataToRead, &bufferChunk[i]);
    }
  }
  DataFragment fragment = {
    .conn = *conn,
    .data = dataToRead->buffer,
    .persistent = 0,
    .size = dataToRead->size
  };
  vct_DeleteWOBuffer(dataToRead);
  return fragment;
}

void sock_Client_Free(PConnection conn) {
  close(conn->fd);
  free(conn);
}

void sock_Delete(PSocketServer self) {
  vct_Delete(self->inputReads);
  sock_ClearConnections(self);
  vct_Delete(self->outputCommands);
  close(self->serverFD.fd);
  sock_Time_Delete(self);
  free(self);
}
#include "Splitter.h"

uint8_t areStringsEqual(char *child, char *parent, size_t childSize, size_t parentSize);
Vector extract(char *buffer, size_t left, size_t right, size_t size);
void splitString(struct Splitter_t self, char *buffer, size_t size, char *splitter, size_t splitterSize);

Splitter split(char *buffer, size_t size, char *splitter, size_t splitterSize) {
  Splitter self;
  self.lines = vct_Init(sizeof(char *));
  if(size) {
    splitString(self, buffer, size, splitter, splitterSize);
  }
  return self;
}

void splitString(Splitter self, char *buffer, size_t size, char *splitter, size_t splitterSize) {
  size_t lastIndex = 0;
  size_t i = 0;
  while(i < size) {
    if(areStringsEqual(splitter, buffer + i, splitterSize, size - i)) {
      Vector currentSlice = extract(buffer, lastIndex, i - 1, size);
      vct_Push(self.lines, &currentSlice);
      i += splitterSize;
      lastIndex = i;
    }
    else {
      i++;
    }
  }
  Vector currentSlice = extract(buffer, lastIndex, size - 1, size);
  vct_Push(self.lines, &currentSlice);
}

Vector extract(char *buffer, size_t left, size_t right, size_t size) {
  Vector result = vct_Init(sizeof(char));
  for(size_t i = left; i <= right; i++) {
    vct_Push(result, &buffer[i]);
  }
  char endCharacter = '\0';
  vct_Push(result, &endCharacter);
  return result;
}

uint8_t areStringsEqual(char *child, char *parent, size_t childSize, size_t parentSize) {
  if(parentSize < childSize) {
    return 0;
  }
  for(size_t i = 0; i < childSize; i++) {
    if(child[i] != parent[i]) {
      return 0;
    }
  }
  return 1;
}

char *splitter_GetLine(Splitter self, size_t index) {
  if(index >= self.lines->size) {
    return NULL;
  }
  Vector *lines = self.lines->buffer;
  return lines[index]->buffer; 
}

size_t splitter_Count(Splitter self) {
  return self.lines->size;
}

size_t splitter_GetSize(Splitter self, size_t index) {
  if(index >= self.lines->size) {
    return 0;
  } 
  Vector *lines = self.lines->buffer;
  if(!lines[index]->size) {
    return 0;
  }
  return lines[index]->size - 1;
}

void splitter_Free(Splitter self) {
  Vector *lines = self.lines->buffer;
  for(size_t i = 0, c = self.lines->size; i < c; i++) {
    vct_Delete(lines[i]);
  }
  vct_Delete(self.lines);
}
#include "TimeFragment.h"
#include <sys/time.h>

uint64_t tf_CurrentTimeMS() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

PTimeServer tf_Create() {
  PTimeServer self = malloc(sizeof(TimeServer));
  self->methods = vct_Init(sizeof(TimeFragment));
  return self;
}

void tf_Delete(PTimeServer self) {
  vct_Delete(self->methods);
  free(self);
}

void tf_ExecuteAfter(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS) {
  TimeFragment fragment = (TimeFragment) {
    .executeAfter = afterMS,
    .methodFragment = currentMethod
  };
  vct_Push(self->methods, &fragment);
}

static inline void tf_ExecuteMethods(PTimeServer self, uint64_t deltaMS) {
  TimeFragment *fragment = self->methods->buffer;
  Vector fragmentsToRemove = vct_Init(sizeof(size_t));
  for(size_t i = 0, c = self->methods->size; i < c; i++) {
    fragment[i].executeAfter -= (int64_t)deltaMS;
    if(fragment[i].executeAfter <= 0) {
      void (*method)(void *) = fragment[i].methodFragment.method;
      method(fragment[i].methodFragment.buffer);
      vct_Push(fragmentsToRemove, &i);
    }
  }
  Vector cpyVector = vct_RemoveElements(self->methods, fragmentsToRemove);
  vct_Delete(self->methods);
  self->methods = cpyVector;
  vct_Delete(fragmentsToRemove);
}

void tf_OnFrame(PTimeServer self, uint64_t deltaMS) {
  tf_ExecuteMethods(self, deltaMS);
}
#include "TrieHash.h"
#include <string.h>

PTrieNode trn_Create();
uint8_t trn_AddValues(PTrieNode self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize, uint32_t position);

PTrieHash trh_Create() {
  PTrieHash self = crm_Alloc(sizeof(TrieHash));
  memset(self, 0, sizeof(TrieHash));
  self->parentNode = trn_Create();
  return self;
}

void trh_Add(PTrieHash self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize) {
  if(!trn_AddValues(self->parentNode, key, keySize, value, valueSize, 0)) {
    self->count++;
  }
}

PTrieNode trn_Create() {
  PTrieNode self = crm_Alloc(sizeof(TrieNode));
  memset(self, 0, sizeof(TrieNode));
  self->nextNodes = crm_Alloc(sizeof(PTrieNode) * 16);
  memset(self->nextNodes, 0, sizeof(PTrieNode) * 16);
  return self;
}

static inline void trh_FreeNode(PTrieNode self) {
  crm_Free(self->nextNodes);
  crm_Free(self);
}

void trn_DeleteNodes(PTrieNode self) {
  for(uint8_t i = 0; i < 16; i++) {
    if(self->nextNodes[i]) {
      trn_DeleteNodes(self->nextNodes[i]);
      self->nextNodes[i] = NULL;
    }
  }
  if(self->buffer) {
    crm_Free(self->buffer);
  }
  trh_FreeNode(self);
}

uint8_t trn_RemoveNode_t(PTrieNode self, PVOID key, uint32_t keySize, uint32_t position) {
  if(position >= (keySize << 1)) {
    if(self->buffer) {
      crm_Free(self->buffer);
      self->buffer = NULL;
      return 1;
    }
    return 0;
  }
  uint8_t currentValue;
  if(position & 1) {
    currentValue = (((uint8_t *)key)[(position >> 1)] & 15);
  }
  else {
    currentValue = (((uint8_t *)key)[(position >> 1)] >> 4);
  }
  PTrieNode node = self->nextNodes[currentValue];
  uint8_t deleted = 0;
  if(node) {
    deleted = trn_RemoveNode_t(node, key, keySize, position + 1);
    node->count--;
    if(!node->count) {
      self->nextNodes[currentValue] = NULL;
      trh_FreeNode(node);
    }
  }
  return deleted;
}

void trh_Buffer_AddToIndex(PTrieHash self, uint32_t id, PVOID buffer, uint32_t bufferSize) {
  trh_Add(self, &id, sizeof(uint32_t), buffer, bufferSize);
}

void trh_Buffer_AddToIndex64(PTrieHash self, uint64_t id, PVOID buffer, uint32_t bufferSize) {
  trh_Add(self, &id, sizeof(uint64_t), buffer, bufferSize);
}

PVOID trh_Buffer_GetFromIndex(PTrieHash self, uint32_t id) {
  return trh_GetBuffer(self, &id, sizeof(uint32_t));
}

PVOID trh_Buffer_GetFromIndex64(PTrieHash self, uint64_t id) {
  return trh_GetBuffer(self, &id, sizeof(uint64_t));
}

void trh_Buffer_RemoveAtIndex(PTrieHash self, uint32_t id) {
  trh_RemoveNode(self, &id, sizeof(uint32_t));
}

void trh_Buffer_RemoveAtIndex64(PTrieHash self, uint64_t id) {
  trh_RemoveNode(self, &id, sizeof(uint64_t));
}

PVOID trn_GetBuffer_t(PTrieNode self, PVOID key, uint32_t keySize, uint32_t position) {
  if(position >= (keySize << 1)) {
    return self->buffer;
  }
  uint8_t currentValue;
  if(position & 1) {
    currentValue = (((uint8_t *)key)[(position >> 1)] & 15);
  }
  else {
    currentValue = (((uint8_t *)key)[(position >> 1)] >> 4);
  }
  PTrieNode node = self->nextNodes[currentValue];
  if(node) {
    return trn_GetBuffer_t(node, key, keySize, position + 1);
  }
  return NULL;
}

void trh_GetValues_t(PTrieNode self, Vector values) {
  if(!self) {
    return ;
  }
  if(self->buffer) {
    vct_Push(values, self->buffer);
  }
  PTrieNode *nextNodes = self->nextNodes;
  for(size_t i = 0; i < 16; i++) {
    if(nextNodes[i]) {
      trh_GetValues_t(nextNodes[i], values);
    }
  }
}

Vector trh_GetValues(PTrieHash self, size_t valueSize) {
  Vector response = vct_Init(valueSize);
  trh_GetValues_t(self->parentNode, response);
  return response;
}

void trh_Key_Push(Vector currentKey, uint8_t value, size_t position) {
  if(!(position & 1)) {
    value <<= 4;
    vct_Push(currentKey, &value);
    return ;
  }
  uint8_t *last = (uint8_t *)vct_Last(currentKey);
  if(!last) {
    return ;
  }
  (*last) += value;
}

static inline void trh_Key_Pop(Vector currentKey, size_t position) {
  if(!(position & 1)) {
    vct_Pop(currentKey);
  }
  else {
    uint8_t *last = (uint8_t *)vct_Last(currentKey);
    if(!last) {
      return ;
    }
    (*last) &= 0xF0;
  }
}

void trh_GetKeys_t(PTrieNode self, Vector keys, Vector currentKey, size_t position) {
  if(!self) {
    return ;
  }
  if(self->buffer) {
    Key key;
    key.keySize = currentKey->size;
    key.key = crm_Alloc(key.keySize);

    memcpy(key.key, currentKey->buffer, key.keySize);
    vct_Push(keys, &key);
  }
  PTrieNode *nextNodes = self->nextNodes;
  for(uint8_t i = 0; i < 16; i++) {
    if(nextNodes[i]) {
      trh_Key_Push(currentKey, i, position);
      trh_GetKeys_t(nextNodes[i], keys, currentKey, position + 1);
      trh_Key_Pop(currentKey, position);
    }
  }
}

Vector trh_GetKeys(PTrieHash self) {
  Vector response = vct_Init(sizeof(Key));
  Vector currentKey = vct_Init(sizeof(uint8_t));
  trh_GetKeys_t(self->parentNode, response, currentKey, 0);
  vct_Delete(currentKey);
  return response;
}

void trh_FreeKeys(Vector keys) {
  Key *buffer = (Key *)keys->buffer;
  for(size_t i = 0, c = keys->size; i < c; i++) {
    crm_Free(buffer[i].key);
  }
  vct_Delete(keys);
}

PVOID trh_GetBuffer(PTrieHash self, PVOID key, uint32_t keySize) {
  return trn_GetBuffer_t(self->parentNode, key, keySize, 0);
}

void trh_RemoveNode(PTrieHash self, PVOID key, uint32_t keySize) {
  if(trn_RemoveNode_t(self->parentNode, key, keySize, 0)) {
    self->count--;
  }
}

uint8_t trn_AddValues(PTrieNode self, PVOID key, uint32_t keySize, PVOID value, uint32_t valueSize, uint32_t position) {
  if(position >= (keySize << 1)) {
    PVOID lastBuffer = self->buffer;
    self->buffer = crm_Alloc(valueSize);
    memcpy(self->buffer, value, valueSize);
    if(lastBuffer) {
      crm_Free(lastBuffer);
      return 0;
    }
    return 1;
  }
  uint8_t currentValue;
  if(position & 1) {
    currentValue = (((uint8_t *)key)[(position >> 1)] & 15);
  }
  else {
    currentValue = (((uint8_t *)key)[(position >> 1)] >> 4);
  }
  PTrieNode node = self->nextNodes[currentValue];
  if(!node) {
    node = trn_Create();
    self->nextNodes[currentValue] = node;
  }
  node->count++;
  return trn_AddValues(node, key, keySize, value, valueSize, position + 1);
}

void trh_Integer32_Insert(PTrieHash self, uint32_t key, uint32_t value) {
  trh_Add(self, &key, sizeof(uint32_t), &value, sizeof(uint32_t));
}

PVOID trh_Integer32_Get(PTrieHash self, uint32_t key) {
  return trh_GetBuffer(self, &key, sizeof(uint32_t));
}

void trh_Integer32_RemoveElement(PTrieHash self, uint32_t key) {
  trh_RemoveNode(self, &key, sizeof(uint32_t));
}

void trh_Delete(PTrieHash self) {
  trn_DeleteNodes(self->parentNode);
  crm_Free(self);
}
#include "Vector.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

#define crm_Alloc malloc
#define crm_Free free
#define crm_Realloc realloc

Vector vct_Init(size_t size) {
  Vector self = (Vector)crm_Alloc(sizeof(struct Vector_t));
  self->buffer = crm_Alloc(size);
  self->size = 0;
  self->capacity = 1;
  self->objSize = size;
  return self;
}

Vector vct_InitWithCapacity(size_t size, size_t count) {
  Vector self = crm_Alloc(sizeof(struct Vector_t));
  self->buffer = crm_Alloc(size * count);
  self->size = 0;
  self->capacity = count;
  self->objSize = size;
  return self;
}

Vector vct_InitWithSize(size_t objSize, size_t count) {
  Vector self = crm_Alloc(sizeof(struct Vector_t));
  self->buffer = crm_Alloc(objSize * count);
  self->size = count;
  self->capacity = count;
  self->objSize = objSize;
  return self;
}

void copyData(Vector self, void *buffer) {
  memcpy(self->buffer + (self->size * self->objSize), buffer, self->objSize);
  self->size++;
}

void vct_Push(Vector self, void *buffer) {
  if(self->size >= self->capacity) {
    self->capacity <<= 1;
    self->buffer = crm_Realloc(self->buffer, self->capacity * self->objSize);
  }
  copyData(self, buffer);
}

void vct_RemoveElement(Vector self, size_t index) {
  assert(self->size != 0);
  if(index >= self->size) {
    return ;
  }
  char *payloadBuffer = self->buffer;
  for(ssize_t i = index, c = (ssize_t)self->size - 1; i < c; i++) {
    memcpy(payloadBuffer + i * self->objSize, payloadBuffer + (i + 1) * self->objSize, self->objSize);
  }
  self->size--;
}

void vct_Delete(Vector self) {
  crm_Free(self->buffer);
  crm_Free(self);
}

void vct_DeleteWOBuffer(Vector self) {
  crm_Free(self);
}

char *vct_Last(Vector self) {
  if(!self->size) {
    return NULL;
  }
  return self->buffer + (self->size - 1) * self->objSize;
}

void vct_Pop(Vector self) {
  if(!self->size) {
    return ;
  }
  self->size--;
}

Vector vct_RemoveElements(Vector payload, Vector indexes) {
  Vector indexesCount = vct_InitWithSize(sizeof(uint8_t), payload->size);
  memset(indexesCount->buffer, 0, sizeof(uint8_t) * payload->size);

  size_t *indexesBuffer = indexes->buffer;
  uint8_t *aparitionCount = indexesCount->buffer;
  
  for(size_t i = 0, c = indexes->size; i < c; i++) {
    if(indexesBuffer[i] < payload->size) {
      aparitionCount[indexesBuffer[i]] = 1;
    }
  }
  Vector payloadWithMissingElements = vct_Init(payload->objSize);
  for(size_t i = 0, c = payload->size; i < c; i++) {
    if(!aparitionCount[i]) {
      vct_Push(payloadWithMissingElements, payload->buffer + i * payload->objSize);
    }
  }
  vct_Delete(indexesCount);
  return payloadWithMissingElements;
}

int64_t vct_Find(Vector payload, void *element) {
  void *startingPointer = payload->buffer;
  size_t objSize = payload->objSize;
  for(size_t i = 0, c = payload->size; i < c; i++) {
    if(!memcmp(startingPointer + i * objSize, element, objSize)) {
      return i;
    }
  }
  return -1;
}

void vct_Clear(Vector self) {
  self->size = 0;
}
#include "WebSocketServer.h"
#include <string.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include "WebSocketsTranslator.h"

void wss_SetMethods(PWebSocketServer self);
void _wss_OnConnect(Connection connection, void *buffer);
void _wss_OnReceive(PDataFragment dt, void *buffer);
void _wss_OnRelease(Connection conn, void *buffer);

PWebSocketServer wss_Create(uint16_t port) {
  PWebSocketServer self = malloc(sizeof(WebSocketServer));
  memset(self, 0, sizeof(WebSocketServer));
  self->socketServer = sock_Create(port);
  self->pendingConnections = vct_Init(sizeof(Connection));
  wss_SetMethods(self);
  return self;
}

void wss_EnablePingPongTimeout(PWebSocketServer self, uint64_t timeout) {

}

void wss_SetMethods(PWebSocketServer self) {
  PSocketMethod _onConnect = sock_Method_Create(
    _wss_OnConnect,
    self
  );
  self->methodsBundle._onConnect = _onConnect;
  self->socketServer->onConnectionAquire = _onConnect;
  PSocketMethod _onReceive = sock_Method_Create(
    _wss_OnReceive,
    self
  );
  self->methodsBundle._onReceive = _onReceive;
  self->socketServer->onReceiveMessage = _onReceive;
  PSocketMethod _onRelease = sock_Method_Create(
    _wss_OnRelease,
    self
  );
  self->methodsBundle._onRelease = _onRelease;
  self->socketServer->onConnectionRelease = _onRelease;
}

void wss_Delete(PWebSocketServer self) {
  sock_Method_Delete(self->methodsBundle._onReceive);
  sock_Method_Delete(self->methodsBundle._onConnect);
  sock_Method_Delete(self->methodsBundle._onRelease);
  sock_Delete(self->socketServer);
  vct_Delete(self->pendingConnections);
  free(self);
}

static inline size_t wss_FindConnectionOnThePull(PWebSocketServer self, PConnection conn, uint8_t *found) {
  *found = 0;
  Connection *connections = self->pendingConnections->buffer;
  for(size_t i = 0, c = self->pendingConnections->size; i < c; i++) {
    if(conn->fd == connections[i].fd) {
      *found = 1;
      return i;
    }
  }
  return 0;
}

char *webSocketKey(PHttpString sec_websocket_key) {
  static const char *GUID = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
  if (!sec_websocket_key->buffer) return NULL;
  size_t key_len = sec_websocket_key->sz;
  size_t guid_len = strlen(GUID);
  size_t cat_len  = key_len + guid_len;
  char *cat = (char *)malloc(cat_len + 1);
  if (!cat) return NULL;
  memcpy(cat, sec_websocket_key->buffer, key_len);
  memcpy(cat + key_len, GUID, guid_len);
  cat[cat_len] = '\0';
  unsigned char sha1_digest[SHA_DIGEST_LENGTH];
  SHA1((const unsigned char *)cat, cat_len, sha1_digest);
  free(cat);
  int b64_len = 4 * ((SHA_DIGEST_LENGTH + 2) / 3);
  char *accept = (char *)malloc(b64_len + 1);
  if (!accept) return NULL;
  EVP_EncodeBlock((unsigned char *)accept, sha1_digest, SHA_DIGEST_LENGTH);
  accept[b64_len] = '\0';
  return accept;
}

PHttpResponse wss_Response(PWebSocketServer self, PHttpRequest req) {
  PHttpResponse response = http_Response_Empty();
  response->response = 101;
  http_Response_Set(response, "Upgrade", sizeof("Upgrade") - 1, "websocket", sizeof("websocket") - 1);
  http_Response_Set(response, "Connection", sizeof("Connection") - 1, "Upgrade", sizeof("Upgrade") - 1);
  HttpString key = http_Request_GetValue(req, "Sec-WebSocket-Key");
  if(!key.buffer) {
    http_Response_Delete(response);
    return NULL;
  }
  char *newKey = webSocketKey(&key);
  http_Response_Set(response, "Sec-WebSocket-Accept", sizeof("Sec-WebSocket-Accept") - 1, newKey, strlen(newKey));
  free(newKey);
  return response;
}

void wss_SendMessage(PWebSocketServer self, PDataFragment dt) {
  WebSocketObject objs = {
    .buffer = dt->data,
    .sz = dt->size
  };
  char *response = wbs_ToWebSocket(objs);
  DataFragment fragment = {
    .conn = dt->conn,
    .data = response,
    .size = wbs_FullMessageSize(response),
    .persistent = 1
  };
  sock_Write_Push(self->socketServer, &fragment);
  free(response);
}

uint8_t wss_ProcessConnectionRequest(PWebSocketServer self, PDataFragment dt) {
  PHttpRequest req = http_Request_Parse(dt->data, dt->size);
  if(!req) {
    return 0;
  }
  PHttpResponse response = wss_Response(self, req);
  http_Request_Delete(req);
  if(!response) {
    return 0;
  }
  HttpString responseChar = http_Response_ToString(response);
  DataFragment frag = {
    .conn = dt->conn,
    .data = responseChar.buffer,
    .persistent = 1,
    .size = responseChar.sz
  };
  sock_Write_Push(self->socketServer, &frag);
  http_Response_Delete(response);
  free(responseChar.buffer);
  return 1;
}

uint8_t wss_ReceiveMessages(PDataFragment dt, PSocketMethod routine) {
  Vector messages = wbs_FromWebSocket(dt->data, dt->size);
  if(!messages) {
    return 0;
  }
  WebSocketObject *objects = messages->buffer;
  void (*cMethod)(PDataFragment, void *) = routine->method;
  DataFragment responseDt = {
    .conn = dt->conn,
    .data = NULL,
    .persistent = 0,
    .size = 0
  };
  for(size_t i = 0, c = messages->size; i < c; i++) {
    responseDt.data = objects[i].buffer;
    responseDt.size = objects[i].sz;
    cMethod(&responseDt, routine->mirrorBuffer);
  }
  vct_Delete(messages);
  return 1;
}

static inline void wss_ProcessReleaseMethod(PWebSocketServer self, PDataFragment dt, PSocketMethod routine) {
  if(self->onRelease) {
    void (*cMethod)(PConnection, void *) = self->onRelease->method;
    cMethod(&dt->conn, self->onRelease->mirrorBuffer);
  }
}

static inline void wss_ProcessWsRequests(PWebSocketServer self, PDataFragment dt, PSocketMethod routine) {
  if(!self->onReceiveMessage) {
    return ;
  }
  if(!wss_ReceiveMessages(dt, routine)) {
    wss_ProcessReleaseMethod(self, dt, routine);
    sock_PushCloseConnections(self->socketServer, &dt->conn);
  }
}

void _wss_OnReceive(PDataFragment dt, void *buffer) {
  PWebSocketServer self = buffer;
  uint8_t found;
  size_t connIndex = wss_FindConnectionOnThePull(self, &dt->conn, &found);
  if(!found) {
    wss_ProcessWsRequests(self, dt, self->onReceiveMessage);
    return ;
  }
  vct_RemoveElement(self->pendingConnections, connIndex);
  if(!wss_ProcessConnectionRequest(self, dt)) {
    sock_PushCloseConnections(self->socketServer, &dt->conn);
    return ;
  }
  if(self->onConnect) {
    void (*cMethod)(PConnection, void *) = self->onConnect->method;
    cMethod(&dt->conn, self->onConnect->mirrorBuffer);
  }
}

size_t wss_ConnectionsCount(PWebSocketServer self) {
  return sock_ConnectionCount(self->socketServer);
}

void _wss_OnConnect(Connection connection, void *buffer) {
  PWebSocketServer self = buffer;
  vct_Push(self->pendingConnections, &connection);
}

void _wss_OnRelease(Connection conn, void *buffer) {
  PWebSocketServer self = buffer;
  uint8_t found;
  size_t connIndex = wss_FindConnectionOnThePull(self, &conn, &found);
  if(found) {
    vct_RemoveElement(self->pendingConnections, connIndex);
    return ;
  }
  if(self->onRelease) {
    void (*cMethod)(Connection, void *) = self->onRelease->method;
    cMethod(conn, self->onRelease->mirrorBuffer);
  }
}

void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS) {
  sock_OnFrame(self->socketServer, deltaMS);
}
#include "WebSocketsTranslator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>

#define MAX_FRAME_SIZE (1024 * 1024 * 1024) 

typedef enum {
  OPCODE_CONTINUATION_FRAME = 0x0,
  OPCODE_TEXT_FRAME = 0x1,
  OPCODE_BINARY = 0x2,
  OPCODE_CONNECTION_CLOSE = 0x8,
  OPCODE_PING = 0x9,
  OPCODE_PONG = 0xA
} Opcode;

static inline char *wbs_PayloadBuffer(char *buffer);
static inline uint8_t wbs_IsMasked(char *buffer);
static inline char *wbs_MaskOffset(char *msg);

static inline void wbs_SetOpcodeTo(char *buffer, Opcode code) {
  buffer[0] |= code;
}

static inline void wbs_SetFin(char *buffer) {
  buffer[0] |= (1<<7);
}

static inline void wbs_ClearHeaderBytes(char *buffer) {
  buffer[0] = 0;
  buffer[1] = 0;
}

static inline void wbs_SetMaskFlag(char *buffer) {
  buffer[1] |= (1<<7);
}

static inline uint8_t wbs_SizeCode(char *buffer) {
  return (buffer[1] & ((1<<7) - 1));
}

static inline void wbs_RevertBytes(char *st, char *end, char *dst) {
  end--;
  for(char *it = end; it >= st; it--) {
    *dst = *it;
    dst++;
  }
}

static inline size_t wbs_SetPayloadSize(char *buffer, const PWebSocketObject obj) {
  char *currentNumberPointer = (char *)&obj->sz;
  size_t maskSize = wbs_IsMasked(buffer) * 4;
  switch (wbs_SizeCode(buffer))
  {
    case 126: {
      wbs_RevertBytes(currentNumberPointer, currentNumberPointer + sizeof(uint16_t), buffer + 2);
      return sizeof(uint16_t) + maskSize;
      break;  
    }

    case 127: {
      wbs_RevertBytes(currentNumberPointer, currentNumberPointer + sizeof(uint64_t), buffer + 2);
      return sizeof(uint64_t) + maskSize;
      break;  
    }
  
    default:
      break;
  }
  return maskSize;
}

static inline void wbs_WritePayload(char *buffer, const PWebSocketObject obj) {
  memcpy(buffer, obj->buffer, obj->sz);
}

static inline size_t wbs_Object_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked) {
  size_t maskData = shouldBeMasked * 4;
  if(obj->sz <= 125) {
    return obj->sz + 2 + maskData;
  }
  if(obj->sz <= (1<<16)) {
    return obj->sz + 4 + maskData;
  }
  return obj->sz + 10 + maskData;
}

static inline size_t wbs_Raw_HeaderSize(char *buffer) {
  return (size_t)(wbs_PayloadBuffer(buffer) - buffer);
}

size_t wbs_Raw_Public_HeaderSize(char *buffer) {
  return wbs_Raw_HeaderSize(buffer);
}

size_t wbs_Public_HeaderSize(const PWebSocketObject obj, uint8_t shouldBeMasked) {
  return wbs_Object_HeaderSize(obj, shouldBeMasked);
}

static inline char *wbs_SetPayloadCode(char *buffer, const PWebSocketObject obj) {
  if(obj->sz <= 125) {
    buffer[1] |= obj->sz;
  }
  else if(obj->sz <= (1<<16)) {
    buffer[1] |= 126;
  } else {
    buffer[1] |= 127;
  }
  return buffer + 1 + wbs_SetPayloadSize(buffer, obj);
}

void _wbs_PrintNextBytes(char *buffer, size_t sz) {
  printf("(");
  for(size_t i = 0; i < sz; i++) {
    printf("0x%x ", (uint8_t)buffer[i]);
  }
  printf(")\n");
}

static inline uint8_t wbs_IsMasked(char *buffer) {
  return (buffer[1] & (1<<7)) > 0;
}

static inline size_t wbs_PayloadSize(char *buffer) {
  size_t result = 0;
  uint8_t size = wbs_SizeCode(buffer);
  if(size < 126) {
    return size;
  }
  if(size == 126) {
    wbs_RevertBytes(buffer + 2, buffer + 2 + sizeof(uint16_t), (char *)&result);
    return result;
  }
  if(size == 127) {
    wbs_RevertBytes(buffer + 2, buffer + 2 + sizeof(uint64_t), (char *)&result);
    return result;
  }
  return 0;
}

size_t wbs_Public_PayloadSize(char *buffer) {
  return wbs_PayloadSize(buffer);
}

static inline char *wbs_PayloadBuffer(char *buffer) {
  size_t maskOffset = wbs_IsMasked(buffer) * 4;
  uint8_t size = wbs_SizeCode(buffer);
  if(size < 126) {
    return buffer + 2 + maskOffset;
  }
  if(size == 126) {
    return buffer + 4 + maskOffset;
  }
  return buffer + 10 + maskOffset;
}

char *wbs_Public_PayloadBuffer(char *buffer) {
  return wbs_PayloadBuffer(buffer);
}

uint8_t wbs_IsBufferValid(char *buffer, size_t sz) {
  char *endBuffer = buffer + sz;
  while(buffer < endBuffer) {
    size_t currentSize = (size_t)(endBuffer - buffer);
    char *nextBuffer = wbs_NextMessageIterator(buffer, currentSize);
    if(!nextBuffer) {
      return 0;
    }
    buffer = nextBuffer;
  }
  return buffer == endBuffer;
}

static inline size_t wbs_ValidMinimumSize(char *buffer) {
  size_t maskSize = wbs_IsMasked(buffer) * 4;
  uint8_t size = wbs_SizeCode(buffer);
  if(size < 126) {
    return 2 + maskSize;
  }
  if(size == 126) {
    return 4 + maskSize;
  }
  return 10 + maskSize;
}

char *wbs_NextMessageIterator(char *st, size_t maxMessageSize) {
  if(maxMessageSize < 2) {
    return NULL;
  }
  if(wbs_ValidMinimumSize(st) > maxMessageSize) {
    return NULL;
  }
  size_t messageSz = wbs_FullMessageSize(st);
  if(messageSz > maxMessageSize) {
    return NULL;
  }
  return st + messageSz;
}

size_t wbs_FullMessageSize(char *buffer) {
  return wbs_Raw_HeaderSize(buffer) + wbs_PayloadSize(buffer);
}

void wbs_Print(char *buffer) {
  printf("First byte 0x%x\n", (uint8_t)buffer[0]);
  uint8_t size = wbs_SizeCode(buffer);
  printf("Size cateogry byte is 0x%x\n", size);
  switch (size)
  {
    case 126:
      _wbs_PrintNextBytes(buffer + 2, sizeof(uint16_t));
      break;

    case 127:
      _wbs_PrintNextBytes(buffer + 2, sizeof(uint64_t));
      break;
    
    default:
      break;
  }
  printf("Mask bit is 0x%x\n", wbs_IsMasked(buffer));
  const size_t payloadSize = wbs_PayloadSize(buffer), messageSize = wbs_FullMessageSize(buffer);
  printf("Payload is size is %ld\n", payloadSize);
  _wbs_PrintNextBytes(wbs_PayloadBuffer(buffer), payloadSize);
  printf("Full message size is %ld\n", messageSize);
  _wbs_PrintNextBytes(buffer, messageSize);
}

char *wbs_ToWebSocket(WebSocketObject self) {
  char *response = malloc(wbs_Object_HeaderSize(&self, 0));
  wbs_ClearHeaderBytes(response);
  wbs_SetFin(response);
  wbs_SetOpcodeTo(response, OPCODE_BINARY);
  char *cpyResponse = response;
  cpyResponse = wbs_SetPayloadCode(response, &self) + 1 /*First byte*/;
  wbs_WritePayload(cpyResponse, &self);
  return response;
}

void wbs_MaskSwitch(char *buffer) {
  char *maskOffset = wbs_MaskOffset(buffer);
  char *payloadOffset = wbs_PayloadBuffer(buffer);
  for(size_t i = 0, c = 0, z = wbs_PayloadSize(buffer); i < z; i++, c = ((c + 1) & 3)) {
    payloadOffset[i] ^= maskOffset[c];
  }
}

static inline void wbs_Mask_Set(char *buffer) {
  if(!wbs_IsMasked(buffer)) {
    return ;
  }
  char *maskOffset = wbs_MaskOffset(buffer);
  for(size_t i = 0; i < sizeof(uint32_t); i++) {
    maskOffset[i] = (rand() & 0xFF);
  }
  wbs_MaskSwitch(buffer);
}

char *wbs_Masked_ToWebSocket(WebSocketObject self) {
  char *response = malloc(wbs_Object_HeaderSize(&self, 1));
  wbs_ClearHeaderBytes(response);
  wbs_SetFin(response);
  wbs_SetMaskFlag(response);
  wbs_SetOpcodeTo(response, OPCODE_BINARY);
  char *cpyResponse = response;
  cpyResponse = wbs_SetPayloadCode(response, &self) + 1 /*First byte*/;
  wbs_WritePayload(cpyResponse, &self);
  wbs_Mask_Set(response);
  return response;
}

static inline char *wbs_UnmaskedBuffer(char *msg) {
  return wbs_PayloadBuffer(msg);
}

static inline char *wbs_MaskOffset(char *msg) {
  return wbs_PayloadBuffer(msg) - sizeof(uint32_t);
}

static inline char *wbs_MaskedPayload(char *msg) {
  wbs_MaskSwitch(msg);
  return wbs_PayloadBuffer(msg);
}

char *wbs_ExtractPayload(char *msg) {
  if(!wbs_IsMasked(msg)) {
    return wbs_UnmaskedBuffer(msg);
  }
  return wbs_MaskedPayload(msg);
}

void wbs_Clear_FromWebSocket(Vector objects) {
  vct_Delete(objects);
}

Vector wbs_FromWebSocket(char *msg, size_t bufferSize) {
  if(!wbs_IsBufferValid(msg, bufferSize)) {
    return NULL;
  }
  char *endBuffer = msg + bufferSize;
  Vector buffer = vct_Init(sizeof(WebSocketObject));
  while(msg < endBuffer) {
    WebSocketObject obj = (WebSocketObject) {
      .buffer = wbs_ExtractPayload(msg),
      .sz = wbs_PayloadSize(msg)
    };
    if(!obj.buffer) {
      wbs_Clear_FromWebSocket(buffer);
      return NULL;
    }
    vct_Push(buffer, &obj);
    msg += wbs_FullMessageSize(msg);
  }

  return buffer;
}
