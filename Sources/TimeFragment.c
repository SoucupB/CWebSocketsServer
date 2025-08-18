#include "TimeFragment.h"
#include <sys/time.h>

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
    .lastExecutionTimeMS = tf_CurrentTimeMS(),
    .methodFragment = currentMethod
  };
  vct_Push(self->methods, &fragment);
}

void tf_OnFrame(PTimeServer self, uint64_t deltaMS) {

}