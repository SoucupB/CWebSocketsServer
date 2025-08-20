#!/bin/bash

./_compile_specs.sh

if [ -z "$1" ]; then
  echo "Missing argument!"
  exit 1
fi

valgrind --error-exitcode=1 --track-fds=yes --quiet -s --leak-check=full TestBinaries/$1
RESULT=$?

if [ $RESULT -eq 0 ]; then
  echo "✅ No memory errors detected"
else
  echo "❌ Memory errors detected!"
  echo "---- Valgrind Report ----"
  cat /tmp/valgrind_out
  echo "-------------------------"
fi