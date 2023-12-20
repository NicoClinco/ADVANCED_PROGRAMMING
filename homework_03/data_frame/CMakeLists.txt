cmake_minimum_required(VERSION 3.12)

project(data_frame_library VERSION 1.0
  DESCRIPTION "Statistics module revised"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic")

set(BOOST_INCLUDE_DIR ${BOOSTPATH}/include)

message(STATUS "Building the statistics module")

set(SRC_FILES data_frame.cpp)
set(HEADER_FILES data_frame.hpp)

add_library(dataframe SHARED ${SRC_FILES} ${HEADER_FILES})
target_include_directories(dataframe PUBLIC ${BOOST_INCLUDE_DIR})

install(TARGETS dataframe
  LIBRARY DESTINATION /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_03/libs
  PUBLIC_HEADER DESTINATION /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_03/libs)

install(FILES ${HEADER_FILES} DESTINATION /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_03/headers)

#add_subdirectory(pybind11-cmakedir)
#pybind11_add_module(example example.cpp)
