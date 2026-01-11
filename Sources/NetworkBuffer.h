#pragma once

#include "Structs.h"

PNetworkBuffer tpd_Create(size_t maxSizeB);
void tpd_Delete(PNetworkBuffer self);
uint8_t tpd_Push(PNetworkBuffer self, void *buffer, size_t size);
size_t tpd_Size(PNetworkBuffer self);
void tpd_Retract(PNetworkBuffer self, size_t bytes);
void *tpd_StartingBuffer(PNetworkBuffer self);
void tpd_DeleteWOBuffer(PNetworkBuffer self);