cmake_minimum_required(VERSION 3.12)

project(homework2 VERSION 1.0
	DESCRIPTION "HOMEWORK03"
		LANGUAGES CXX)

# Set the C++ version:
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic")
#set(CMAKE_BUILD_TYPE Debug)


set(TOP_TREE ${PROJECT_SOURCE_DIR})

add_subdirectory(src)

