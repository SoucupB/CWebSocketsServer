#pragma once
#include "Structs.h"
#include <stdint.h>
#include "SocketClient.h"
#include "SocketServer.h"
#include <string.h>
#include <stdio.h>

HttpString json_Helper_Add(char *buffer);
JsonElement json_Helper_Integer(int64_t element);