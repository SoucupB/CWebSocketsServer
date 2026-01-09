#pragma once
#include <stdint.h>
#include <stddef.h>
#include "Structs.h"

/*
 * A method which creates a pointer to a socket server
 * This server can be used to register events (methods in this case) such as
 * onConnectionRelease, onConnectionAquire, onReceiveMessage
 * These events will be be triggered based on the action is taken, 
 * onConnectionRelease -> When somebody closes the connection.
 * onConnectionAquire -> When a new connection arrives.
 * onReceiveMessage -> When a buffer is received through the socket.
 */
PSocketServer sock_Create(uint16_t port);

/*
 * Free the Pointer alocked from sock_Create
 */
void sock_Delete(PSocketServer self);
/*
 * This is the method that should be executed in a loop.
 * Since its single threaded, the callback hooks will be 
 * executed only when this method runs.
 * deltaMS is the ms difference between the current time and the 
 * last time this time this methods executes.
 */
void sock_OnFrame(PSocketServer self, uint64_t deltaMS);
/* 
 * This method pushes data to be sent towards the receiver.
 * The message is not sent right away, its only sent on `sock_OnFrame`.
 * DataFragment is a struct which contains data regarding
 * the message sent.
 * data -> the send buffer.
 * size -> the size of the payload sent. (32 bits max value).
 * persistent -> 0/1, If the flag is set on 1, then the buffer on data will also be stored on the heap,
 * and will be released by the PSocketServer routine. If the flag is set on 0, then the data sent on
 * `data` should be freed by the caller, or by a workflow independent of the PSocketServer flow.
 * Also, if persistent is 0, data SHOULD NOT be set with a pointer created on the stack. (Undefined behaviour).
 */
void sock_Write_Push(PSocketServer self, DataFragment *dt);
/*
 * This method returns the number of active connections,
 * The number might not be accurate since the clients might not 
 * send a closing package. `sock_Write_Push` will however find out
 * which connections are closing and which are not.
 */
size_t sock_ConnectionCount(PSocketServer self);
/*
 * Set the maximum number of a addmited connections.
 */
// Default is set to 16 max connections
void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections);
/*
 * This method will push a connection close request.
 * The connection closing request will only happen when this
 * method `sock_OnFrame` runs.
 */
void sock_PushCloseConnections(PSocketServer self, PConnection conn);
/*
 * This method will instantly close the connections.
 */
void sock_CloseConnection(PSocketServer self, size_t index);
/*
 * This method is used to create the callback methods.
 */
PSocketMethod sock_Method_Create(void *method, void *mirrorBuffer);
/*
 * Releases the method that was created by `sock_Method_Create`
 */
void sock_Method_Delete(PSocketMethod self);
/*
 * An invalid socket method
 */
Connection sock_InvalidConnection();
/*
 * An invalid socket checker
 */
uint8_t sock_IsInvalid(Connection conn);