# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/clion-2018.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/matrixMult.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/matrixMult.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/matrixMult.dir/flags.make

CMakeFiles/matrixMult.dir/matrixMult.c.o: CMakeFiles/matrixMult.dir/flags.make
CMakeFiles/matrixMult.dir/matrixMult.c.o: ../matrixMult.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/matrixMult.dir/matrixMult.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/matrixMult.dir/matrixMult.c.o   -c /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/matrixMult.c

CMakeFiles/matrixMult.dir/matrixMult.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/matrixMult.dir/matrixMult.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/matrixMult.c > CMakeFiles/matrixMult.dir/matrixMult.c.i

CMakeFiles/matrixMult.dir/matrixMult.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/matrixMult.dir/matrixMult.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/matrixMult.c -o CMakeFiles/matrixMult.dir/matrixMult.c.s

# Object files for target matrixMult
matrixMult_OBJECTS = \
"CMakeFiles/matrixMult.dir/matrixMult.c.o"

# External object files for target matrixMult
matrixMult_EXTERNAL_OBJECTS =

bin/matrixMult: CMakeFiles/matrixMult.dir/matrixMult.c.o
bin/matrixMult: CMakeFiles/matrixMult.dir/build.make
bin/matrixMult: CMakeFiles/matrixMult.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/matrixMult"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrixMult.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/matrixMult.dir/build: bin/matrixMult

.PHONY : CMakeFiles/matrixMult.dir/build

CMakeFiles/matrixMult.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/matrixMult.dir/cmake_clean.cmake
.PHONY : CMakeFiles/matrixMult.dir/clean

CMakeFiles/matrixMult.dir/depend:
	cd /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/cmake-build-debug /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/cmake-build-debug /home/gabriel.espinosa936@csuci.edu/Desktop/matrixMult/cmake-build-debug/CMakeFiles/matrixMult.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/matrixMult.dir/depend

