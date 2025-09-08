#/bin/bash

npx esbuild JSConnector/Sources/EventWebSocket.mjs --bundle \
   --minify --outfile=JSConnector/build/EventWebSocket.js \
   --format=esm \
   --platform=node \
   --external:ws \
   --external:events

npx esbuild JSConnector/Sources/EventWebSocket.mjs --bundle \
   --minify --outfile=JSConnector/bundle/event_web_socket.min.js \
   --platform=browser \
   --format=iife \
   --global-name=JSConnector