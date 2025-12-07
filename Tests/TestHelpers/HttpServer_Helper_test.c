#include "HttpServer_Helper_test.h"
#include "Socket_Helper_test.h"

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

PHttpResponse http_Helper_Send(PHttpServer server, uint16_t port, PHttpRequest req) {
  return NULL;
  // PConnection connection = test_Util_Connect(server->server);
  // HttpString str = 

  // void test_Util_SendMessage(PSocketServer server, PConnection conn, char *msg, size_t sz);
}

void http_Helper_Free(PHttpServer server) {
  sock_Method_Delete(server->onReceive);
  httpS_Delete(server);
}