#!/bin/bash

./prepare_sources.sh
gcc -Wall -O9 -Ibin/ bin/ServerSource.c Main/HttpMain.c -o Binaries/HttpServer -lcrypto
Binaries/HttpServer