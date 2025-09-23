#include <stdio.h>
#include <unistd.h>
#include "SocketServer.h"
#include "HttpParser.h"
#include "WebSocketServer.h"
#include "TimeFragment.h"

// Called when a new connection is established
void onConnectRoutine(PConnection conn, void *buffer)
{
  printf("Connected mr %d\n", conn->fd); // Print the file descriptor of the new connection
}

// Called when a message is received from a client
void onReceiveMessage(PDataFragment frag, void *buffer)
{
  PWebSocketServer self = buffer; // Cast buffer to our server instance

  // Print the received message and the connection FD
  printf("Receive messages `%.*s` with conn %d\n", (int32_t)frag->size, frag->data, frag->conn.fd);

  // Prepare an echo message back to the client
  DataFragment nextFrag = {
      .conn = frag->conn,        // Send back to the same connection
      .data = "Echo",            // Message content
      .size = sizeof("Echo") - 1 // Length of the message
  };

  // Send the echo message
  wss_SendMessage(self, &nextFrag);
  printf("Message echo back\n");
}

// Called when a connection is closed
void onDisconnectRoutine(Connection conn, void *buffer)
{
  printf("Disconnected from %d\n", conn.fd); // Print FD of disconnected client
}

int main()
{
  // Create a WebSocket server on port 8080
  PWebSocketServer server = wss_Create(8080);

  // Get current timestamp (in milliseconds)
  uint64_t currentTimestamp = tf_CurrentTimeMS();
  printf("Server initialized!\n");

  // Wrap the connection callback in a socket method
  PSocketMethod onConnect = sock_Method_Create(
      (void *)onConnectRoutine, // Function pointer
      NULL                      // No additional buffer needed
  );

  // Wrap the receive callback
  PSocketMethod onReceive = sock_Method_Create(
      (void *)onReceiveMessage, // Function pointer
      server                    // Pass server instance as buffer
  );

  // Wrap the disconnect callback
  PSocketMethod onDisconnect = sock_Method_Create(
      (void *)onDisconnectRoutine,
      server);

  // Assign callbacks to the server
  server->onConnect = onConnect;
  server->onReceiveMessage = onReceive;
  server->onRelease = onDisconnect;

  // Enable ping/pong timeout for client connections (2.5 seconds)
  wss_EnablePingPongTimeout(server, 2500);

  // Main server loop
  while (1)
  {
    uint64_t currentTime = tf_CurrentTimeMS();

    // Process WebSocket frames. The second param is the delta MS which was computed between the last and the current ocurring frame.
    wss_OnFrame(server, currentTime - currentTimestamp);

    currentTimestamp = currentTime;

    // Sleep ~32ms to avoid busy-waiting (approx 30 FPS)
    usleep(32 * 1000);
  }

  // Clean up server and socket methods (not reached in this infinite loop)
  wss_Delete(server);
  sock_Method_Delete(onConnect);
  sock_Method_Delete(onReceive);
  sock_Method_Delete(onDisconnect);
}