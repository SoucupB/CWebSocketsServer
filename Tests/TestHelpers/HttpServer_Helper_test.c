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
  *prc->response = req;
}

PHttpResponse http_Helper_Send(PHttpServer server, uint16_t port, PHttpRequest req) {
  uint32_t hasExecuted = 0;
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
  PHttpRequestServer reqServer = httpS_Request_Create(5000);
  httpS_Request_Send(reqServer, reqData);
  while(1) {
    if(hasExecuted) {
      break;
    }
    httpS_Request_OnFrame(reqServer, 1);
    usleep(1 * 1000);
  }
  free(reqData.query.buffer);
  sock_Method_Delete(onReceive);
  return NULL;
}

void http_Helper_Free(PHttpServer server) {
  sock_Method_Delete(server->onReceive);
  httpS_Delete(server);
}