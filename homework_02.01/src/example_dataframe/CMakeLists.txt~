cmake_minimum_required(VERSION 3.12)

set(BOOST_INCLUDE_DIR ${BOOSTPATH}/include)
set(BOOST_LIB_DIR ${BOOSTPATH}/lib)

#Set the executable in the Tests directory:
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TOP_TREE}/Tests)
add_executable(main_DATA_FRAME main_DATA_FRAME.cpp)
#include directories for headers:
target_include_directories(main_DATA_FRAME PUBLIC ${TOP_TREE}/Headers PUBLIC BOOST_INCLUDE_DIR)
#link the following directories:
target_link_directories(main_DATA_FRAME PUBLIC ${TOP_TREE}/Libraries public BOOST_LIB_DIR)
#link the specific libraries:
target_link_libraries(main_DATA_FRAME PUBLIC data_frame PUBLIC boost_program_options)

