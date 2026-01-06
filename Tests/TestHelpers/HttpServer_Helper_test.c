#include "HttpServer_Helper_test.h"
#include "Socket_Helper_test.h"
#include "HttpParser.h"
#include <stdlib.h>
#include <unistd.h>
#include "Array.h"

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

HttpString http_Helper_SendBlockingRequest(PHttpServer server, uint16_t port, HttpString str) {
  PConnection conn = sock_Client_Connect(port, "127.0.0.1");
  DataFragment fr = {
    .conn = *conn,
    .data = str.buffer,
    .persistent = 0,
    .size = str.sz
  };
  sock_Client_SendMessage(&fr);
  HttpString serv;
  memset(&serv, 0, sizeof(HttpString));
  int32_t totalTries = 5000;
  while(totalTries--) {
    serv = sock_Client_ReceiveWithErrors(conn);
    if(serv.sz) {
      break;
    }
    httpS_OnFrame(server, 1);
    usleep(1000);
    free(serv.buffer);
  }
  return serv;
}

typedef struct ConnComm_t {
  PSocketMethod child;
  PHttpServer server;
  Array response;
  uint32_t callerCount;
} ConnComm;

typedef ConnComm *PConnComm;

PHttpResponse intermediateCaller(PHttpRequest req, void *mirror) {
  PConnComm currentCom = mirror;
  PHttpResponse (*childCaller)(PHttpRequest, void *) = currentCom->child->method;
  PHttpResponse childResponse = childCaller(req, currentCom->child->mirrorBuffer);
  HttpString respString = http_Response_ToString(childResponse);
  arr_Push(currentCom->response, &respString);
  return childResponse;
}

void http_Helper_ExtractData(PConnComm currComm, HttpString str) {
  PHttpServer server = currComm->server;
  PConnection conn = sock_Client_Connect(server->server->port, "127.0.0.1");
  DataFragment fr = {
    .conn = *conn,
    .data = str.buffer,
    .persistent = 0,
    .size = str.sz
  };
  uint32_t currentCall = currComm->callerCount;
  sock_Client_SendMessage(&fr);
  HttpString serv;
  memset(&serv, 0, sizeof(HttpString));
  while(currComm->callerCount == currentCall) {
    httpS_OnFrame(server, 1);
    usleep(100);
  }
  sock_Client_Free(conn);
}

Array http_Helper_StreamRequest(PHttpServer server, Array requests) {
  Array response = arr_Init(sizeof(HttpString));
  PSocketMethod currentMethod = server->onReceive;
  ConnComm currComm = {
    .child = currentMethod,
    .server = server,
    .response = response,
    .callerCount = 0
  };
  PSocketMethod nextMethod = sock_Method_Create(
    (void *)intermediateCaller,
    &currComm
  );
  server->onReceive = nextMethod;
  HttpString *strReq = requests->buffer;
  for(size_t i = 0, c = requests->size; i < c; i++) {
    http_Helper_ExtractData(&currComm, strReq[i]);
  }
  server->onReceive = currentMethod;
  sock_Method_Delete(nextMethod);
  return response;
}

void http_Helper_FreeStrArray(const Array arr) {
  HttpString *strss = arr->buffer;
  for(size_t i = 0; i < arr->size; i++) {
    free(strss[i].buffer);
  }
  arr_Delete(arr);
}

Array http_Helper_StreamRequestStrings(PHttpServer server, char **strs, size_t count) {
  Array strings = arr_Init(sizeof(HttpString));
  for(size_t i = 0; i < count; i++) {
    HttpString currentString = {
      .buffer = strs[i],
      .sz = strlen(strs[i])
    };
    PHttpRequest req = http_Request_Basic();
    http_Request_SetBody(req, currentString);
    HttpString str = http_Request_ToString(req);
    arr_Push(strings, &str);
    http_Request_Delete(req);
  }
  Array response = http_Helper_StreamRequest(server, strings);
  http_Helper_FreeStrArray(strings);
  return response;
}