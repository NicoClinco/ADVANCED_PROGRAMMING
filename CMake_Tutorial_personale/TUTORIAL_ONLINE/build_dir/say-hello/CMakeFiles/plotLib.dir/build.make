# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir

# Include any dependencies generated for this target.
include say-hello/CMakeFiles/plotLib.dir/depend.make

# Include the progress variables for this target.
include say-hello/CMakeFiles/plotLib.dir/progress.make

# Include the compile flags for this target's objects.
include say-hello/CMakeFiles/plotLib.dir/flags.make

say-hello/CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.o: say-hello/CMakeFiles/plotLib.dir/flags.make
say-hello/CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.o: ../say-hello/src/say-hello/myLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object say-hello/CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.o"
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/say-hello && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.o -c /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/say-hello/src/say-hello/myLib.cpp

say-hello/CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.i"
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/say-hello && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/say-hello/src/say-hello/myLib.cpp > CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.i

say-hello/CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.s"
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/say-hello && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/say-hello/src/say-hello/myLib.cpp -o CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.s

# Object files for target plotLib
plotLib_OBJECTS = \
"CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.o"

# External object files for target plotLib
plotLib_EXTERNAL_OBJECTS =

say-hello/libplotLib.a: say-hello/CMakeFiles/plotLib.dir/src/say-hello/myLib.cpp.o
say-hello/libplotLib.a: say-hello/CMakeFiles/plotLib.dir/build.make
say-hello/libplotLib.a: say-hello/CMakeFiles/plotLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libplotLib.a"
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/say-hello && $(CMAKE_COMMAND) -P CMakeFiles/plotLib.dir/cmake_clean_target.cmake
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/say-hello && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plotLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
say-hello/CMakeFiles/plotLib.dir/build: say-hello/libplotLib.a

.PHONY : say-hello/CMakeFiles/plotLib.dir/build

say-hello/CMakeFiles/plotLib.dir/clean:
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/say-hello && $(CMAKE_COMMAND) -P CMakeFiles/plotLib.dir/cmake_clean.cmake
.PHONY : say-hello/CMakeFiles/plotLib.dir/clean

say-hello/CMakeFiles/plotLib.dir/depend:
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/say-hello /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/say-hello /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_ONLINE/build_dir/say-hello/CMakeFiles/plotLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : say-hello/CMakeFiles/plotLib.dir/depend

