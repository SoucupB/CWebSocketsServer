#pragma once
#include "NetworkBuffer.h"

typedef struct {
  PNetworkBuffer buff;
} NetBufferHelper;

NetBufferHelper ntb_Create(size_t maxBSize);
