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
include src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/compiler_depend.make

# Include the progress variables for this target.
include src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/progress.make

# Include the compile flags for this target's objects.
include src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/flags.make

src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.o: src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/flags.make
src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.o: /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_dataframe/main_DATA_FRAME.cpp
src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.o: src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.o"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_dataframe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.o -MF CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.o.d -o CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.o -c /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_dataframe/main_DATA_FRAME.cpp

src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.i"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_dataframe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_dataframe/main_DATA_FRAME.cpp > CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.i

src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.s"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_dataframe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_dataframe/main_DATA_FRAME.cpp -o CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.s

# Object files for target main_DATA_FRAME
main_DATA_FRAME_OBJECTS = \
"CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.o"

# External object files for target main_DATA_FRAME
main_DATA_FRAME_EXTERNAL_OBJECTS =

/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_DATA_FRAME: src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/main_DATA_FRAME.cpp.o
/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_DATA_FRAME: src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/build.make
/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_DATA_FRAME: /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Libraries/libdata_frame.so
/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_DATA_FRAME: src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_DATA_FRAME"
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_dataframe && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_DATA_FRAME.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/build: /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Tests/main_DATA_FRAME
.PHONY : src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/build

src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/clean:
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_dataframe && $(CMAKE_COMMAND) -P CMakeFiles/main_DATA_FRAME.dir/cmake_clean.cmake
.PHONY : src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/clean

src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/depend:
	cd /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01 /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/test_dataframe /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_dataframe /home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/build/src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/test_dataframe/CMakeFiles/main_DATA_FRAME.dir/depend
