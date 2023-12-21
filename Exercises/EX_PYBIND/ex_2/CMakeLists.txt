cmake_minimum_required(VERSION 3.2)
project(newton_solver)

find_package(pybind11 REQUIRED)
include_directories(SYSTEM ${pybind11_INCLUDE_DIRS})

pybind11_add_module(newton_py newton.cpp newton_py.cpp)
