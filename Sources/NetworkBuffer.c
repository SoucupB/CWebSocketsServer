#include "NetworkBuffer.h"
#include <stdlib.h>

PNetworkBuffer tpd_Create(size_t maxSizeB) {
  PNetworkBuffer self = malloc(sizeof(NetworkBuffer));

  return self;
}

void tpd_Delete(PNetworkBuffer self) {

}

size_t tpd_Size(PNetworkBuffer self) {
  return self->size;
}

void tpd_Retract(PNetworkBuffer self, size_t bytes) {

}

void *tpd_StartingBuffer(PNetworkBuffer self) {
  return NULL;
}

void tpd_Push(PNetworkBuffer self, void *buffer, size_t size) {

}