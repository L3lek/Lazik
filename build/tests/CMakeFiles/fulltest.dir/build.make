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
CMAKE_SOURCE_DIR = /home/nikodeml/programowanie/PO/Zad6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikodeml/programowanie/PO/Zad6/build

# Utility rule file for fulltest.

# Include the progress variables for this target.
include tests/CMakeFiles/fulltest.dir/progress.make

tests/CMakeFiles/fulltest:
	cd /home/nikodeml/programowanie/PO/Zad6/build/tests && /home/nikodeml/programowanie/PO/Zad6/build/unit_tests -s

fulltest: tests/CMakeFiles/fulltest
fulltest: tests/CMakeFiles/fulltest.dir/build.make

.PHONY : fulltest

# Rule to build all files generated by this target.
tests/CMakeFiles/fulltest.dir/build: fulltest

.PHONY : tests/CMakeFiles/fulltest.dir/build

tests/CMakeFiles/fulltest.dir/clean:
	cd /home/nikodeml/programowanie/PO/Zad6/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/fulltest.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/fulltest.dir/clean

tests/CMakeFiles/fulltest.dir/depend:
	cd /home/nikodeml/programowanie/PO/Zad6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikodeml/programowanie/PO/Zad6 /home/nikodeml/programowanie/PO/Zad6/tests /home/nikodeml/programowanie/PO/Zad6/build /home/nikodeml/programowanie/PO/Zad6/build/tests /home/nikodeml/programowanie/PO/Zad6/build/tests/CMakeFiles/fulltest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/fulltest.dir/depend

