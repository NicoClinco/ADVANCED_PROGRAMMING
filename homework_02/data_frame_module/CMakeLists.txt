cmake_minimum_required(VERSION 3.18)
project(data_frame_lib VERSION 1.0.0 DESCRIPTION "Data frame module" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic")

set(BOOST_INCLUDE_DIR "/home/nico/Desktop/PHD-COURSES/libraries/Boost/include")

message(STATUS "Including the boost library: ${BOOST_INCLUDE_DIR}")

set(SOURCE_FILES DATA_FRAME.cpp)
set(HEADER_FILES DATA_FRAME.hpp)

add_library(data_frame SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(data_frame PUBLIC ${BOOST_INCLUDE_DIR})

install(TARGETS data_frame
	LIBRARY DESTINATION /home/nico/Desktop/TEMPORARY/dataframe/lib
	PUBLIC_HEADER DESTINATION /home/nico/Desktop/TEMPORARY/dataframe/include)
	
install(FILES ${HEADER_FILES} DESTINATION /home/nico/Desktop/TEMPORARY/dataframe/include)
