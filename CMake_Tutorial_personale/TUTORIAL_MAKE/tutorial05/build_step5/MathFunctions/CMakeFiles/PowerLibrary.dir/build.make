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
CMAKE_SOURCE_DIR = /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5

# Include any dependencies generated for this target.
include MathFunctions/CMakeFiles/PowerLibrary.dir/depend.make

# Include the progress variables for this target.
include MathFunctions/CMakeFiles/PowerLibrary.dir/progress.make

# Include the compile flags for this target's objects.
include MathFunctions/CMakeFiles/PowerLibrary.dir/flags.make

MathFunctions/CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.o: MathFunctions/CMakeFiles/PowerLibrary.dir/flags.make
MathFunctions/CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.o: ../MathFunctions/MathLibraries/powerclass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MathFunctions/CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.o"
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/MathFunctions && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.o -c /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/MathFunctions/MathLibraries/powerclass.cpp

MathFunctions/CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.i"
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/MathFunctions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/MathFunctions/MathLibraries/powerclass.cpp > CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.i

MathFunctions/CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.s"
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/MathFunctions && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/MathFunctions/MathLibraries/powerclass.cpp -o CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.s

# Object files for target PowerLibrary
PowerLibrary_OBJECTS = \
"CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.o"

# External object files for target PowerLibrary
PowerLibrary_EXTERNAL_OBJECTS =

MathFunctions/libPowerLibrary.a: MathFunctions/CMakeFiles/PowerLibrary.dir/MathLibraries/powerclass.cpp.o
MathFunctions/libPowerLibrary.a: MathFunctions/CMakeFiles/PowerLibrary.dir/build.make
MathFunctions/libPowerLibrary.a: MathFunctions/CMakeFiles/PowerLibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPowerLibrary.a"
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/MathFunctions && $(CMAKE_COMMAND) -P CMakeFiles/PowerLibrary.dir/cmake_clean_target.cmake
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/MathFunctions && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PowerLibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MathFunctions/CMakeFiles/PowerLibrary.dir/build: MathFunctions/libPowerLibrary.a

.PHONY : MathFunctions/CMakeFiles/PowerLibrary.dir/build

MathFunctions/CMakeFiles/PowerLibrary.dir/clean:
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/MathFunctions && $(CMAKE_COMMAND) -P CMakeFiles/PowerLibrary.dir/cmake_clean.cmake
.PHONY : MathFunctions/CMakeFiles/PowerLibrary.dir/clean

MathFunctions/CMakeFiles/PowerLibrary.dir/depend:
	cd /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05 /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/MathFunctions /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5 /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/MathFunctions /home/nicopc/Desktop/CMake_Tutorial/TUTORIAL_MAKE/tutorial05/build_step5/MathFunctions/CMakeFiles/PowerLibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : MathFunctions/CMakeFiles/PowerLibrary.dir/depend

