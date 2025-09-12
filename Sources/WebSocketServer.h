#pragma once
#include "Structs.h"

/*
 * This method creates a pointer to a websocket server.
 * It has 3 callback methods `onConnect` `onReceiveMessage` `onRelease`,
 * onConnect happends when a websocket connections handshake is succesfully.
 * onReceiveMessage happends when the client sends a valid websocket message.
 * onRelease happends when the client closes the connection.
 */
PWebSocketServer wss_Create(uint16_t port);
/*
 * Current active connections count, it might not be accurat if the 
 * the client suddenly stops without a closing message.
 */
size_t wss_ConnectionsCount(PWebSocketServer self);
/*
 * This methods should be executed on a loop since its a single threaded method.
 * All the callbacks will only happen during the execution of this method
 */
void wss_OnFrame(PWebSocketServer self, uint64_t deltaMS);
/*
 * This method, enables ping pong connections checker.
 * timeout is the time when in miliseconds that will send a `ping` request towards the clients.
 * If the clients do not respons in (timeout / 2) ms, then, the server will disconnect that connection.
 * The timeout is calculated using the `deltaMS` from `wss_OnFrame`.
 */
void wss_EnablePingPongTimeout(PWebSocketServer self, uint64_t timeout);
/*
 * Frees the server made with `wss_Create`.
 */
void wss_Delete(PWebSocketServer self);
/*
 * Pushes a message to be sent to a stack. `wss_OnFrame` will
 * send all the messages towards the connections.
 */
void wss_SendMessage(PWebSocketServer self, PDataFragment dt);