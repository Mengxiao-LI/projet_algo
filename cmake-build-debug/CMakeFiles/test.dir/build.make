# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projet\projet_algo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projet\projet_algo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/main_test.c.obj: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/main_test.c.obj: C:/Projet/projet_algo/main_test.c
CMakeFiles/test.dir/main_test.c.obj: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projet\projet_algo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test.dir/main_test.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/main_test.c.obj -MF CMakeFiles\test.dir\main_test.c.obj.d -o CMakeFiles\test.dir\main_test.c.obj -c C:\Projet\projet_algo\main_test.c

CMakeFiles/test.dir/main_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/main_test.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projet\projet_algo\main_test.c > CMakeFiles\test.dir\main_test.c.i

CMakeFiles/test.dir/main_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/main_test.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projet\projet_algo\main_test.c -o CMakeFiles\test.dir\main_test.c.s

CMakeFiles/test.dir/tas/test.c.obj: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/tas/test.c.obj: C:/Projet/projet_algo/tas/test.c
CMakeFiles/test.dir/tas/test.c.obj: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projet\projet_algo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test.dir/tas/test.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/tas/test.c.obj -MF CMakeFiles\test.dir\tas\test.c.obj.d -o CMakeFiles\test.dir\tas\test.c.obj -c C:\Projet\projet_algo\tas\test.c

CMakeFiles/test.dir/tas/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/tas/test.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projet\projet_algo\tas\test.c > CMakeFiles\test.dir\tas\test.c.i

CMakeFiles/test.dir/tas/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/tas/test.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projet\projet_algo\tas\test.c -o CMakeFiles\test.dir\tas\test.c.s

CMakeFiles/test.dir/echauffement/echauffement.c.obj: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/echauffement/echauffement.c.obj: C:/Projet/projet_algo/echauffement/echauffement.c
CMakeFiles/test.dir/echauffement/echauffement.c.obj: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projet\projet_algo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test.dir/echauffement/echauffement.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/echauffement/echauffement.c.obj -MF CMakeFiles\test.dir\echauffement\echauffement.c.obj.d -o CMakeFiles\test.dir\echauffement\echauffement.c.obj -c C:\Projet\projet_algo\echauffement\echauffement.c

CMakeFiles/test.dir/echauffement/echauffement.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/echauffement/echauffement.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projet\projet_algo\echauffement\echauffement.c > CMakeFiles\test.dir\echauffement\echauffement.c.i

CMakeFiles/test.dir/echauffement/echauffement.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/echauffement/echauffement.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projet\projet_algo\echauffement\echauffement.c -o CMakeFiles\test.dir\echauffement\echauffement.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/main_test.c.obj" \
"CMakeFiles/test.dir/tas/test.c.obj" \
"CMakeFiles/test.dir/echauffement/echauffement.c.obj"

# External object files for target test
test_EXTERNAL_OBJECTS =

test.exe: CMakeFiles/test.dir/main_test.c.obj
test.exe: CMakeFiles/test.dir/tas/test.c.obj
test.exe: CMakeFiles/test.dir/echauffement/echauffement.c.obj
test.exe: CMakeFiles/test.dir/build.make
test.exe: CMakeFiles/test.dir/linkLibs.rsp
test.exe: CMakeFiles/test.dir/objects1.rsp
test.exe: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projet\projet_algo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test.exe
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projet\projet_algo C:\Projet\projet_algo C:\Projet\projet_algo\cmake-build-debug C:\Projet\projet_algo\cmake-build-debug C:\Projet\projet_algo\cmake-build-debug\CMakeFiles\test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend
