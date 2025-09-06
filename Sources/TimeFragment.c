#include "TimeFragment.h"
#include <sys/time.h>
#include "Vector.h"

uint64_t tf_CurrentTimeMS() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

PTimeServer tf_Create() {
  PTimeServer self = malloc(sizeof(TimeServer));
  self->methods = vct_Init(sizeof(TimeFragment));
  return self;
}

void tf_Delete(PTimeServer self) {
  vct_Delete(self->methods);
  free(self);
}

void tf_ExecuteAfter(PTimeServer self, TimeMethod currentMethod, uint64_t afterMS) {
  TimeFragment fragment = (TimeFragment) {
    .executeAfter = afterMS,
    .methodFragment = currentMethod
  };
  vct_Push(self->methods, &fragment);
}

static inline void tf_ExecuteMethods(PTimeServer self, uint64_t deltaMS) {
  TimeFragment *fragment = self->methods->buffer;
  Vector fragmentsToRemove = vct_Init(sizeof(size_t));
  for(size_t i = 0, c = self->methods->size; i < c; i++) {
    fragment[i].executeAfter -= (int64_t)deltaMS;
    if(fragment[i].executeAfter <= 0) {
      void (*method)(void *) = fragment[i].methodFragment.method;
      method(fragment[i].methodFragment.buffer);
      vct_Push(fragmentsToRemove, &i);
    }
  }
  Vector cpyVector = vct_RemoveElements(self->methods, fragmentsToRemove);
  vct_Delete(self->methods);
  self->methods = cpyVector;
  vct_Delete(fragmentsToRemove);
}

void tf_OnFrame(PTimeServer self, uint64_t deltaMS) {
  tf_ExecuteMethods(self, deltaMS);
}