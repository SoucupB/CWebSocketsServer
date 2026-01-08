#pragma once
#include <stdint.h>
#include <stdio.h>
#include "Structs.h"
#include "HttpServer.h"
#include "WebSocketServer.h"
#include "Array.h"
#include "User.h"
#include "JsonParser.h"
#include "HttpServer.h"
#include "TimeFragment.h"

PManager man_Create(uint16_t port);
void man_Delete(PManager self);
void man_OnFrame(PManager self, uint64_t deltaMS);
void man_SetSecret(PManager self, HttpString hmacKey);
PUser man_User_Get(PManager self, uint64_t ID);
void man_SendMessage(const PManager self, const PDataFragment dt);