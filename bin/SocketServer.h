#pragma once

#include <stdint.h>
#include <stddef.h>
#include "Structs.h"

PSocketServer sock_Create(uint16_t port);
void sock_Delete(PSocketServer self);
void sock_OnFrame(PSocketServer self, uint64_t deltaMS);
void sock_Write_Push(PSocketServer self, DataFragment *dt);
PConnection sock_FindConnectionByIndex(PSocketServer self, size_t index);
size_t sock_ConnectionCount(PSocketServer self);
// Default is set to 16 max connections
void sock_SetMaxConnections(PSocketServer self, int32_t maxActiveConnections);
void sock_AddConnectionTimeout(PSocketServer self, int64_t expireAfter);
void sock_PushCloseConnections(PSocketServer self, PConnection conn);
void sock_CloseConnection(PSocketServer self, size_t index);

PSocketMethod sock_Method_Create(void *method, void *mirrorBuffer);
void sock_Method_Delete(PSocketMethod self);