# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/alexey/Downloads/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alexey/Downloads/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexey/Documents/git/MiniJavaCompiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexey/Documents/git/MiniJavaCompiler/cmake-build-debug

# Utility rule file for lexer.

# Include the progress variables for this target.
include CMakeFiles/lexer.dir/progress.make

CMakeFiles/lexer:
	cd /home/alexey/Documents/git/MiniJavaCompiler && make lexer

lexer: CMakeFiles/lexer
lexer: CMakeFiles/lexer.dir/build.make

.PHONY : lexer

# Rule to build all files generated by this target.
CMakeFiles/lexer.dir/build: lexer

.PHONY : CMakeFiles/lexer.dir/build

CMakeFiles/lexer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lexer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lexer.dir/clean

CMakeFiles/lexer.dir/depend:
	cd /home/alexey/Documents/git/MiniJavaCompiler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexey/Documents/git/MiniJavaCompiler /home/alexey/Documents/git/MiniJavaCompiler /home/alexey/Documents/git/MiniJavaCompiler/cmake-build-debug /home/alexey/Documents/git/MiniJavaCompiler/cmake-build-debug /home/alexey/Documents/git/MiniJavaCompiler/cmake-build-debug/CMakeFiles/lexer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lexer.dir/depend

