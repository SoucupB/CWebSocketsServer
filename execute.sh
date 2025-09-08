#!/bin/bash

# gcc -Wall -O3 -ISources/ Main/main.c Sources/*.c -o Binaries/Server -lcrypto
./prepare_sources.sh
# gcc -Wall -O9 -Ibin/ bin/ServerSource.c Main/main.c -o Binaries/Server -lcrypto
gcc -Wall -O9 -Ibin/ bin/ServerSource.c Main/EventMain.c -o Binaries/Server -lcrypto
# valgrind --error-exitcode=1 --track-fds=yes --quiet -s --leak-check=full Binaries/Server
Binaries/Server