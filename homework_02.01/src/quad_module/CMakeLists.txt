cmake_minimum_required(VERSION 3.12)

set(GSL_INCLUDE_DIR ${GSLPATH}/include)
set(GSL_LIB_DIR ${GSLPATH}/lib)


message(STATUS "Builing the library for the quadrature module...")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TOP_TREE}/Libraries)
set(SOURCE_FILES Quadrature.cpp)
set(HEADER_FILES Quadrature.hpp)

add_library(quad_module SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(quad_module PUBLIC ${GSL_INCLUDE_DIR})

target_link_directories(quad_module PUBLIC ${GSL_LIB_DIR})
target_link_libraries(quad_module gsl gslcblas)

message(STATUS "Quadrature module library builded")
