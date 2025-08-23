#pragma once
#include "Vector.h"
#include <stdint.h>
#include <stddef.h>

struct Splitter_t {
  Vector lines;
};

typedef struct Splitter_t Splitter;

Splitter split(char *buffer, size_t size, char *splitter, size_t splitterSize);
char *splitter_GetLine(Splitter self, size_t index);
size_t splitter_GetSize(Splitter self, size_t index);
size_t splitter_Count(Splitter self);
void splitter_Free(Splitter self);