#include <stdio.h>
#include <unistd.h>
#include "SocketServer.h"
#include "HttpParser.h"
#include "HttpServer.h"
#include "JsonParser.h"
#include "TimeFragment.h"
#include "GameNetworkManager.h"

void onLogin(PUser user, void *mirror) {
  printf("User logged on!");
}

int main()
{
  PManager manager = man_Create(8080);
  man_SetSecret(manager, (HttpString) {
    .buffer = "IDHhudhgiusghUGYIYFFdsaf33312244444444444444223214141",
    .sz = sizeof("IDHhudhgiusghUGYIYFFdsaf33312244444444444444223214141")
  });
  man_UserRegister(manager, 32455);
  printf("Server initialized!\n");
  PSocketMethod onReceive = sock_Method_Create(
    (void *)onLogin,
    manager
  );
  manager->onLogin = onReceive;
  uint64_t currentTimestamp = tf_CurrentTimeMS();
  while (1)
  {
    uint64_t currentTime = tf_CurrentTimeMS();
    man_OnFrame(manager, currentTime - currentTimestamp);
    currentTimestamp = currentTime;
    usleep(64 * 1000);
  }
  man_Delete(manager);
  sock_Method_Delete(onReceive);
  // PHttpServer server = httpS_Create(8080);
  // printf("Server initialized!\n");
  // PSocketMethod onReceive = sock_Method_Create(
  //   (void *)caller,
  //   server
  // );
  // server->onReceive = onReceive;
  // uint64_t currentTimestamp = tf_CurrentTimeMS();
  // while (1)
  // {
  //   uint64_t currentTime = tf_CurrentTimeMS();
  //   httpS_OnFrame(server, currentTime - currentTimestamp);
  //   currentTimestamp = currentTime;
  //   usleep(4 * 1000);
  // }
  // httpS_Delete(server);
  // sock_Method_Delete(onReceive);
}