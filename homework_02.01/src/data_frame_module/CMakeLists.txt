cmake_minimum_required(VERSION 3.12)

set(BOOST_INCLUDE_DIR ${BOOSTPATH}/include)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TOP_TREE}/Libraries)
message(STATUS "Builing the library for the statistics module...")

set(SOURCE_FILES DATA_FRAME.cpp)
set(HEADER_FILES DATA_FRAME.hpp CSV_WRITER.hpp)

add_library(data_frame SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(data_frame PUBLIC ${BOOST_INCLUDE_DIR})

message(STATUS "Dataframe library builded")
