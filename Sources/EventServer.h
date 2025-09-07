#pragma once
#include <stdint.h>
#include <stddef.h>
#include "Structs.h"

PEventServer evs_Create(uint16_t port);
void evs_Delete(PEventServer self);
void evs_OnFrame(PEventServer self, uint64_t deltaMS);
void evs_PushMessage(PEventServer self, PResponseObject msg);