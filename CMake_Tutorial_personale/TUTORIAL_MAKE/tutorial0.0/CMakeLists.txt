cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Tutorial0 VERSION 1.0)
configure_file(TutorialConfig.h.in TutorialConfig.h)
#target_include_directories(Tutorial0 PUBLIC "${PROJECT_BINARY_DIR}")
add_executable(Tutorial0 Tutorial0.cxx)
target_include_directories(Tutorial0 PUBLIC "${PROJECT_BINARY_DIR}")
