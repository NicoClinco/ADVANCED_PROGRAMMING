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
include src/pyDir/CMakeFiles/quadBind.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/pyDir/CMakeFiles/quadBind.dir/compiler_depend.make

# Include the progress variables for this target.
include src/pyDir/CMakeFiles/quadBind.dir/progress.make

# Include the compile flags for this target's objects.
include src/pyDir/CMakeFiles/quadBind.dir/flags.make

src/pyDir/CMakeFiles/quadBind.dir/quadBind.cpp.o: src/pyDir/CMakeFiles/quadBind.dir/flags.make
src/pyDir/CMakeFiles/quadBind.dir/quadBind.cpp.o: /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/pyDir/quadBind.cpp
src/pyDir/CMakeFiles/quadBind.dir/quadBind.cpp.o: src/pyDir/CMakeFiles/quadBind.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/pyDir/CMakeFiles/quadBind.dir/quadBind.cpp.o"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/pyDir && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pyDir/CMakeFiles/quadBind.dir/quadBind.cpp.o -MF CMakeFiles/quadBind.dir/quadBind.cpp.o.d -o CMakeFiles/quadBind.dir/quadBind.cpp.o -c /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/pyDir/quadBind.cpp

src/pyDir/CMakeFiles/quadBind.dir/quadBind.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quadBind.dir/quadBind.cpp.i"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/pyDir && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/pyDir/quadBind.cpp > CMakeFiles/quadBind.dir/quadBind.cpp.i

src/pyDir/CMakeFiles/quadBind.dir/quadBind.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quadBind.dir/quadBind.cpp.s"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/pyDir && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/pyDir/quadBind.cpp -o CMakeFiles/quadBind.dir/quadBind.cpp.s

# Object files for target quadBind
quadBind_OBJECTS = \
"CMakeFiles/quadBind.dir/quadBind.cpp.o"

# External object files for target quadBind
quadBind_EXTERNAL_OBJECTS =

/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/pyDirLib/quadBind.cpython-310-x86_64-linux-gnu.so: src/pyDir/CMakeFiles/quadBind.dir/quadBind.cpp.o
/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/pyDirLib/quadBind.cpython-310-x86_64-linux-gnu.so: src/pyDir/CMakeFiles/quadBind.dir/build.make
/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/pyDirLib/quadBind.cpython-310-x86_64-linux-gnu.so: src/pyDir/CMakeFiles/quadBind.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/pyDirLib/quadBind.cpython-310-x86_64-linux-gnu.so"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/pyDir && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quadBind.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pyDir/CMakeFiles/quadBind.dir/build: /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/pyDirLib/quadBind.cpython-310-x86_64-linux-gnu.so
.PHONY : src/pyDir/CMakeFiles/quadBind.dir/build

src/pyDir/CMakeFiles/quadBind.dir/clean:
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/pyDir && $(CMAKE_COMMAND) -P CMakeFiles/quadBind.dir/cmake_clean.cmake
.PHONY : src/pyDir/CMakeFiles/quadBind.dir/clean

src/pyDir/CMakeFiles/quadBind.dir/depend:
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01 /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/pyDir /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/pyDir /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/pyDir/CMakeFiles/quadBind.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/pyDir/CMakeFiles/quadBind.dir/depend

