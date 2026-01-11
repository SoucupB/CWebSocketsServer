#include "NetBufferHelper.h"

NetBufferHelper ntb_Create(size_t maxBSize) {
  NetBufferHelper self;
  self.buff = tpd_Create(maxBSize);
  return self;
}

void ntb_PushBuffer(NetBufferHelper self, void *buffer, size_t size) {
  tpd_Push(self.buff, buffer, size);
}

void ntb_PushF32(NetBufferHelper self, float number) {
  tpd_Push(self.buff, &number, sizeof(float));
}

void ntb_PushF64(NetBufferHelper self, double number) {
  tpd_Push(self.buff, &number, sizeof(double));
}

void ntb_PushINT8(NetBufferHelper self, int8_t number) {
  tpd_Push(self.buff, &number, sizeof(int8_t));
}

void ntb_PushINT16(NetBufferHelper self, int16_t number) {
  tpd_Push(self.buff, &number, sizeof(int16_t));
}

void ntb_PushINT32(NetBufferHelper self, int32_t number) {
  tpd_Push(self.buff, &number, sizeof(int32_t));
}

void ntb_PushINT64(NetBufferHelper self, int64_t number) {
  tpd_Push(self.buff, &number, sizeof(int64_t));
}

void ntb_PushString(NetBufferHelper self, HttpString str) {
  ntb_PushINT64(self, str.sz);
  ntb_PushBuffer(self, str.buffer, str.sz);
}

void ntb_Delete(NetBufferHelper self) {
  tpd_Delete(self.buff);
}