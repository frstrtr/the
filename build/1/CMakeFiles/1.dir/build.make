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
CMAKE_SOURCE_DIR = /home/sl33n/repository/the

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sl33n/repository/the/build

# Include any dependencies generated for this target.
include 1/CMakeFiles/1.dir/depend.make

# Include the progress variables for this target.
include 1/CMakeFiles/1.dir/progress.make

# Include the compile flags for this target's objects.
include 1/CMakeFiles/1.dir/flags.make

1/CMakeFiles/1.dir/1.cpp.o: 1/CMakeFiles/1.dir/flags.make
1/CMakeFiles/1.dir/1.cpp.o: ../1/1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sl33n/repository/the/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 1/CMakeFiles/1.dir/1.cpp.o"
	cd /home/sl33n/repository/the/build/1 && /bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1.dir/1.cpp.o -c /home/sl33n/repository/the/1/1.cpp

1/CMakeFiles/1.dir/1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/1.cpp.i"
	cd /home/sl33n/repository/the/build/1 && /bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sl33n/repository/the/1/1.cpp > CMakeFiles/1.dir/1.cpp.i

1/CMakeFiles/1.dir/1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/1.cpp.s"
	cd /home/sl33n/repository/the/build/1 && /bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sl33n/repository/the/1/1.cpp -o CMakeFiles/1.dir/1.cpp.s

# Object files for target 1
1_OBJECTS = \
"CMakeFiles/1.dir/1.cpp.o"

# External object files for target 1
1_EXTERNAL_OBJECTS =

1/1: 1/CMakeFiles/1.dir/1.cpp.o
1/1: 1/CMakeFiles/1.dir/build.make
1/1: 1/CMakeFiles/1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sl33n/repository/the/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1"
	cd /home/sl33n/repository/the/build/1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
1/CMakeFiles/1.dir/build: 1/1

.PHONY : 1/CMakeFiles/1.dir/build

1/CMakeFiles/1.dir/clean:
	cd /home/sl33n/repository/the/build/1 && $(CMAKE_COMMAND) -P CMakeFiles/1.dir/cmake_clean.cmake
.PHONY : 1/CMakeFiles/1.dir/clean

1/CMakeFiles/1.dir/depend:
	cd /home/sl33n/repository/the/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sl33n/repository/the /home/sl33n/repository/the/1 /home/sl33n/repository/the/build /home/sl33n/repository/the/build/1 /home/sl33n/repository/the/build/1/CMakeFiles/1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 1/CMakeFiles/1.dir/depend

