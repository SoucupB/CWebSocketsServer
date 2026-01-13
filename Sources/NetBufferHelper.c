#include "NetBufferHelper.h"
#include <string.h>

NetBufferHelperWriter ntb_Writer_Create(size_t maxBSize) {
  NetBufferHelperWriter self;
  self.buff = tpd_Create(maxBSize);
  return self;
}

void ntb_Write_PushBuffer(NetBufferHelperWriter self, void *buffer, size_t size) {
  tpd_Push(self.buff, buffer, size);
}

void ntb_Write_PushF32(NetBufferHelperWriter self, float number) {
  tpd_Push(self.buff, &number, sizeof(float));
}

void ntb_Write_PushF64(NetBufferHelperWriter self, double number) {
  tpd_Push(self.buff, &number, sizeof(double));
}

void ntb_Write_PushINT8(NetBufferHelperWriter self, int8_t number) {
  tpd_Push(self.buff, &number, sizeof(int8_t));
}

void ntb_Write_PushINT16(NetBufferHelperWriter self, int16_t number) {
  tpd_Push(self.buff, &number, sizeof(int16_t));
}

void ntb_Write_PushINT32(NetBufferHelperWriter self, int32_t number) {
  tpd_Push(self.buff, &number, sizeof(int32_t));
}

void ntb_Write_PushINT64(NetBufferHelperWriter self, int64_t number) {
  tpd_Push(self.buff, &number, sizeof(int64_t));
}

size_t ntb_Write_Size(NetBufferHelperWriter self) {
  return tpd_Size(self.buff);
}

void ntb_Write_PushString(NetBufferHelperWriter self, HttpString str) {
  ntb_Write_PushINT64(self, str.sz);
  ntb_Write_PushBuffer(self, str.buffer, str.sz);
}

void *ntb_Write_Buffer(NetBufferHelperWriter self) {
  return tpd_StartingBuffer(self.buff);
}

void ntb_Writer_Delete(NetBufferHelperWriter self) {
  tpd_Delete(self.buff);
}

NetBufferHelperReader ntb_Reader_Create(char *buffer, size_t size) {
  NetBufferHelperReader self;
  self.bufferSize = size;
  self.currentBuffer = buffer;
  self.startingBuffer = buffer;
  self.readCount = 0;
  return self;
}

int64_t ntb_Reader_INT64(PNetBufferHelperReader self) {
  if(self->readCount + sizeof(int64_t) > self->bufferSize) {
    return 0;
  }
  int64_t response;
  memcpy(&response, self->currentBuffer, sizeof(int64_t));
  self->currentBuffer += sizeof(int64_t);
  self->readCount += sizeof(int64_t);
  return response;
}

int32_t ntb_Reader_INT32(PNetBufferHelperReader self) {
  if(self->readCount + sizeof(int32_t) > self->bufferSize) {
    return 0;
  }
  int32_t response;
  memcpy(&response, self->currentBuffer, sizeof(int32_t));
  self->currentBuffer += sizeof(int32_t);
  self->readCount += sizeof(int32_t);
  return response;
}

int16_t ntb_Reader_INT16(PNetBufferHelperReader self) {
  if(self->readCount + sizeof(int16_t) > self->bufferSize) {
    return 0;
  }
  int16_t response;
  memcpy(&response, self->currentBuffer, sizeof(int16_t));
  self->currentBuffer += sizeof(int16_t);
  self->readCount += sizeof(int16_t);
  return response;
}

int8_t ntb_Reader_INT8(PNetBufferHelperReader self) {
  if(self->readCount + sizeof(int8_t) > self->bufferSize) {
    return 0;
  }
  int8_t response = *(int8_t *)self->currentBuffer;
  self->currentBuffer += sizeof(int8_t);
  self->readCount += sizeof(int8_t);
  return response;
}

float ntb_Reader_FLOAT32(PNetBufferHelperReader self) {
  if(self->readCount + sizeof(float) > self->bufferSize) {
    return 0.0f;
  }
  float response;
  memcpy(&response, self->currentBuffer, sizeof(float));
  self->currentBuffer += sizeof(float);
  self->readCount += sizeof(float);
  return response;
}

double ntb_Reader_FLOAT64(PNetBufferHelperReader self) {
  if(self->readCount + sizeof(double) > self->bufferSize) {
    return 0.0;
  }
  double response;
  memcpy(&response, self->currentBuffer, sizeof(double));
  self->currentBuffer += sizeof(double);
  self->readCount += sizeof(double);
  return response;
}

HttpString ntb_Reader_String(PNetBufferHelperReader self) {
  HttpString response = {
    .buffer = NULL,
    .sz = 0
  };
  size_t strSize = ntb_Reader_INT64(self);
  if(strSize + self->readCount > self->bufferSize) {
    return response;
  }
  char *startingBuffer = self->currentBuffer;
  self->readCount += strSize;
  response.sz = strSize;
  response.buffer = startingBuffer;
  return response;
}

uint8_t ntb_Reader_IsComplete(PNetBufferHelperReader self) {
  return self->currentBuffer == self->startingBuffer + self->bufferSize;
}

