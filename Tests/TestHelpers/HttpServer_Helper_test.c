#include "HttpServer_Helper_test.h"

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

void http_Helper_Free(PHttpServer server) {
  sock_Method_Delete(server->onReceive);
  httpS_Delete(server);
}