#!/bin/bash

gcc -Wall -O3 -ISources/ Main/main.c Sources/*.c -o Binaries/Server -lcrypto
Binaries/Server