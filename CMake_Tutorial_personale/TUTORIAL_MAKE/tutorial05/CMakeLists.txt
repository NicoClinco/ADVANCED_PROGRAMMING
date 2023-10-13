cmake_minimum_required(VERSION 3.16)

# set the project name and version
project(Tutorial VERSION 1.0)

include(CTest)

# specify the C++ standard
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
#add_subdirectory(MathFunctions)

# add the executable
add_executable(Tutorial tutorial.cxx)
add_subdirectory(MathFunctions)

target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

enable_testing()
add_test(NAME test25 COMMAND Tutorial 25 )

add_test(NAME usageTest COMMAND Tutorial )
set_tests_properties(usageTest PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")

add_test(NAME SquareRootCheck COMMAND Tutorial 9)
set_tests_properties(SquareRootCheck PROPERTIES PASS_REGULAR_EXPRESSION "9 is 3")



#[[
function(do_test testName number sqrtnumber)
	message(STATUS "testName: ${${testName}}  and number :${${number}}, and sqrNumber ${${sqrtnumber}}")
	add_test(NAME ${${testName}} COMMAND Tutorial ${${number}})
	set_tests_properties(${${testName}} PROPERTIES PASS_REGULAR_EXPRESSION "${${number}} is ${${sqrtnumber}}")
endfunction()

set(num16 16)
set(sqr16 4)
set(testName16 "testName16")

do_test(testName16 num16 sqr16)
]]



