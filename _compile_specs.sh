#!/bin/bash

gcc -Wall -O3 -ISources/ -ITests/TestHelpers/ Sources/*.c Tests/TestHelpers/*.c Tests/Socket_test.c -o TestBinaries/Socket_test -lcmocka