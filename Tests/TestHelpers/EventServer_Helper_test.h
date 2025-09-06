#pragma once
#include "EventServer.h"

void test_Util_Evs_Delete(PEventServer self);
void test_Util_Evs_SendClearMessage(PEventServer evServer, PConnection conn, char *msg, uint32_t sz, uint32_t code);
void test_Util_Evs_SendAuthMessage(PEventServer evServer, PConnection conn, char *msg, uint32_t sz, char *authCode, uint32_t code);