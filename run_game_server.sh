#!/bin/bash

./prepare_sources.sh
gcc -Wall -O9 -Ibin/ bin/ServerSource.c Main/GameMain.c -o Binaries/GameMain -lcrypto
strip --strip-all Binaries/GameMain
Binaries/GameMain

# strip Binaries/HttpServer -- Remove compilation symbols