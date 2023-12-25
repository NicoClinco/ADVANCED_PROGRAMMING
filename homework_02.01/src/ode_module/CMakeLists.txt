cmake_minimum_required(VERSION 3.12)

set(EIGEN_INCLUDE_DIR ${EIGENPATH}/)

message(STATUS "Building the time-integration module")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TOP_TREE}/Libraries)
set(SOURCE_FILES ODE.cpp)
set(HEADER_FILES ODE.hpp)

add_library(ode_module SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(ode_module PUBLIC ${EIGEN_INCLUDE_DIR})

#target_link_directories(quad_module PUBLIC ${GSL_LIB_DIR})
#target_link_libraries(quad_module gsl gslcblas)

message(STATUS "Time-integration module builded")
