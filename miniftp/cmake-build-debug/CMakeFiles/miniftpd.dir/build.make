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
include CMakeFiles/miniftpd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/miniftpd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/miniftpd.dir/flags.make

CMakeFiles/miniftpd.dir/ftpproto.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/ftpproto.c.o: ../ftpproto.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/miniftpd.dir/ftpproto.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/ftpproto.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/ftpproto.c

CMakeFiles/miniftpd.dir/ftpproto.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/ftpproto.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/ftpproto.c > CMakeFiles/miniftpd.dir/ftpproto.c.i

CMakeFiles/miniftpd.dir/ftpproto.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/ftpproto.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/ftpproto.c -o CMakeFiles/miniftpd.dir/ftpproto.c.s

CMakeFiles/miniftpd.dir/ftpproto.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/ftpproto.c.o.requires

CMakeFiles/miniftpd.dir/ftpproto.c.o.provides: CMakeFiles/miniftpd.dir/ftpproto.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/ftpproto.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/ftpproto.c.o.provides

CMakeFiles/miniftpd.dir/ftpproto.c.o.provides.build: CMakeFiles/miniftpd.dir/ftpproto.c.o


CMakeFiles/miniftpd.dir/hash.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/hash.c.o: ../hash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/miniftpd.dir/hash.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/hash.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/hash.c

CMakeFiles/miniftpd.dir/hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/hash.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/hash.c > CMakeFiles/miniftpd.dir/hash.c.i

CMakeFiles/miniftpd.dir/hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/hash.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/hash.c -o CMakeFiles/miniftpd.dir/hash.c.s

CMakeFiles/miniftpd.dir/hash.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/hash.c.o.requires

CMakeFiles/miniftpd.dir/hash.c.o.provides: CMakeFiles/miniftpd.dir/hash.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/hash.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/hash.c.o.provides

CMakeFiles/miniftpd.dir/hash.c.o.provides.build: CMakeFiles/miniftpd.dir/hash.c.o


CMakeFiles/miniftpd.dir/main.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/miniftpd.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/main.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/main.c

CMakeFiles/miniftpd.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/main.c > CMakeFiles/miniftpd.dir/main.c.i

CMakeFiles/miniftpd.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/main.c -o CMakeFiles/miniftpd.dir/main.c.s

CMakeFiles/miniftpd.dir/main.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/main.c.o.requires

CMakeFiles/miniftpd.dir/main.c.o.provides: CMakeFiles/miniftpd.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/main.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/main.c.o.provides

CMakeFiles/miniftpd.dir/main.c.o.provides.build: CMakeFiles/miniftpd.dir/main.c.o


CMakeFiles/miniftpd.dir/parseconf.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/parseconf.c.o: ../parseconf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/miniftpd.dir/parseconf.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/parseconf.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/parseconf.c

CMakeFiles/miniftpd.dir/parseconf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/parseconf.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/parseconf.c > CMakeFiles/miniftpd.dir/parseconf.c.i

CMakeFiles/miniftpd.dir/parseconf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/parseconf.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/parseconf.c -o CMakeFiles/miniftpd.dir/parseconf.c.s

CMakeFiles/miniftpd.dir/parseconf.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/parseconf.c.o.requires

CMakeFiles/miniftpd.dir/parseconf.c.o.provides: CMakeFiles/miniftpd.dir/parseconf.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/parseconf.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/parseconf.c.o.provides

CMakeFiles/miniftpd.dir/parseconf.c.o.provides.build: CMakeFiles/miniftpd.dir/parseconf.c.o


CMakeFiles/miniftpd.dir/privparent.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/privparent.c.o: ../privparent.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/miniftpd.dir/privparent.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/privparent.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/privparent.c

CMakeFiles/miniftpd.dir/privparent.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/privparent.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/privparent.c > CMakeFiles/miniftpd.dir/privparent.c.i

CMakeFiles/miniftpd.dir/privparent.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/privparent.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/privparent.c -o CMakeFiles/miniftpd.dir/privparent.c.s

