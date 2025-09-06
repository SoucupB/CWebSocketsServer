#pragma once
#include <stddef.h>
#include <stdint.h>
#include "Structs.h"

EventBuffer evm_New_Transform(const PEventMessage self);
EventBuffer evm_Reuse_Transform(const PEventMessage self, char *buffer);
EventMessage evm_Parse(EventBuffer buffer, uint8_t *valid);
uint32_t evm_Out_Public_TotalSize(PEventMessage self);