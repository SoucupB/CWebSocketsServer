#include <stdio.h>
#include "Socket.h"
#include <unistd.h>

void onConnectPlm(Connection conn, void *buffer) {
  printf("Connected mr %d\n", conn.fd);
}

void onReceiveMessage(DataFragment *dataFragment, void *buffer) {
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
  printf("Server initialized!\n");
  while(1) {
    sock_OnFrame(server);
    usleep(124 * 1000);
  }
  sock_Method_Delete(onConnect);
  sock_Method_Delete(onReceive);
  sock_Delete(server);
  return 0;
}