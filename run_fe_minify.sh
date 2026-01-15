#!/bin/bash
set -e

./_build_fe_minify.sh NetworkReadBuffer
./_build_fe_minify.sh NetworkWriteBuffer
./_build_fe_minify.sh Network