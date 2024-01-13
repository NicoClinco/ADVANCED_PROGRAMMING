cmake_minimum_required(VERSION 3.12)

set(EIGEN_INCLUDE_DIR ${EIGENPATH}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TOP_TREE}/Examples)

add_executable(main_ODE main_ODE.cpp)

#include directories for headers:
target_include_directories(main_ODE PUBLIC ${TOP_TREE}/Headers PUBLIC EIGEN_INCLUDE_DIR)
target_link_directories(main_ODE PUBLIC ${TOP_TREE}/Libraries)
target_link_libraries(main_ODE PUBLIC ode_module)


