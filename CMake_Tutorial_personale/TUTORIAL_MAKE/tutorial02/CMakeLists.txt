cmake_minimum_required(VERSION 3.16)
project(Tutorial VERSION 1.0.0)


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


