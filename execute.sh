#!/bin/bash

# gcc -Wall -O3 -ISources/ Main/main.c Sources/*.c -o Binaries/Server -lcrypto
./prepare_sources.sh
gcc -Wall -O3 -Ibin/ bin/ServerSource.c Main/main.c -o Binaries/Server -lcrypto
Binaries/Server