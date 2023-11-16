#!/bin/bash

rm *.o

pathTolib="./data_frame_module/"

g++ -I$pathTolib -c main.cpp
g++ main.o -L$pathTolib -lDataFrame -o main
