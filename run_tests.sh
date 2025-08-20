#!/bin/bash

if [ -z "$1" ]; then
  echo "Missing argument!"
  exit 1
fi

./_compile_specs.sh $1

TestBinaries/$1

RESULT=$?

if [ $RESULT -eq 0 ]; then
  echo "✅ Tests passed successfully"
else
  echo "❌ Tests failed!"
  exit 1
fi

exit 0