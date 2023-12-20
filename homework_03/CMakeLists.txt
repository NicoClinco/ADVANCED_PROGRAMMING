cmake_minimum_required(VERSION 3.12)

project(homework03 VERSION 1.0
  DESCRIPTION "Scientific library implementation"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic")

set(GSLPATH "/home/nico-pc/Desktop/PHD-COURSES/libraries/gsl")
set(BOOSTPATH "/home/nico-pc/Desktop/PHD-COURSES/libraries/boost")

#library-statistics-module
add_subdirectory(data_frame)

#executable-statistics-module
add_subdirectory(apps)






#add_subdirectory(pybind11-cmakedir)
#pybind11_add_module(example example.cpp)
