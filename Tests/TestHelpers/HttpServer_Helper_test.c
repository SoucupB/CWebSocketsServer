#include "HttpServer_Helper_test.h"
#include "Socket_Helper_test.h"
#include "HttpParser.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct CheckerStruct_t {
  uint32_t *hasExecuted;
  PHttpResponse *response;
} CheckerStruct;

PHttpResponse caller(PHttpRequest req, void *mirror) {
  JsonElement echo = httpS_Json_Get(req);
  json_Parser_Print(echo);
  PHttpResponse rsp = httpS_Json_Post(echo);
  json_DeleteElement(echo);
  return rsp;
}

void http_Helper_AddMethod(PHttpServer server, void *method) {
  PSocketMethod onReceive = sock_Method_Create(
    (void *)caller,
    server
  );
  if(method) {
    onReceive->method = method;
  }
  server->onReceive = onReceive;
}

void onSuccess(PHttpResponse req, void *mirror) {
  CheckerStruct *prc = mirror;
  *prc->hasExecuted = 1;
  *prc->response = http_Response_DeepCopy(req);
}

PHttpResponse http_Helper_Send(uint16_t port, PHttpRequest req, PSocketMethod method) {
  uint32_t hasExecuted = 0;
  int32_t timesExecuted = 5000;
  PHttpResponse response = NULL;
  CheckerStruct inpData = {
    .hasExecuted = &hasExecuted,
    .response = &response
  };
  PSocketMethod onReceive = sock_Method_Create(
    (void *)onSuccess,
    &inpData
  );
  HttpString ip = {
    .buffer = "127.0.0.1",
    .sz = sizeof("127.0.0.1") - 1
  };
  RequestStruct reqData = httpS_Request_StructInit(ip, port);
  reqData.query = http_Request_ToString(req);
  reqData.onSuccess = onReceive;
  PHttpRequestServer reqServer = httpS_Request_Create(15000);
  httpS_Request_Send(reqServer, reqData);
  while(1) {
    if(hasExecuted || !timesExecuted) {
      break;
    }
    if(method) {
      void (*methodDef)(void *) = method->method;
      methodDef(method->mirrorBuffer);
    }
    timesExecuted--;
    httpS_Request_OnFrame(reqServer, 1);
    usleep(1 * 1000);
  }
  free(reqData.query.buffer);
  httpS_Request_Delete(reqServer);
  sock_Method_Delete(onReceive);
  if(!hasExecuted) {
    return NULL;
  }
  return response;
}

void dummyOnFrameMethod(void *buffer) {
  PHttpServer server = buffer;
  httpS_OnFrame(server, 1);
}

PHttpResponse http_Helper_Process(PHttpServer server, PHttpRequest req) {
  PSocketMethod onFrame = sock_Method_Create(
    (void *)dummyOnFrameMethod,
    server
  );
  PHttpResponse resp = http_Helper_Send(server->server->port, req, onFrame);
  sock_Method_Delete(onFrame);
  return resp;
}

PHttpResponse _caller(PHttpRequest req, void *mirror) {
  PHttpResponse empty = http_Response_Empty();
  HttpString str = {
    .buffer = "SOME_BUFFER_SOMER_BUFFER",
    .sz = sizeof("SOME_BUFFER_SOMER_BUFFER") - 1
  };
  http_Response_SetBody(empty, &str);
  return empty;
}

PSocketMethod http_Helper_MirrorMethod(void *mirror) {
  PSocketMethod socket = sock_Method_Create(
    (void *)_caller,
    mirror
  );
  return socket;
}

void http_Helper_Free(PHttpServer server) {
  sock_Method_Delete(server->onReceive);
  httpS_Delete(server);
}

void http_Helper_StressTest(PHttpServer server, size_t requestCounts, uint8_t (*finishCondition)(void *), void *buffer) {
  // to do
}