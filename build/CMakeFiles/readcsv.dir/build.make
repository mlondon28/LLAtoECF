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
CMAKE_SOURCE_DIR = /home/matt/projects/scitec-coding-problem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matt/projects/scitec-coding-problem/build

# Include any dependencies generated for this target.
include CMakeFiles/readcsv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/readcsv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/readcsv.dir/flags.make

CMakeFiles/readcsv.dir/src/csv_utils.cpp.o: CMakeFiles/readcsv.dir/flags.make
CMakeFiles/readcsv.dir/src/csv_utils.cpp.o: ../src/csv_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matt/projects/scitec-coding-problem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/readcsv.dir/src/csv_utils.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/readcsv.dir/src/csv_utils.cpp.o -c /home/matt/projects/scitec-coding-problem/src/csv_utils.cpp

CMakeFiles/readcsv.dir/src/csv_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/readcsv.dir/src/csv_utils.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matt/projects/scitec-coding-problem/src/csv_utils.cpp > CMakeFiles/readcsv.dir/src/csv_utils.cpp.i

CMakeFiles/readcsv.dir/src/csv_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/readcsv.dir/src/csv_utils.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matt/projects/scitec-coding-problem/src/csv_utils.cpp -o CMakeFiles/readcsv.dir/src/csv_utils.cpp.s

# Object files for target readcsv
readcsv_OBJECTS = \
"CMakeFiles/readcsv.dir/src/csv_utils.cpp.o"

# External object files for target readcsv
readcsv_EXTERNAL_OBJECTS =

libreadcsv.a: CMakeFiles/readcsv.dir/src/csv_utils.cpp.o
libreadcsv.a: CMakeFiles/readcsv.dir/build.make
libreadcsv.a: CMakeFiles/readcsv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matt/projects/scitec-coding-problem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libreadcsv.a"
	$(CMAKE_COMMAND) -P CMakeFiles/readcsv.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/readcsv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/readcsv.dir/build: libreadcsv.a

.PHONY : CMakeFiles/readcsv.dir/build

CMakeFiles/readcsv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/readcsv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/readcsv.dir/clean

CMakeFiles/readcsv.dir/depend:
	cd /home/matt/projects/scitec-coding-problem/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matt/projects/scitec-coding-problem /home/matt/projects/scitec-coding-problem /home/matt/projects/scitec-coding-problem/build /home/matt/projects/scitec-coding-problem/build /home/matt/projects/scitec-coding-problem/build/CMakeFiles/readcsv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/readcsv.dir/depend
