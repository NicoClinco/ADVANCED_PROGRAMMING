#!/bin/bash

rm *.o
rm *.so

g++ -std=c++17 -fPIC -c DATA_FRAME.cpp
g++ -std=c++17 -shared *.o -o libDataFrame.so

