# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/duwenqin123/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/duwenqin123/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/duwenqin123/CLionProjects/miniftpd27

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/miniftpd27.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/miniftpd27.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/miniftpd27.dir/flags.make

CMakeFiles/miniftpd27.dir/main.c.o: CMakeFiles/miniftpd27.dir/flags.make
CMakeFiles/miniftpd27.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/miniftpd27.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd27.dir/main.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/main.c

CMakeFiles/miniftpd27.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd27.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/main.c > CMakeFiles/miniftpd27.dir/main.c.i

CMakeFiles/miniftpd27.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd27.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/main.c -o CMakeFiles/miniftpd27.dir/main.c.s

CMakeFiles/miniftpd27.dir/main.c.o.requires:

.PHONY : CMakeFiles/miniftpd27.dir/main.c.o.requires

CMakeFiles/miniftpd27.dir/main.c.o.provides: CMakeFiles/miniftpd27.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd27.dir/build.make CMakeFiles/miniftpd27.dir/main.c.o.provides.build
.PHONY : CMakeFiles/miniftpd27.dir/main.c.o.provides

CMakeFiles/miniftpd27.dir/main.c.o.provides.build: CMakeFiles/miniftpd27.dir/main.c.o


# Object files for target miniftpd27
miniftpd27_OBJECTS = \
"CMakeFiles/miniftpd27.dir/main.c.o"

# External object files for target miniftpd27
miniftpd27_EXTERNAL_OBJECTS =

miniftpd27: CMakeFiles/miniftpd27.dir/main.c.o
miniftpd27: CMakeFiles/miniftpd27.dir/build.make
miniftpd27: CMakeFiles/miniftpd27.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable miniftpd27"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/miniftpd27.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/miniftpd27.dir/build: miniftpd27

.PHONY : CMakeFiles/miniftpd27.dir/build

CMakeFiles/miniftpd27.dir/requires: CMakeFiles/miniftpd27.dir/main.c.o.requires

.PHONY : CMakeFiles/miniftpd27.dir/requires

CMakeFiles/miniftpd27.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/miniftpd27.dir/cmake_clean.cmake
.PHONY : CMakeFiles/miniftpd27.dir/clean

CMakeFiles/miniftpd27.dir/depend:
	cd /home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/duwenqin123/CLionProjects/miniftpd27 /home/duwenqin123/CLionProjects/miniftpd27 /home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug /home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug /home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles/miniftpd27.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/miniftpd27.dir/depend

