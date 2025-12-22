#pragma once
#include "Structs.h"
#include <stddef.h>
#include <stdint.h>
#include "Hsh.h"

size_t *test_Util_CreateBuffer(size_t size);
size_t test_Util_RandomElement();
void test_Util_TestEquivalency(size_t *buffed, size_t *realArray, size_t size);
void test_Util_TestStringEquivalency(char **buffed, Key *keys, size_t size);