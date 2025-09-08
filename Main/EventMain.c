#include <stdio.h>
#include "SocketServer.h"
#include <unistd.h>
#include "HttpParser.h"
#include "EventServer.h"
#include "TimeFragment.h"
#include <string.h>

void onConnectPlm(PConnection conn, void *buffer) {
  printf("Connected mr %d\n", conn->fd);
}

void onReceiveMessage(PResponseObject dt, void *buffer) {
  PEventServer self = buffer;
  Auth code;
  char *zrCode = "32425666";
  memcpy(code.bff, zrCode, sizeof(Auth));
  ResponseObject response = {
    .conn = dt->conn,
    .metaData = (EventMessage) {
      .headerCode = 123,
      .uniqueCode = code,
      .isAuthed = 1,
      .str = (EventBuffer) {
        .buffer = "VASILE",
        .size = sizeof("VASILE") - 1
      }
    }
  };

  evs_PushMessage(self, &response);
  if(dt->metaData.isAuthed) {
    printf("Auth code %.*s\n", 8, dt->metaData.uniqueCode.bff);
  }
  printf("Some message received %d %d -> %d <- `%.*s`\n", dt->metaData.headerCode, dt->metaData.isAuthed, dt->metaData.str.size, dt->metaData.str.size, dt->metaData.str.buffer);
}

void onDisconnectRoutine(PConnection conn, void *buffer) {
  printf("Disconnected from %d\n", conn->fd);
}

int main() {
  PEventServer server = evs_Create(8080);
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
  server->onReceive = onReceive;
  server->onClose = onDisconnect;
  evs_EnablePingPongTimeout(server, 10000);
  while(1) {
    uint64_t currentTime = tf_CurrentTimeMS();
    evs_OnFrame(server, currentTime - currentTimestamp);
    currentTimestamp = currentTime;
    usleep(32 * 1000);
  }
  evs_Delete(server);
  sock_Method_Delete(onConnect);
  sock_Method_Delete(onReceive);
  sock_Method_Delete(onDisconnect);
}