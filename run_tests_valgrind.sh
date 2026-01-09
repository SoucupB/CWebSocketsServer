#!/bin/bash
if [ -z "$1" ]; then
  echo "Missing argument!"
  exit 1
fi

./_compile_specs.sh $1


valgrind --error-exitcode=1 --track-fds=yes --quiet -s --leak-check=full TestBinaries/$1
RESULT=$?

if [ $RESULT -eq 0 ]; then
  echo "✅ No memory errors detected"
else
  echo "❌ Memory errors detected!"
  echo "---- Valgrind Report ----"
  exit 1
fi

exit 0