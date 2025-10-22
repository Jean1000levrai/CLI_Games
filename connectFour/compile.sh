#!/bin/bash

set -e

mkdir -p build

SRC_FILES=$(find src -name "*.c")

CFLAGS="-I./include"

gcc -g $CFLAGS $SRC_FILES -o build/main

./build/main