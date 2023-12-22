cmake_minimum_required(VERSION 3.12)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TOP_TREE}/pyDirLib)

#headers for data_frame and quadrature:
set(INCLUDE_DIR_HPP ${TOP_TREE}/Headers)

#.so of dataframe and quadrature
set(LIB_DIR ${TOP_TREE}/Libraries)

set(PYBIND11_DIR pybind11)

add_subdirectory(${PYBIND11_DIR})
pybind11_add_module(dataFrameBind dataFrameBind.cpp)

#include header files and libraries from the top tree:
target_include_directories(dataFrameBind PUBLIC ${INCLUDE_DIR_HPP})
target_link_directories(dataFrameBind PUBLIC ${LIB_DIR})
target_link_libraries(dataFrameBind PUBLIC data_frame)

pybind11_add_module(quadBind quadBind.cpp)
target_include_directories(quadBind PUBLIC ${INCLUDE_DIR_HPP} PUBLIC ${GSLPATH}/include)
target_link_directories(quadBind PUBLIC ${LIB_DIR} PUBLIC ${GSLPATH}/lib)
target_link_libraries(quadBind PUBLIC quad_module gsl gslcblas)

