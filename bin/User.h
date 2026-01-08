#pragma once
#include "SocketServer.h"
#include "SocketClient.h"
#include "Structs.h"

PUserData usrs_Create();
size_t usrs_ConnID(PUserData self, PConnection conn, uint8_t *ok);
PUser usrs_Activate(PUserData self, uint64_t ID, PConnection conn);
PUser usrs_Get(PUserData self, uint64_t ID);
PUser usrs_ByIndex(PUserData self, uint64_t index);
PUser usrs_ByConnection(PUserData self, PConnection conn);
void usrs_Deactivate(PUserData self, PConnection conn);
void usrs_Delete(PUserData self);
void usrs_AddUser(PUserData self, uint64_t ID);
void usr_Deactivate(PUser self);