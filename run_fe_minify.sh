#!/bin/bash
set -e

# ./run_fe_build.sh
./_build_fe_minify.sh NetworkReadBuffer
./_build_fe_minify.sh NetworkWriteBuffer
# cd JSHelpers && (npx esbuild src/NetworkReadBuffer.ts --outfile=minified/NetworkReadBuffer.min.js --bundle --minify || true) && cd ../
# cd JSHelpers && (npx esbuild src/NetworkWriteBuffer.ts --outfile=minified/NetworkWriteBuffer.min.js --bundle --minify || true) && cd ../