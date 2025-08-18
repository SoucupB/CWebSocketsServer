#pragma once
#include <stdint.h>
#include "Vector.h"

typedef struct TimeMethod_t {
  void *method;
  void *buffer;
} TimeMethod;

typedef struct TimeFragment_t {
  TimeMethod methodFragment;
  int64_t executeAfter;
} TimeFragment;

typedef struct TimeServer_t {
  Vector methods;
} TimeServer;

typedef TimeServer *PTimeServer;

PTimeServer tf_Create();
void tf_OnFrame(PTimeServer self, uint64_t deltaMS);
void tf_Delete(PTimeServer self);
void tf_ExecuteAfter(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS);
uint64_t tf_CurrentTimeMS();