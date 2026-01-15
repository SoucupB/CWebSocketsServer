#!/bin/bash

./run_fe_build.sh
cd JSHelpers && (npm run test || true) && cd ../