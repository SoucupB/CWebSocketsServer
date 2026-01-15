#!/bin/bash

cd JSHelpers && (npx esbuild src/$1.ts --bundle --minify --outfile=minified/$1.min.js --platform=browser --global-name=$1 || true) && cd ../