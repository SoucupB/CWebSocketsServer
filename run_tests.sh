#!/bin/bash

./_compile_specs.sh

if [ -z "$1" ]; then
  echo "Missing argument!"
  exit 1
fi

TestBinaries/$1

RESULT=$?

if [ $RESULT -eq 0 ]; then
  echo "✅ Tests passed successfully"
else
  echo "❌ Tests failed!"
fi