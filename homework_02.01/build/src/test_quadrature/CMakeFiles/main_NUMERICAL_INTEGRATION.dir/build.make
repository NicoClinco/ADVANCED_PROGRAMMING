# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1361/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1361/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build

# Include any dependencies generated for this target.
include src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/compiler_depend.make

# Include the progress variables for this target.
include src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/progress.make

# Include the compile flags for this target's objects.
include src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/flags.make

src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.o: src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/flags.make
src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.o: /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_quadrature/main_NUMERICAL_INTEGRATION.cpp
src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.o: src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.o"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_quadrature && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.o -MF CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.o.d -o CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.o -c /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_quadrature/main_NUMERICAL_INTEGRATION.cpp

src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.i"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_quadrature && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_quadrature/main_NUMERICAL_INTEGRATION.cpp > CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.i

src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.s"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_quadrature && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_quadrature/main_NUMERICAL_INTEGRATION.cpp -o CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.s

# Object files for target main_NUMERICAL_INTEGRATION
main_NUMERICAL_INTEGRATION_OBJECTS = \
"CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.o"

# External object files for target main_NUMERICAL_INTEGRATION
main_NUMERICAL_INTEGRATION_EXTERNAL_OBJECTS =

/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_NUMERICAL_INTEGRATION: src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/main_NUMERICAL_INTEGRATION.cpp.o
/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_NUMERICAL_INTEGRATION: src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/build.make
/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_NUMERICAL_INTEGRATION: /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Libraries/libquad_module.so
/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_NUMERICAL_INTEGRATION: src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_NUMERICAL_INTEGRATION"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_quadrature && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_NUMERICAL_INTEGRATION.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/build: /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_NUMERICAL_INTEGRATION
.PHONY : src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/build

src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/clean:
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_quadrature && $(CMAKE_COMMAND) -P CMakeFiles/main_NUMERICAL_INTEGRATION.dir/cmake_clean.cmake
.PHONY : src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/clean

src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/depend:
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01 /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_quadrature /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_quadrature /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/test_quadrature/CMakeFiles/main_NUMERICAL_INTEGRATION.dir/depend
