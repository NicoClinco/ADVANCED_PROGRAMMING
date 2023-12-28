cmake_minimum_required(VERSION 3.12)

# adding the two libraries:

set(GSLPATH "/home/nico/Desktop/PHD-COURSES/libraries/gsl" CACHE STRING "/path/to/gsl")
set(BOOSTPATH "/home/nico/Desktop/PHD-COURSES/libraries/Boost" CACHE STRING "/path/to/boost")
set(EIGENPATH "/home/nico/Desktop/PHD-COURSES/libraries/eigen/include/eigen3" CACHE STRING "/path/to/eigen")


option(BUILD_LIB_STATISTICS "Build the statistics module" OFF)
option(BUILD_LIB_QUAD "Build the quadrature module" OFF)
option(BUILD_LIB_ODE "Build the ODE integration module" OFF)
option(BUILD_TEST_STATISTICS "Test program for data-frame" OFF)
option(BUILD_TEST_QUAD "Test program for quadrature" OFF)
option(BUILD_TEST_ODE "Test program for time-integration" OFF)

option(BUILD_PYDIR_DF "Build Python library for statistics" OFF)
option(BUILD_PYDIR_QUAD "Build Python library for quadrature" OFF)

MESSAGE(STATUS "THE FOLLOWING OPTIONS ARE AVAILABLE:")
MESSAGE(STATUS "Specify BUILD_LIB_STATISTICS=ON for statistics module")
MESSAGE(STATUS "Specify BUILD_LIB_QUAD=ON for quadrature module")
MESSAGE(STATUS "Specify BUILD_LIB_ODE=ON for ODE module")
MESSAGE(STATUS "Specify BUILD_TEST_STATISTICS=ON for generating an executable that test the Statistics module")
MESSAGE(STATUS "Specify BUILD_TEST_QUAD=ON for generating an executable that test the Quadrature module")
MESSAGE(STATUS "Specify BUILD_TEST_ODE=ON for generating an executable that test the time-integration module")


if(BUILD_LIB_STATISTICS)
	add_subdirectory(data_frame_module)
endif(BUILD_LIB_STATISTICS)

if(BUILD_LIB_QUAD)
	add_subdirectory(quad_module)
endif(BUILD_LIB_QUAD)

if(BUILD_LIB_ODE)
	add_subdirectory(ode_module)
endif(BUILD_LIB_ODE)

if(BUILD_TEST_STATISTICS)
	add_subdirectory(data_frame_module)
	add_subdirectory(test_dataframe)
endif(BUILD_TEST_STATISTICS)

if(BUILD_TEST_QUAD)
	add_subdirectory(quad_module)
	add_subdirectory(test_quadrature)
endif(BUILD_TEST_QUAD)

if(BUILD_TEST_ODE)
	add_subdirectory(ode_module)
	add_subdirectory(test_ode)
endif(BUILD_TEST_ODE)

if(BUILD_PYDIR_DF)
	add_subdirectory(data_frame_module)
	add_subdirectory(pyDirDF)
endif(BUILD_PYDIR_DF)

if(BUILD_PYDIR_QUAD)
	add_subdirectory(quad_module)
	add_subdirectory(pyDirQuad)
endif(BUILD_PYDIR_QUAD)
