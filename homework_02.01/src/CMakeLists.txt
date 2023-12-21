cmake_minimum_required(VERSION 3.12)

# adding the two libraries:

set(GSLPATH "/home/nico/Desktop/PHD-COURSES/libraries/gsl" CACHE STRING "/path/to/gsl")
set(BOOSTPATH "/home/nico/Desktop/PHD-COURSES/libraries/Boost" CACHE STRING "/path/to/boost")


option(BUILD_LIB_DF "Build the statistics module" OFF)
option(BUILD_LIB_Q "Build the quadrature module" OFF)
option(BUILD_TEST_DF "Build test program for data-frame" OFF)
option(BUILD_TEST_Q "Build test program for quadrature" OFF)
option(BUILD_PYDIR_DF "Build test program for quadrature" OFF)

MESSAGE(STATUS "THE FOLLOWING OPTIONS ARE AVAILABLE:")
MESSAGE(STATUS "Specify BUILD_LIB_DF=ON for statistics module")
MESSAGE(STATUS "Specify BUILD_LIB_Q=ON for quadrature  module")
MESSAGE(STATUS "Specify BUILD_TEST_DF=ON for generating an executable that test the Statistics module")
MESSAGE(STATUS "Specify BUILD_TEST_Q=ON for generating an executable that test the Quadrature module")


if(BUILD_LIB_DF)
	add_subdirectory(data_frame_module)
endif(BUILD_LIB_DF)

if(BUILD_LIB_Q)
	add_subdirectory(quad_module)
endif(BUILD_LIB_Q)

if(BUILD_TEST_DF)
	add_subdirectory(data_frame_module)
	add_subdirectory(test_dataframe)
endif(BUILD_TEST_DF)

if(BUILD_TEST_Q)
	add_subdirectory(quad_module)
	add_subdirectory(test_quadrature)
endif(BUILD_TEST_Q)

if(BUILD_PYDIR_DF)
	add_subdirectory(data_frame_module)
	add_subdirectory(pyDir)
endif(BUILD_PYDIR_DF)
