#!/bin/bash
set -e
HDR_DIR="bin"
KEEP=("SocketServer.h" "SocketClient.h" "Structs.h" "EventServer.h" "WebSocketServer.h")
KEEP_PATTERN=$(printf "|%s" "${KEEP[@]}")
KEEP_PATTERN=${KEEP_PATTERN:1}
for f in "$HDR_DIR"/*.h; do
  [ -f "$f" ] || continue
  base=$(basename "$f")
  if ! echo "$base" | grep -Eq "^($KEEP_PATTERN)$"; then
    echo "Removing $f"
    rm "$f"
  fi
done