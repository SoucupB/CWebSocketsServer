#pragma once
#include "NetworkBuffer.h"
#include "Structs.h"

NetBufferHelperWriter ntb_Writer_Create(size_t maxBSize);
void ntb_Writer_Delete(NetBufferHelperWriter self);
void ntb_Write_PushF32(NetBufferHelperWriter self, float number);
void ntb_Write_PushBuffer(NetBufferHelperWriter self, void *buffer, size_t size);
void ntb_Write_PushF64(NetBufferHelperWriter self, double number);
void ntb_Write_PushINT8(NetBufferHelperWriter self, int8_t number);
void ntb_Write_PushINT16(NetBufferHelperWriter self, int16_t number);
void ntb_Write_PushINT32(NetBufferHelperWriter self, int32_t number);
void ntb_Write_PushINT64(NetBufferHelperWriter self, int64_t number);
void ntb_Write_PushString(NetBufferHelperWriter self, HttpString str);
void *ntb_Write_Buffer(NetBufferHelperWriter self);

NetBufferHelperReader ntb_Reader_Create(char *buffer, size_t size);
int64_t ntp_Reader_INT64(PNetBufferHelperReader self);
int32_t ntp_Reader_INT32(PNetBufferHelperReader self);
int16_t ntp_Reader_INT16(PNetBufferHelperReader self);
int8_t ntp_Reader_INT8(PNetBufferHelperReader self);
float ntp_Reader_FLOAT32(PNetBufferHelperReader self);
double ntp_Reader_FLOAT64(PNetBufferHelperReader self);
HttpString ntp_Reader_String(PNetBufferHelperReader self);
uint8_t ntp_Reader_IsComplete(PNetBufferHelperReader self);