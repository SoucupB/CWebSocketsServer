#!/bin/bash

# cd JSHelpers && (npx esbuild src/$1.ts --bundle --minify --outfile=minified/$1.min.js --platform=browser --global-name=$1 || true) && cd ../
cd JSHelpers && (npx esbuild src/$1.ts --bundle --minify --format=iife --outfile=minified/$1.min.js --platform=browser || true) && cd ../