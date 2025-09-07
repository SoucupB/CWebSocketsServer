#include <stdio.h>
#include "SocketServer.h"
#include <unistd.h>
#include "HttpParser.h"
#include "WebSocketServer.h"
#include "TimeFragment.h"

void onConnectPlm(PConnection conn, void *buffer) {
  printf("Connected mr %d\n", conn->fd);
}

void onReceiveMessage(PDataFragment frag, void *buffer) {
  PWebSocketServer self = buffer;
  printf("Receive messages `%.*s` with conn %d\n", (int32_t)frag->size, frag->data, frag->conn.fd);
  DataFragment nextFrag = {
    .conn = frag->conn,
    .data = "Echo",
    .size = sizeof("Echo") - 1
  };
  wss_SendMessage(self, &nextFrag);
  printf("Message echo back\n");
}

void onDisconnectRoutine(Connection conn, void *buffer) {
  printf("Disconnected from %d\n", conn.fd);
}

int main() {
  PWebSocketServer server = wss_Create(8080);
  uint64_t currentTimestamp = tf_CurrentTimeMS();
  printf("Server initialized!\n");
  PSocketMethod onConnect = sock_Method_Create(
    (void *)onConnectPlm,
    NULL
  );
  PSocketMethod onReceive = sock_Method_Create(
    (void *)onReceiveMessage,
    server
  );
  PSocketMethod onDisconnect = sock_Method_Create(
    (void *)onDisconnectRoutine,
    server
  );
  server->onConnect = onConnect;
  server->onReceiveMessage = onReceive;
  server->onRelease = onDisconnect;
  wss_EnablePingPongTimeout(server, 2500);
  while(1) {
    uint64_t currentTime = tf_CurrentTimeMS();
    wss_OnFrame(server, currentTime - currentTimestamp);
    currentTimestamp = currentTime;
    usleep(32 * 1000);
  }
  wss_Delete(server);
  sock_Method_Delete(onConnect);
  sock_Method_Delete(onReceive);
  sock_Method_Delete(onDisconnect);
}

// void onReceiveMessage(DataFragment *dataFragment, void *buffer) {
//   PSocketServer sv = buffer;
//   PHttpRequest req = http_Request_Parse(dataFragment->data, dataFragment->size);
//   PHttpResponse response = http_Response_Create();
//   HttpString stre = {
//     .buffer = "pengus mengus yolo",
//     .sz = sizeof("pengus mengus yolo") - 1
//   };
//   http_Response_SetBody(response, &stre);
//   char *msg = dataFragment->data;
//   for(size_t i = 0; i < dataFragment->size; i++) {
//     printf("%c", msg[i]);
//   }
//   printf("\n");
//   printf("Message receive! with size %d %p\n", dataFragment->size, req);
//   HttpString echoValue = http_Request_GetValue(req, "echo");
//   if(echoValue.buffer) {
//     http_Response_Set(response, "vola", sizeof("vola") - 1, echoValue.buffer, echoValue.sz);
//   }
//   HttpString responseBuffer = http_Response_ToString(response);
//   DataFragment fragment = {
//     .conn = dataFragment->conn,
//     .persistent = 1,
//     .data = responseBuffer.buffer,
//     .size = responseBuffer.sz
//   };
//   sock_Write_Push(sv, &fragment);
//   if(req) {
//     http_Request_Delete(req);
//   }
//   http_Response_Delete(response);
//   sock_PushCloseConnections(sv, &dataFragment->conn);
// }

// int main() {
//   PSocketServer server = sock_Create(8080);
//   PSocketMethod onConnect = sock_Method_Create(
//     (void *)onConnectPlm,
//     NULL
//   );
//   PSocketMethod onReceive = sock_Method_Create(
//     (void *)onReceiveMessage,
//     server
//   );
//   server->onConnectionAquire = onConnect;
//   server->onReceiveMessage = onReceive;
//   sock_AddConnectionTimeout(server, 2000);
//   uint64_t currentTimestamp = tf_CurrentTimeMS();
//   printf("Server initialized!\n");
//   while(1) {
//     uint64_t currentTime = tf_CurrentTimeMS();
//     sock_OnFrame(server, currentTime - currentTimestamp);
//     currentTimestamp = currentTime;
//     usleep(64 * 1000);
//   }
//   sock_Method_Delete(onConnect);
//   sock_Method_Delete(onReceive);
//   sock_Delete(server);
//   return 0;
// }