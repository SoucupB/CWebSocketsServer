#include <stdio.h>
#include <unistd.h>
#include "SocketServer.h"
#include "HttpParser.h"
#include "HttpServer.h"
#include "JsonParser.h"
#include "TimeFragment.h"

void onSuccess(PHttpResponse req, void *mirror) {
  HttpString str = http_Response_ToString(req);
  printf("Received!\n%.*s\n", str.sz, str.buffer);
}

int main()
{
  PHttpRequestServer req = httpS_Request_Create(5000);
  printf("Server initialized!\n");
  PSocketMethod onReceive = sock_Method_Create(
    (void *)onSuccess,
    NULL
  );
  uint64_t currentTimestamp = tf_CurrentTimeMS();
  HttpString ip = {
    .buffer = "127.0.0.1",
    .sz = sizeof("127.0.0.1") - 1
  };
  PHttpRequest httpReq = http_Request_Create();
  http_Request_AddHeader(httpReq, "Accept", "*/*");
  http_Request_AddHeader(httpReq, "Accept-Encoding", "gzip, deflate, br");
  http_Request_AddHeader(httpReq, "Connection", "keep-alive");
  RequestStruct reqData = httpS_Request_StructInit(ip, 8000);
  reqData.query = http_Request_ToString(httpReq);
  reqData.onSuccess = onReceive;
  httpS_Request_Send(req, reqData);
  while (1)
  {
    uint64_t currentTime = tf_CurrentTimeMS();
    httpS_Request_OnFrame(req, currentTime - currentTimestamp);
    currentTimestamp = currentTime;
    usleep(1000 * 1000);
  }
  httpS_Request_Delete(req);
  sock_Method_Delete(onReceive);
}