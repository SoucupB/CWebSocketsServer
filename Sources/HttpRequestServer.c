#include "HttpServer.h"
#include "Structs.h"
#include "Vector.h"
#include "SocketServer.h"
#include "TimeFragment.h"
#include "HttpParser.h"
#include "SocketClient.h"

typedef struct RequestMetadata_t {
  RequestStruct metadata;
  PConnection conn;
  uint64_t requestDateMS;
} RequestMetadata;

typedef RequestMetadata *PRequestMetadata;

HttpString sock_Client_ReceiveWithErrors(PConnection conn);

PHttpRequestServer httpS_Request_Create(int64_t timeoutMS) {
  PHttpRequestServer self = malloc(sizeof(HttpRequestServer));
  self->requests = vct_Init(sizeof(RequestMetadata));
  self->timeoutMS = timeoutMS;
  return self;
}

void httpS_Request_Delete(PHttpRequestServer self) {
  vct_Delete(self->requests);
  free(self);
}

void httpS_Request_Send(PHttpRequestServer self, RequestStruct request) {
  RequestMetadata toAdd = {
    .conn = NULL,
    .metadata = request,
    .requestDateMS = tf_CurrentTimeMS()
  };
  vct_Push(self->requests, &toAdd);
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
    if(!buffer[i].conn) {
      continue;
    }
    buffer[i].conn = sock_Client_Connect(buffer[i].metadata.port, buffer[i].metadata.ip);
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

static inline uint8_t httpS_Request_ProcessCurrentFragment(PHttpRequestServer self, RequestMetadata metadata, uint64_t deltaMS) {
  HttpString response = sock_Client_ReceiveWithErrors(metadata.conn);
  if(!response.buffer) {
    return 0;
  }
  PHttpResponse httpResponse = http_Response_Parse(response);
  if(!httpResponse) {
    httpS_Request_ExecuteErrorMethod(metadata.metadata.onFailure, RESPONSE_PARSE_ERROR);
    return 1;
  }
  httpS_Request_ExecuteSuccessMethod(metadata.metadata.onSuccess, httpResponse);
  http_Response_Delete(httpResponse);
  return 1;
}

void httpS_Request_ProcessActiveRequests(PHttpRequestServer self, uint64_t deltaMS) {
  RequestMetadata *buffer = self->requests->buffer;
  Vector indexes = vct_Init(sizeof(size_t));
  for(size_t i = 0, c = self->requests->size; i < c; i++) {
    if(!buffer[i].conn) {
      continue;
    }
    if(httpS_Request_ProcessCurrentFragment(self, buffer[i], deltaMS)) {
      vct_Push(indexes, &i);
    }
  }
  vct_RemoveElements(self->requests, indexes);
  vct_Delete(indexes);
}

void httpS_Request_OnFrame(PHttpRequestServer self, uint64_t deltaMS) {
  httpS_Request_ProcessPendingRequests(self);
  httpS_Request_ProcessActiveRequests(self, deltaMS);
}