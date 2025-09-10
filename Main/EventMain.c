#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "SocketServer.h"   // Custom socket server abstraction
#include "HttpParser.h"     // Utilities for HTTP parsing
#include "EventServer.h"    // EventServer abstraction for message handling
#include "TimeFragment.h"   // Utilities for timestamps

// Callback triggered when a new connection is established
void onConnectPlm(PConnection conn, void *buffer) {
  printf("Connected mr %d\n", conn->fd); // Log connection file descriptor
}

// Callback triggered when a message is received from a client
void onReceiveMessage(PResponseObject dt, void *buffer) {
  PEventServer self = buffer; // Cast buffer to the server instance

  // Prepare authentication code
  Auth code;
  char *authCode = "32425666";
  memcpy(code.bff, authCode, sizeof(Auth)); // Copy auth string into Auth struct

  // Construct a response message
  ResponseObject response = {
    .conn = dt->conn,  // Send back to the same connection
    .metaData = (EventMessage) {
      .headerCode = 123,     // Arbitrary header code
      .uniqueCode = code,    // Auth code
      .isAuthed = 1,         // Flag indicating authentication
      .str = (EventBuffer) { // Payload buffer
        .buffer = "test",
        .size = sizeof("test") - 1
      }
    }
  };

  // Send the response back to the client
  evs_PushMessage(self, &response);

  // Log the auth code if the received message was authenticated
  if(dt->metaData.isAuthed) {
    printf("Auth code %.*s\n", 8, dt->metaData.uniqueCode.bff);
  }

  // Log the received message details
  printf("Some message received %d %d -> %d <- `%.*s`\n",
    dt->metaData.headerCode,
    dt->metaData.isAuthed,
    dt->metaData.str.size,
    dt->metaData.str.size,
    dt->metaData.str.buffer);
}

// Callback triggered when a connection is closed
void onDisconnectRoutine(PConnection conn, void *buffer) {
  printf("Disconnected from %d\n", conn->fd);
}

int main() {
  // Create an EventServer listening on port 8080
  PEventServer server = evs_Create(8080);

  // Get current timestamp in milliseconds
  uint64_t currentTimestamp = tf_CurrentTimeMS();
  printf("Server initialized!\n");

  // Wrap the callbacks in socket methods
  PSocketMethod onConnect = sock_Method_Create(
    (void *)onConnectPlm, // Connection callback
    NULL                   // No additional buffer needed
  );

  PSocketMethod onReceive = sock_Method_Create(
    (void *)onReceiveMessage, // Receive callback
    server                     // Pass server instance as buffer
  );

  PSocketMethod onDisconnect = sock_Method_Create(
    (void *)onDisconnectRoutine, // Disconnect callback
    server
  );

  // Assign callbacks to the server
  server->onReceive = onReceive;
  server->onClose = onDisconnect;

  // Enable ping/pong timeout for idle connections (10 seconds)
  evs_EnablePingPongTimeout(server, 10000);

  // Main server loop
  while(1) {
    uint64_t currentTime = tf_CurrentTimeMS();

    // Process incoming frames, events, and timeouts
    evs_OnFrame(server, currentTime - currentTimestamp);

    currentTimestamp = currentTime;

    // Sleep ~32ms to avoid busy-waiting (~30 FPS)
    usleep(32 * 1000);
  }

  // Cleanup resources (not reached due to infinite loop)
  evs_Delete(server);
  sock_Method_Delete(onConnect);
  sock_Method_Delete(onReceive);
  sock_Method_Delete(onDisconnect);
}
