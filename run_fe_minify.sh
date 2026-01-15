#!/bin/bash
set -e

# ./run_fe_build.sh
cd JSHelpers && (npx esbuild src/NetworkReadBuffer.ts --outfile=minified/NetworkReadBuffer.min.js --bundle --minify || true) && cd ../
cd JSHelpers && (npx esbuild src/NetworkWriteBuffer.ts --outfile=minified/NetworkWriteBuffer.min.js --bundle --minify || true) && cd ../