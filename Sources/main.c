#include <stdio.h>
#include "Socket.h"
#include <unistd.h>

void onConnectPlm(Connection conn, void *buffer) {
  printf("Connected mr %d\n", conn.fd);
}

int main() {
  PSocketServer server = sock_Create(8080);
  PSocketMethod method = sock_Method_Create(
    onConnectPlm,
    NULL
  );
  server->onConnectionAquire = method;
  printf("Server initialized!\n");
  while(1) {
    sock_OnFrame(server);
    usleep(124 * 1000);
  }
  sock_Method_Delete(method);
  sock_Delete(server);
  return 0;
}