#include <stdio.h>
#include "SocketServer.h"
#include <unistd.h>
#include "HttpParser.h"
#include "EventMessage.h"
#include "TimeFragment.h"

void onConnectPlm(PConnection conn, void *buffer) {
  printf("Connected mr %d\n", conn->fd);
}

void onReceiveMessage(PResponseObject dt, void *buffer) {
  PWebSocketServer self = buffer;
  printf("Some message\n");
  // PWebSocketServer self = buffer;
  // printf("Receive messages `%.*s` with conn %d\n", (int32_t)frag->size, frag->data, frag->conn.fd);
  // DataFragment nextFrag = {
  //   .conn = frag->conn,
  //   .data = "Echo",
  //   .size = sizeof("Echo") - 1
  // };
  // wss_SendMessage(self, &nextFrag);
  // printf("Message echo back\n");
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
  // wss_EnablePingPongTimeout(server, 2500);
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