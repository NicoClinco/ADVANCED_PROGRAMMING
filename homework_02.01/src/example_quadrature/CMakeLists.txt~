cmake_minimum_required(VERSION 3.12)

set(GSL_INCLUDE_DIR ${GSLPATH}/include)
set(GSL_LIB_DIR ${GSLPATH}/lib)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TOP_TREE}/Tests)

add_executable(main_NUMERICAL_INTEGRATION main_NUMERICAL_INTEGRATION.cpp)
#include directories for headers:
target_include_directories(main_NUMERICAL_INTEGRATION PUBLIC ${TOP_TREE}/Headers PUBLIC GSL_INCLUDE_DIR)
#link the following directories:
target_link_directories(main_NUMERICAL_INTEGRATION PUBLIC ${TOP_TREE}/Libraries PUBLIC GSL_LIB_DIR)
#link the specific libraries:
target_link_libraries(main_NUMERICAL_INTEGRATION PUBLIC quad_module PUBLIC gsl PUBLIC gslcblas)


