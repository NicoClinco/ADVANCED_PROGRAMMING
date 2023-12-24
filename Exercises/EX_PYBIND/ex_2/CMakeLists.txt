cmake_minimum_required(VERSION 3.2)
project(newton_solver)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

#NOTE: pybind must be installed with these commands:
find_package(pybind11 REQUIRED)
include_directories(SYSTEM ${pybind11_INCLUDE_DIRS})

pybind11_add_module(newton_py newton.cpp newton_py.cpp)


