#include <stdio.h>
#include "Socket.h"

int main() {
  PSocketServer server = sock_Create(8080);
  printf("Server initialized!\n");
  sock_Delete(server);
  return 0;
}