# CMake generated Testfile for 
# Source directory: /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05
# Build directory: /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test25 "/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/Tutorial" "25")
set_tests_properties(test25 PROPERTIES  _BACKTRACE_TRIPLES "/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/CMakeLists.txt;46;add_test;/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/CMakeLists.txt;0;")
add_test(usageTest "/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/Tutorial")
set_tests_properties(usageTest PROPERTIES  PASS_REGULAR_EXPRESSION "Usage:.*number" _BACKTRACE_TRIPLES "/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/CMakeLists.txt;48;add_test;/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/CMakeLists.txt;0;")
add_test(SquareRootCheck "/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/Tutorial" "9")
set_tests_properties(SquareRootCheck PROPERTIES  PASS_REGULAR_EXPRESSION "9 is 3" _BACKTRACE_TRIPLES "/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/CMakeLists.txt;51;add_test;/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/CMakeLists.txt;0;")
subdirs("MathFunctions")
