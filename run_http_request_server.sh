#!/bin/bash

./prepare_sources.sh
gcc -Wall -O9 -Ibin/ bin/ServerSource.c Main/RequestMain.c -o Binaries/RequestMain -lcrypto
Binaries/RequestMain