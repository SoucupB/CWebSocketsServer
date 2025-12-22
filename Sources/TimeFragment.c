#include "TimeFragment.h"
#include <sys/time.h>
#include "Array.h"

uint64_t tf_CurrentTimeMS() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

PTimeServer tf_Create() {
  PTimeServer self = malloc(sizeof(TimeServer));
  self->methods = vct_Init(sizeof(TimeFragment));
  self->loopMethods = vct_Init(sizeof(TimeFragment));
  return self;
}

void tf_Delete(PTimeServer self) {
  vct_Delete(self->methods);
  vct_Delete(self->loopMethods);
  free(self);
}

void tf_ExecuteAfter(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS) {
  TimeFragment fragment = (TimeFragment) {
    .executeAfter = afterMS,
    .methodFragment = currentMethod
  };
  vct_Push(self->methods, &fragment);
}

static inline void tf_ExecuteFragMethods(PTimeServer self, uint64_t deltaMS) {
  TimeFragment *fragment = self->methods->buffer;
  Array fragmentsToRemove = vct_Init(sizeof(size_t));
  for(size_t i = 0, c = self->methods->size; i < c; i++) {
    fragment[i].executeAfter -= (int64_t)deltaMS;
    if(fragment[i].executeAfter <= 0) {
      void (*method)(void *) = fragment[i].methodFragment.method;
      method(fragment[i].methodFragment.buffer);
      vct_Push(fragmentsToRemove, &i);
    }
  }
  Array cpyVector = vct_RemoveElements(self->methods, fragmentsToRemove);
  vct_Delete(self->methods);
  self->methods = cpyVector;
  vct_Delete(fragmentsToRemove);
}

static inline void tf_ExecuteLoopMethods(PTimeServer self, uint64_t deltaMS) {
  TimeFragment *fragment = self->loopMethods->buffer;
  for(size_t i = 0, c = self->loopMethods->size; i < c; i++) {
    fragment[i].executeAfter -= (int64_t)deltaMS;
    if(fragment[i].executeAfter <= 0) {
      void (*method)(void *) = fragment[i].methodFragment.method;
      method(fragment[i].methodFragment.buffer);
      fragment[i].executeAfter = fragment[i].time;
    }
  }
}

void tf_ExecuteLoop(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS) {
  TimeFragment fragment = (TimeFragment) {
    .executeAfter = afterMS,
    .methodFragment = currentMethod,
    .time = afterMS
  };
  vct_Push(self->loopMethods, &fragment);
}

void tf_OnFrame(PTimeServer self, uint64_t deltaMS) {
  tf_ExecuteFragMethods(self, deltaMS);
  tf_ExecuteLoopMethods(self, deltaMS);
}