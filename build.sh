#!/bin/bash

SOURCE_DIR="src"
BUILD_DIR="build"
PROGRAM_NAME="i3wk"

mkdir -p $BUILD_DIR
gcc $SOURCE_DIR/Main.c -o $BUILD_DIR/$PROGRAM_NAME
