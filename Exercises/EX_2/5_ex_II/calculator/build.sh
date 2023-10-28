#!/bin/bash

current_dir="./build/"
cd $current_dir

g++ -E ../src/main.cpp  -o ../src/main_preprocessed.cpp
g++ -E ../src/calculator.cpp -o ../src/calculator_preprocessed.cpp

g++ -c ../src/main_preprocessed.cpp -o main.o
g++ -c ../src/calculator_preprocessed.cpp -o calculator.o

g++ calculator.o main.o -o my_program_exe
cd ..