CMakeFiles/miniftpd.dir/privparent.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/privparent.c.o.requires

CMakeFiles/miniftpd.dir/privparent.c.o.provides: CMakeFiles/miniftpd.dir/privparent.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/privparent.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/privparent.c.o.provides

CMakeFiles/miniftpd.dir/privparent.c.o.provides.build: CMakeFiles/miniftpd.dir/privparent.c.o


CMakeFiles/miniftpd.dir/privsock.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/privsock.c.o: ../privsock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/miniftpd.dir/privsock.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/privsock.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/privsock.c

CMakeFiles/miniftpd.dir/privsock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/privsock.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/privsock.c > CMakeFiles/miniftpd.dir/privsock.c.i

CMakeFiles/miniftpd.dir/privsock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/privsock.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/privsock.c -o CMakeFiles/miniftpd.dir/privsock.c.s

CMakeFiles/miniftpd.dir/privsock.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/privsock.c.o.requires

CMakeFiles/miniftpd.dir/privsock.c.o.provides: CMakeFiles/miniftpd.dir/privsock.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/privsock.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/privsock.c.o.provides

CMakeFiles/miniftpd.dir/privsock.c.o.provides.build: CMakeFiles/miniftpd.dir/privsock.c.o


CMakeFiles/miniftpd.dir/session.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/session.c.o: ../session.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/miniftpd.dir/session.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/session.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/session.c

CMakeFiles/miniftpd.dir/session.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/session.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/session.c > CMakeFiles/miniftpd.dir/session.c.i

CMakeFiles/miniftpd.dir/session.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/session.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/session.c -o CMakeFiles/miniftpd.dir/session.c.s

CMakeFiles/miniftpd.dir/session.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/session.c.o.requires

CMakeFiles/miniftpd.dir/session.c.o.provides: CMakeFiles/miniftpd.dir/session.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/session.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/session.c.o.provides

CMakeFiles/miniftpd.dir/session.c.o.provides.build: CMakeFiles/miniftpd.dir/session.c.o


CMakeFiles/miniftpd.dir/str.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/str.c.o: ../str.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/miniftpd.dir/str.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/str.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/str.c

CMakeFiles/miniftpd.dir/str.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/str.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/str.c > CMakeFiles/miniftpd.dir/str.c.i

CMakeFiles/miniftpd.dir/str.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/str.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/str.c -o CMakeFiles/miniftpd.dir/str.c.s

CMakeFiles/miniftpd.dir/str.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/str.c.o.requires

CMakeFiles/miniftpd.dir/str.c.o.provides: CMakeFiles/miniftpd.dir/str.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/str.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/str.c.o.provides

CMakeFiles/miniftpd.dir/str.c.o.provides.build: CMakeFiles/miniftpd.dir/str.c.o


CMakeFiles/miniftpd.dir/sysutil.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/sysutil.c.o: ../sysutil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/miniftpd.dir/sysutil.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/sysutil.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/sysutil.c

CMakeFiles/miniftpd.dir/sysutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/sysutil.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/sysutil.c > CMakeFiles/miniftpd.dir/sysutil.c.i

CMakeFiles/miniftpd.dir/sysutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/sysutil.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/sysutil.c -o CMakeFiles/miniftpd.dir/sysutil.c.s

CMakeFiles/miniftpd.dir/sysutil.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/sysutil.c.o.requires

CMakeFiles/miniftpd.dir/sysutil.c.o.provides: CMakeFiles/miniftpd.dir/sysutil.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/sysutil.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/sysutil.c.o.provides

CMakeFiles/miniftpd.dir/sysutil.c.o.provides.build: CMakeFiles/miniftpd.dir/sysutil.c.o


CMakeFiles/miniftpd.dir/tunable.c.o: CMakeFiles/miniftpd.dir/flags.make
CMakeFiles/miniftpd.dir/tunable.c.o: ../tunable.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/miniftpd.dir/tunable.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miniftpd.dir/tunable.c.o   -c /home/duwenqin123/CLionProjects/miniftpd27/tunable.c

