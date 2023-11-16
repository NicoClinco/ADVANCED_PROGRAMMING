#!/bin/bash

rm *.o
rm *.so

g++ -fPIC -c DATA_FRAME.cpp
g++ -shared *.o -o libDataFrame.so

