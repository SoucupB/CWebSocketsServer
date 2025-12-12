#pragma once
#include "Structs.h"

PConnection sock_Client_Connect(uint16_t port, char *ip);
void sock_Client_SendMessage(PDataFragment frag);
void sock_Client_Free(PConnection conn);
DataFragment sock_Client_Receive(PConnection conn);
HttpString sock_Client_ReceiveWithErrors(PConnection conn);