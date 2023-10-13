cmake_minimum_required(VERSION 3.16)
project(Tutorial VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add a library for compiler features 
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

configure_file(TutorialConfig.h.in TutorialConfig.h)


option(MyMathLib "Set the library on?" ON)


message(STATUS "Selected the following option :${MyMathLib}")

set(EXTRA_LIBS SquareRootLib)
set(EXTRA_LIBS1 SquareLib)

if( MyMathLib)
  add_definitions(-DUSE_LIBS_EXE=${MyMathLib})
  add_subdirectory(MATHFUNCTIONS)
endif()

message(STATUS "THE LIBS I WANT IS : ${EXTRA_LIBS}")
message(STATUS "THE SECOND LIB IS : ${EXTRA_LIBS1}")
message(STATUS "${EXTRA_INCLUDE}")
add_subdirectory(Executable)


