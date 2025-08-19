#!/bin/bash

gcc -Wall -O3 -ISources/ Sources/*.c Tests/socket_test.c -o TestBinaries/socket_test -lcmocka

if [ -z "$1" ]; then
  echo "Missing argument!"
  exit 1
fi

valgrind --error-exitcode=1 --quiet -s --leak-check=full TestBinaries/$1
RESULT=$?

if [ $RESULT -eq 0 ]; then
  echo "✅ No memory errors detected"
else
  echo "❌ Memory errors detected!"
  echo "---- Valgrind Report ----"
  cat /tmp/valgrind_out
  echo "-------------------------"
fi