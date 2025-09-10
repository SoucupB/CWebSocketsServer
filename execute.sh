#!/bin/bash

./prepare_sources.sh
# gcc -Wall -O9 -Ibin/ bin/ServerSource.c Main/main.c -o Binaries/Server -lcrypto
gcc -Wall -O9 -Ibin/ bin/ServerSource.c Main/EventMain.c -o Binaries/Server -lcrypto
Binaries/Server