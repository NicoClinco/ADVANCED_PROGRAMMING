#!/bin/bash

rm *.o

pathTolib="./data_frame_module/"
CXXFLAGS="-std=c++17 -Wall -Wpedantic"

g++ $CXXFLAGS -I$pathTolib -c main.cpp
g++ $CXXFLAGS main.o -L$pathTolib -lDataFrame -o main
