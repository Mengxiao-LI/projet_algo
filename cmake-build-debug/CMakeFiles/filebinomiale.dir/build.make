# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zyu/Desktop/Projet/projet_algo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zyu/Desktop/Projet/projet_algo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/filebinomiale.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/filebinomiale.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/filebinomiale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/filebinomiale.dir/flags.make

CMakeFiles/filebinomiale.dir/main.c.o: CMakeFiles/filebinomiale.dir/flags.make
CMakeFiles/filebinomiale.dir/main.c.o: /Users/zyu/Desktop/Projet/projet_algo/main.c
CMakeFiles/filebinomiale.dir/main.c.o: CMakeFiles/filebinomiale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zyu/Desktop/Projet/projet_algo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/filebinomiale.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/filebinomiale.dir/main.c.o -MF CMakeFiles/filebinomiale.dir/main.c.o.d -o CMakeFiles/filebinomiale.dir/main.c.o -c /Users/zyu/Desktop/Projet/projet_algo/main.c

CMakeFiles/filebinomiale.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filebinomiale.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zyu/Desktop/Projet/projet_algo/main.c > CMakeFiles/filebinomiale.dir/main.c.i

CMakeFiles/filebinomiale.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filebinomiale.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zyu/Desktop/Projet/projet_algo/main.c -o CMakeFiles/filebinomiale.dir/main.c.s

CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.o: CMakeFiles/filebinomiale.dir/flags.make
CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.o: /Users/zyu/Desktop/Projet/projet_algo/fileBinomiale/filebinomiale.c
CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.o: CMakeFiles/filebinomiale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zyu/Desktop/Projet/projet_algo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.o -MF CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.o.d -o CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.o -c /Users/zyu/Desktop/Projet/projet_algo/fileBinomiale/filebinomiale.c

CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zyu/Desktop/Projet/projet_algo/fileBinomiale/filebinomiale.c > CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.i

CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zyu/Desktop/Projet/projet_algo/fileBinomiale/filebinomiale.c -o CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.s

# Object files for target filebinomiale
filebinomiale_OBJECTS = \
"CMakeFiles/filebinomiale.dir/main.c.o" \
"CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.o"

# External object files for target filebinomiale
filebinomiale_EXTERNAL_OBJECTS =

filebinomiale: CMakeFiles/filebinomiale.dir/main.c.o
filebinomiale: CMakeFiles/filebinomiale.dir/fileBinomiale/filebinomiale.c.o
filebinomiale: CMakeFiles/filebinomiale.dir/build.make
filebinomiale: CMakeFiles/filebinomiale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zyu/Desktop/Projet/projet_algo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable filebinomiale"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/filebinomiale.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/filebinomiale.dir/build: filebinomiale
.PHONY : CMakeFiles/filebinomiale.dir/build

CMakeFiles/filebinomiale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/filebinomiale.dir/cmake_clean.cmake
.PHONY : CMakeFiles/filebinomiale.dir/clean

CMakeFiles/filebinomiale.dir/depend:
	cd /Users/zyu/Desktop/Projet/projet_algo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zyu/Desktop/Projet/projet_algo /Users/zyu/Desktop/Projet/projet_algo /Users/zyu/Desktop/Projet/projet_algo/cmake-build-debug /Users/zyu/Desktop/Projet/projet_algo/cmake-build-debug /Users/zyu/Desktop/Projet/projet_algo/cmake-build-debug/CMakeFiles/filebinomiale.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/filebinomiale.dir/depend

