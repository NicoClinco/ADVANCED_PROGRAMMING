add_library(
        plotLib
	src/say-hello/myLib.hpp
        src/say-hello/myLib.cpp
)

add_library(
	plotLib2
	src/say-kitem/SecLib.hpp
	src/say-kitem/SecLib.cpp
)

target_include_directories(plotLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(plotLib2 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")


