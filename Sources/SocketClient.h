#pragma once

#include "SocketCommon.h"

PConnection sock_Client_Connect(uint16_t port, char *ip);
void sock_Client_SendMessage(PDataFragment frag);