#!/bin/bash

gcc -Wall -O3 -ISources/ Sources/*.c Tests/socket_test.c -o TestBinaries/socket_test -lcmocka

if [ -z "$1" ]; then
  echo "Missing argument!"
  exit 1
fi

TestBinaries/$1