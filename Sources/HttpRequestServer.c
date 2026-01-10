#include "HttpServer.h"
#include "Structs.h"
#include "Array.h"
#include "SocketServer.h"
#include "TimeFragment.h"
#include "HttpParser.h"
#include "SocketClient.h"
#include "NetworkBuffer.h"

typedef struct RequestMetadata_t {
  RequestStruct metadata;
  PConnection conn;
  uint64_t requestDateMS;
  PNetworkBuffer buffer;
} RequestMetadata;

typedef RequestMetadata *PRequestMetadata;

HttpString sock_Client_ReceiveWithErrors(PConnection conn);
void httpS_Request_CleanHangingConnections(const PHttpRequestServer self);
static void httpS_Request_FreeRequestMetadata(const PRequestMetadata metadata);

PHttpRequestServer httpS_Request_Create(int64_t timeoutMS) {
  PHttpRequestServer self = crm_Alloc(sizeof(HttpRequestServer));
  self->requests = arr_Init(sizeof(RequestMetadata));
  self->timeoutMS = timeoutMS;
  self->maxSizeInB = 1024 * 1024 * 10;
  return self;
}

void httpS_Request_Delete(PHttpRequestServer self) {
  httpS_Request_CleanHangingConnections(self);
  arr_Delete(self->requests);
  crm_Free(self);
}

void httpS_Request_Send(PHttpRequestServer self, RequestStruct request) {
  RequestMetadata toAdd = {
    .conn = NULL,
    .metadata = request,
    .requestDateMS = tf_CurrentTimeMS(),
    .buffer = tpd_Create(self->maxSizeInB)
  };
  arr_Push(self->requests, &toAdd);
}

void httpS_Request_ProcessRequests(PHttpRequestServer self, PRequestMetadata data) {
  DataFragment frag = {
    .size = data->metadata.query.sz,
    .persistent = 0,
    .conn = *data->conn,
    .data = data->metadata.query.buffer
  };
  sock_Client_SendMessage(&frag);
}

void httpS_Request_ProcessPendingRequests(PHttpRequestServer self) {
  RequestMetadata *buffer = self->requests->buffer;
  for(size_t i = 0, c = self->requests->size; i < c; i++) {
    if(buffer[i].conn) {
      continue;
    }
    buffer[i].conn = sock_Client_Connect(buffer[i].metadata.port, buffer[i].metadata.ip);
    if(!buffer[i].conn) {
      continue;
    }
    httpS_Request_ProcessRequests(self, &buffer[i]);
  }
}

static inline void httpS_Request_ExecuteErrorMethod(PSocketMethod method, RequestError error) {
  if(!method) {
    return ;
  }
  void (*onFailure)(RequestError, void *) = method->method;
  onFailure(error, method->mirrorBuffer);
}

static inline void httpS_Request_ExecuteSuccessMethod(PSocketMethod method, PHttpResponse response) {
  if(!method) {
    return ;
  }
  void (*onSuccess)(PHttpResponse, void *) = method->method;
  onSuccess(response, method->mirrorBuffer);
}

static inline PHttpResponse httpS_Response_Process(const PHttpRequestServer self, const HttpString msg, const PRequestMetadata metadata, uint8_t *incomplete) {
  *incomplete = 0;
  if(!tpd_Push(metadata->buffer, msg.buffer, msg.sz)) {
    return NULL;
  }
  PHttpResponse resp = http_Response_NB_Get(metadata->buffer);
  if(!resp) {
    *incomplete = 1;
    return NULL;
  }
  return resp;
}

static inline uint8_t httpS_Request_ProcessCurrentFragment(const PHttpRequestServer self, const PRequestMetadata metadata, const uint64_t deltaMS) {
  if(metadata->requestDateMS <= deltaMS) {
    httpS_Request_ExecuteErrorMethod(metadata->metadata.onFailure, RESPONSE_TIMEOUT);
    return 1;
  }
  HttpString response = sock_Client_ReceiveWithErrors(metadata->conn);
  if(!response.buffer) {
    return 0;
  }
  uint8_t incomplete;
  PHttpResponse httpResponse = httpS_Response_Process(self, response, metadata, &incomplete);
  if(incomplete) {
    crm_Free(response.buffer);
    return 0;
  }
  if(!httpResponse) {
    crm_Free(response.buffer);
    httpS_Request_ExecuteErrorMethod(metadata->metadata.onFailure, RESPONSE_PARSE_ERROR);
    return 1;
  }
  crm_Free(response.buffer);
  httpS_Request_ExecuteSuccessMethod(metadata->metadata.onSuccess, httpResponse);
  http_Response_Delete(httpResponse);
  metadata->requestDateMS -= deltaMS;
  return 1;
}

static void httpS_Request_FreeRequestMetadata(const PRequestMetadata metadata) {
  sock_Client_Free(metadata->conn);
  tpd_Delete(metadata->buffer);
  metadata->conn = NULL;
}

void httpS_Request_CleanHangingConnections(const PHttpRequestServer self) {
  RequestMetadata *buffer = self->requests->buffer;
  for(size_t i = 0, c = self->requests->size; i < c; i++) {
    if(!buffer[i].conn) {
      continue;
    }
    httpS_Request_FreeRequestMetadata(&buffer[i]);
  }
}

void httpS_Request_ProcessActiveRequests(PHttpRequestServer self, uint64_t deltaMS) {
  RequestMetadata *buffer = self->requests->buffer;
  Array indexes = arr_Init(sizeof(size_t));
  for(size_t i = 0, c = self->requests->size; i < c; i++) {
    if(!buffer[i].conn) {
      continue;
    }
    if(httpS_Request_ProcessCurrentFragment(self, &buffer[i], deltaMS)) {
      arr_Push(indexes, &i);
      httpS_Request_FreeRequestMetadata(&buffer[i]);
      buffer[i].conn = NULL;
    }
  }
  Array request = self->requests;
  self->requests = arr_RemoveElements(self->requests, indexes);
  arr_Delete(request);
  arr_Delete(indexes);
}

void httpS_Request_OnFrame(PHttpRequestServer self, uint64_t deltaMS) {
  httpS_Request_ProcessPendingRequests(self);
  httpS_Request_ProcessActiveRequests(self, deltaMS);
}