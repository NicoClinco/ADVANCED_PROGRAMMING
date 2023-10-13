cmake_minimum_required(VERSION 3.16)
project(MyFirstProgram VERSION 1.0.0)

add_library(
	plotLib
	myLib.hpp
	myLib.cpp
)

add_executable(HelloExecutable simpleProgram.cpp)

target_link_libraries(HelloExecutable PRIVATE plotLib)

