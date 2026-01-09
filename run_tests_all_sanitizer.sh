#!/bin/bash
set -e

for f in Tests/*_test.c; do
  [ -f "$f" ] || continue
  base="${f%.c}"
  base="${base#Tests/}"
  ./run_tests_sanitizer.sh "$base"
done