#include <stdio.h>
#include "SocketServer.h"
#include <unistd.h>
#include "TimeFragment.h"
#include "HttpParser.h"

void onConnectPlm(Connection conn, void *buffer) {
  printf("Connected mr %d\n", conn.fd);
}

void onReceiveMessage(DataFragment *dataFragment, void *buffer) {
  PSocketServer sv = buffer;
  PHttpRequest req = http_Request_Parse(dataFragment->data, dataFragment->size);
  PHttpResponse response = http_Response_Create();
  HttpString stre = {
    .buffer = "pengus mengus yolo",
    .sz = sizeof("pengus mengus yolo") - 1
  };
  http_Response_SetBody(response, &stre);
  char *msg = dataFragment->data;
  for(size_t i = 0; i < dataFragment->size; i++) {
    printf("%c", msg[i]);
  }
  printf("\n");
  printf("Message receive! with size %d %p\n", dataFragment->size, req);
  HttpString responseBuffer = http_Response_ToString(response);
  DataFragment fragment = {
    .conn = dataFragment->conn,
    .persistent = 1,
    .data = responseBuffer.buffer,
    .size = responseBuffer.sz
  };
  sock_Write_Push(sv, &fragment);
  if(req) {
    http_Request_Delete(req);
  }
  http_Response_Delete(response);
  sock_PushCloseConnections(sv, &dataFragment->conn);
}

int main() {
  PSocketServer server = sock_Create(8080);
  PSocketMethod onConnect = sock_Method_Create(
    (void *)onConnectPlm,
    NULL
  );
  PSocketMethod onReceive = sock_Method_Create(
    (void *)onReceiveMessage,
    server
  );
  server->onConnectionAquire = onConnect;
  server->onReceiveMessage = onReceive;
  sock_AddConnectionTimeout(server, 2000);
  uint64_t currentTimestamp = tf_CurrentTimeMS();
  printf("Server initialized!\n");
  while(1) {
    uint64_t currentTime = tf_CurrentTimeMS();
    sock_OnFrame(server, currentTime - currentTimestamp);
    currentTimestamp = currentTime;
    usleep(64 * 1000);
  }
  sock_Method_Delete(onConnect);
  sock_Method_Delete(onReceive);
  sock_Delete(server);
  return 0;
}