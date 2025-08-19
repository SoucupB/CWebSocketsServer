#include <stdio.h>
#include "SocketServer.h"
#include <unistd.h>
#include "TimeFragment.h"

void onConnectPlm(Connection conn, void *buffer) {
  printf("Connected mr %d\n", conn.fd);
}

void onReceiveMessage(DataFragment *dataFragment, void *buffer) {
  char *msg = dataFragment->data;
  for(size_t i = 0; i < dataFragment->size; i++) {
    printf("%c", msg[i]);
  }
  printf("\n");
  printf("Message receive!\n");
}

int main() {
  PSocketServer server = sock_Create(8080);
  PSocketMethod onConnect = sock_Method_Create(
    (void *)onConnectPlm,
    NULL
  );
  PSocketMethod onReceive = sock_Method_Create(
    (void *)onReceiveMessage,
    NULL
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