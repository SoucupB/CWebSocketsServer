#pragma once
#include <stdint.h>
#include "Vector.h"
#include "Structs.h"

PTimeServer tf_Create();
void tf_OnFrame(PTimeServer self, uint64_t deltaMS);
void tf_Delete(PTimeServer self);
void tf_ExecuteAfter(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS);
uint64_t tf_CurrentTimeMS();