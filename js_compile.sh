#/bin/bash

npx esbuild JSConnector/Sources/EventWebSocket.mjs --bundle \
   --minify --outfile=JSConnector/build/bundle.node.min.js \
   --format=esm \
   --platform=node \
   --external:ws \
   --external:events

npx esbuild JSConnector/Sources/EventWebSocket.mjs --bundle \
   --minify --outfile=JSConnector/build/bundle.browser.min.js \
   --format=esm \
   --platform=browser