CMakeFiles/miniftpd.dir/tunable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniftpd.dir/tunable.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/duwenqin123/CLionProjects/miniftpd27/tunable.c > CMakeFiles/miniftpd.dir/tunable.c.i

CMakeFiles/miniftpd.dir/tunable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniftpd.dir/tunable.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/duwenqin123/CLionProjects/miniftpd27/tunable.c -o CMakeFiles/miniftpd.dir/tunable.c.s

CMakeFiles/miniftpd.dir/tunable.c.o.requires:

.PHONY : CMakeFiles/miniftpd.dir/tunable.c.o.requires

CMakeFiles/miniftpd.dir/tunable.c.o.provides: CMakeFiles/miniftpd.dir/tunable.c.o.requires
	$(MAKE) -f CMakeFiles/miniftpd.dir/build.make CMakeFiles/miniftpd.dir/tunable.c.o.provides.build
.PHONY : CMakeFiles/miniftpd.dir/tunable.c.o.provides

CMakeFiles/miniftpd.dir/tunable.c.o.provides.build: CMakeFiles/miniftpd.dir/tunable.c.o


# Object files for target miniftpd
miniftpd_OBJECTS = \
"CMakeFiles/miniftpd.dir/ftpproto.c.o" \
"CMakeFiles/miniftpd.dir/hash.c.o" \
"CMakeFiles/miniftpd.dir/main.c.o" \
"CMakeFiles/miniftpd.dir/parseconf.c.o" \
"CMakeFiles/miniftpd.dir/privparent.c.o" \
"CMakeFiles/miniftpd.dir/privsock.c.o" \
"CMakeFiles/miniftpd.dir/session.c.o" \
"CMakeFiles/miniftpd.dir/str.c.o" \
"CMakeFiles/miniftpd.dir/sysutil.c.o" \
"CMakeFiles/miniftpd.dir/tunable.c.o"

# External object files for target miniftpd
miniftpd_EXTERNAL_OBJECTS =

../miniftpd: CMakeFiles/miniftpd.dir/ftpproto.c.o
../miniftpd: CMakeFiles/miniftpd.dir/hash.c.o
../miniftpd: CMakeFiles/miniftpd.dir/main.c.o
../miniftpd: CMakeFiles/miniftpd.dir/parseconf.c.o
../miniftpd: CMakeFiles/miniftpd.dir/privparent.c.o
../miniftpd: CMakeFiles/miniftpd.dir/privsock.c.o
../miniftpd: CMakeFiles/miniftpd.dir/session.c.o
../miniftpd: CMakeFiles/miniftpd.dir/str.c.o
../miniftpd: CMakeFiles/miniftpd.dir/sysutil.c.o
../miniftpd: CMakeFiles/miniftpd.dir/tunable.c.o
../miniftpd: CMakeFiles/miniftpd.dir/build.make
../miniftpd: CMakeFiles/miniftpd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable ../miniftpd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/miniftpd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/miniftpd.dir/build: ../miniftpd

.PHONY : CMakeFiles/miniftpd.dir/build

CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/ftpproto.c.o.requires
CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/hash.c.o.requires
CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/main.c.o.requires
CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/parseconf.c.o.requires
CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/privparent.c.o.requires
CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/privsock.c.o.requires
CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/session.c.o.requires
CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/str.c.o.requires
CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/sysutil.c.o.requires
CMakeFiles/miniftpd.dir/requires: CMakeFiles/miniftpd.dir/tunable.c.o.requires

.PHONY : CMakeFiles/miniftpd.dir/requires

CMakeFiles/miniftpd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/miniftpd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/miniftpd.dir/clean

CMakeFiles/miniftpd.dir/depend:
	cd /home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/duwenqin123/CLionProjects/miniftpd27 /home/duwenqin123/CLionProjects/miniftpd27 /home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug /home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug /home/duwenqin123/CLionProjects/miniftpd27/cmake-build-debug/CMakeFiles/miniftpd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/miniftpd.dir/depend
