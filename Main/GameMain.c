#include <stdio.h>
#include <unistd.h>
#include "SocketServer.h"
#include "HttpParser.h"
#include "HttpServer.h"
#include "JsonParser.h"
#include "TimeFragment.h"
#include "GameNetworkManager.h"

void onLogin(PUser user, void *mirror) {
  printf("User %ld logged on!\n", user->ID);
}

void onDisconnect(PUser user, void *mirror) {
  printf("User %ld disconnected!\n", user->ID);
}

void onReceiveData(PDataFragment dt, PUser user, void *mirror) {
  printf("User %ld receive message %.*s!\n", user->ID, dt->size, dt->data);
}

int main()
{
  PManager manager = man_Create(8080);
  man_SetSecret(manager, (HttpString) {
    .buffer = "IDHhudhgiusghUGYIYFFdsaf33312244444444444444223214141",
    .sz = sizeof("IDHhudhgiusghUGYIYFFdsaf33312244444444444444223214141")
  });
  man_UserRegister(manager, 32455);
  man_InitHTTPServer(manager, 8081);
  printf("Server initialized!\n");
  PSocketMethod onLoginMethod = sock_Method_Create(
    (void *)onLogin,
    manager
  );
  PSocketMethod onRelease = sock_Method_Create(
    (void *)onDisconnect,
    manager
  );
  PSocketMethod onReceiveMethod = sock_Method_Create(
    (void *)onReceiveData,
    manager
  );
  manager->onLogin = onLoginMethod;
  manager->onDisconnect = onRelease;
  manager->onReceive = onReceiveMethod;
  uint64_t currentTimestamp = tf_CurrentTimeMS();
  while (1)
  {
    uint64_t currentTime = tf_CurrentTimeMS();
    man_OnFrame(manager, currentTime - currentTimestamp);
    currentTimestamp = currentTime;
    usleep(64 * 1000);
  }
  man_Delete(manager);
  sock_Method_Delete(onLoginMethod);
  sock_Method_Delete(onRelease);
  sock_Method_Delete(onReceiveMethod);
}