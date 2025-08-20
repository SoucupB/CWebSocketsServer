#!/bin/bash

gcc -Wall -O3 -ISources/ -ITests/TestHelpers/ Sources/*.c Tests/TestHelpers/*.c Tests/$1.c -o TestBinaries/$1 -lcmocka