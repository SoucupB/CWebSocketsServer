#include "Splitter.h"

uint8_t areStringsEqual(char *child, char *parent, size_t childSize, size_t parentSize);
Vector extract(char *buffer, size_t left, size_t right, size_t size);
void splitString(struct Splitter_t self, char *buffer, size_t size, char *splitter, size_t splitterSize);

Splitter split(char *buffer, size_t size, char *splitter, size_t splitterSize) {
  Splitter self;
  self.lines = vct_Init(sizeof(char *));
  if(size) {
    splitString(self, buffer, size, splitter, splitterSize);
  }
  return self;
}

void splitString(Splitter self, char *buffer, size_t size, char *splitter, size_t splitterSize) {
  size_t lastIndex = 0;
  size_t i = 0;
  while(i < size) {
    if(areStringsEqual(splitter, buffer + i, splitterSize, size - i)) {
      Vector currentSlice = extract(buffer, lastIndex, i - 1, size);
      vct_Push(self.lines, &currentSlice);
      i += splitterSize;
      lastIndex = i;
    }
    else {
      i++;
    }
  }
  Vector currentSlice = extract(buffer, lastIndex, size - 1, size);
  vct_Push(self.lines, &currentSlice);
}

Vector extract(char *buffer, size_t left, size_t right, size_t size) {
  Vector result = vct_Init(sizeof(char));
  for(size_t i = left; i <= right; i++) {
    vct_Push(result, &buffer[i]);
  }
  char endCharacter = '\0';
  vct_Push(result, &endCharacter);
  return result;
}

uint8_t areStringsEqual(char *child, char *parent, size_t childSize, size_t parentSize) {
  if(parentSize < childSize) {
    return 0;
  }
  for(size_t i = 0; i < childSize; i++) {
    if(child[i] != parent[i]) {
      return 0;
    }
  }
  return 1;
}

char *splitter_GetLine(Splitter self, size_t index) {
  if(index >= self.lines->size) {
    return NULL;
  }
  Vector *lines = self.lines->buffer;
  return lines[index]->buffer; 
}

size_t splitter_Count(Splitter self) {
  return self.lines->size;
}

size_t splitter_GetSize(Splitter self, size_t index) {
  if(index >= self.lines->size) {
    return 0;
  } 
  Vector *lines = self.lines->buffer;
  if(!lines[index]->size) {
    return 0;
  }
  return lines[index]->size - 1;
}

void splitter_Free(Splitter self) {
  Vector *lines = self.lines->buffer;
  for(size_t i = 0, c = self.lines->size; i < c; i++) {
    vct_Delete(lines[i]);
  }
  vct_Delete(self.lines);
}