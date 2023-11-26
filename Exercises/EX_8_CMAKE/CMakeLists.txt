cmake_minimum_required(VERSION 3.16)

project(ex07_1 VERSION 1.0 DESCRIPTION "ex 1 session 07" LANGUAGES CXX)

set(gslDIR "/home/nico/Desktop/PHD-COURSES/gls" CACHE STRING "path/to/lgsl")

add_executable(ex1 ex1.cpp)
target_include_directories(ex1 PUBLIC ${gslDIR}/include)
target_link_directories(ex1 PUBLIC ${gslDIR}/lib)
target_link_libraries(ex1 gsl gslcblas)
