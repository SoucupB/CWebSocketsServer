#!/bin/bash
set -e
SRC_DIR="Sources"
BIN_DIR="bin"
OUT_FILE="$BIN_DIR/svv.c"
mkdir -p "$BIN_DIR"
: > "$OUT_FILE"
find "$SRC_DIR" -type f -name "*.c" | sort | while read -r f; do
  cat "$f" >> "$OUT_FILE"
  echo "" >> "$OUT_FILE"
  echo "Added $f to combined.c"
done
echo "✅ All .c files combined into $OUT_FILE"
cp $SRC_DIR/*.h bin/
gcc -E -P $BIN_DIR/svv.c -o $BIN_DIR/server.c -O9 -lcrypto
./_remove_headers.sh
rm $BIN_DIR/svv.c
echo "✅ Copied header files into destination folder"
