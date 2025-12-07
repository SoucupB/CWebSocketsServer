#include <stdio.h>
#include <unistd.h>
#include "SocketServer.h"
#include "HttpParser.h"
#include "HttpServer.h"
#include "TimeFragment.h"

PHttpResponse caller(PHttpRequest req, void *mirror) {
  return http_Response_Empty();
}

int main()
{
  PHttpServer server = httpS_Create(8080);
  printf("Server initialized!\n");
  PSocketMethod onReceive = sock_Method_Create(
    (void *)caller,
    server
  );
  server->onReceive = onReceive;
  uint64_t currentTimestamp = tf_CurrentTimeMS();
  while (1)
  {
    uint64_t currentTime = tf_CurrentTimeMS();
    httpS_OnFrame(server, currentTime - currentTimestamp);
    currentTimestamp = currentTime;
    usleep(32 * 1000);
  }
  httpS_Delete(server);
  sock_Method_Delete(onReceive);
}