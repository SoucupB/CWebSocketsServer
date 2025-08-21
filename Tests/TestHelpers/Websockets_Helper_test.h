#pragma once
#include "WebSocketsTranslator.h"
#include <stddef.h>

WebSocketObject test_Util_Transform(char *buffer, size_t sz);
void test_Util_Delete(WebSocketObject obj);
char *test_Util_RepeatMessage(char *msg, size_t sz, size_t count);