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
include CMakeFiles/main_Tas_Min.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_Tas_Min.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_Tas_Min.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_Tas_Min.dir/flags.make

CMakeFiles/main_Tas_Min.dir/main_TasMin.c.obj: CMakeFiles/main_Tas_Min.dir/flags.make
CMakeFiles/main_Tas_Min.dir/main_TasMin.c.obj: C:/Projet/projet_algo/main_TasMin.c
CMakeFiles/main_Tas_Min.dir/main_TasMin.c.obj: CMakeFiles/main_Tas_Min.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projet\projet_algo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main_Tas_Min.dir/main_TasMin.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_Tas_Min.dir/main_TasMin.c.obj -MF CMakeFiles\main_Tas_Min.dir\main_TasMin.c.obj.d -o CMakeFiles\main_Tas_Min.dir\main_TasMin.c.obj -c C:\Projet\projet_algo\main_TasMin.c

CMakeFiles/main_Tas_Min.dir/main_TasMin.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_Tas_Min.dir/main_TasMin.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projet\projet_algo\main_TasMin.c > CMakeFiles\main_Tas_Min.dir\main_TasMin.c.i

CMakeFiles/main_Tas_Min.dir/main_TasMin.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_Tas_Min.dir/main_TasMin.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projet\projet_algo\main_TasMin.c -o CMakeFiles\main_Tas_Min.dir\main_TasMin.c.s

CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.obj: CMakeFiles/main_Tas_Min.dir/flags.make
CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.obj: C:/Projet/projet_algo/echauffement/echauffement.c
CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.obj: CMakeFiles/main_Tas_Min.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projet\projet_algo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.obj -MF CMakeFiles\main_Tas_Min.dir\echauffement\echauffement.c.obj.d -o CMakeFiles\main_Tas_Min.dir\echauffement\echauffement.c.obj -c C:\Projet\projet_algo\echauffement\echauffement.c

CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projet\projet_algo\echauffement\echauffement.c > CMakeFiles\main_Tas_Min.dir\echauffement\echauffement.c.i

CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projet\projet_algo\echauffement\echauffement.c -o CMakeFiles\main_Tas_Min.dir\echauffement\echauffement.c.s

CMakeFiles/main_Tas_Min.dir/tas/tas.c.obj: CMakeFiles/main_Tas_Min.dir/flags.make
CMakeFiles/main_Tas_Min.dir/tas/tas.c.obj: C:/Projet/projet_algo/tas/tas.c
CMakeFiles/main_Tas_Min.dir/tas/tas.c.obj: CMakeFiles/main_Tas_Min.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projet\projet_algo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main_Tas_Min.dir/tas/tas.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_Tas_Min.dir/tas/tas.c.obj -MF CMakeFiles\main_Tas_Min.dir\tas\tas.c.obj.d -o CMakeFiles\main_Tas_Min.dir\tas\tas.c.obj -c C:\Projet\projet_algo\tas\tas.c

CMakeFiles/main_Tas_Min.dir/tas/tas.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_Tas_Min.dir/tas/tas.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projet\projet_algo\tas\tas.c > CMakeFiles\main_Tas_Min.dir\tas\tas.c.i

CMakeFiles/main_Tas_Min.dir/tas/tas.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_Tas_Min.dir/tas/tas.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projet\projet_algo\tas\tas.c -o CMakeFiles\main_Tas_Min.dir\tas\tas.c.s

CMakeFiles/main_Tas_Min.dir/tas/list.c.obj: CMakeFiles/main_Tas_Min.dir/flags.make
CMakeFiles/main_Tas_Min.dir/tas/list.c.obj: C:/Projet/projet_algo/tas/list.c
CMakeFiles/main_Tas_Min.dir/tas/list.c.obj: CMakeFiles/main_Tas_Min.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projet\projet_algo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main_Tas_Min.dir/tas/list.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_Tas_Min.dir/tas/list.c.obj -MF CMakeFiles\main_Tas_Min.dir\tas\list.c.obj.d -o CMakeFiles\main_Tas_Min.dir\tas\list.c.obj -c C:\Projet\projet_algo\tas\list.c

CMakeFiles/main_Tas_Min.dir/tas/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_Tas_Min.dir/tas/list.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projet\projet_algo\tas\list.c > CMakeFiles\main_Tas_Min.dir\tas\list.c.i

CMakeFiles/main_Tas_Min.dir/tas/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_Tas_Min.dir/tas/list.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projet\projet_algo\tas\list.c -o CMakeFiles\main_Tas_Min.dir\tas\list.c.s

# Object files for target main_Tas_Min
main_Tas_Min_OBJECTS = \
"CMakeFiles/main_Tas_Min.dir/main_TasMin.c.obj" \
"CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.obj" \
"CMakeFiles/main_Tas_Min.dir/tas/tas.c.obj" \
"CMakeFiles/main_Tas_Min.dir/tas/list.c.obj"

# External object files for target main_Tas_Min
main_Tas_Min_EXTERNAL_OBJECTS =

main_Tas_Min.exe: CMakeFiles/main_Tas_Min.dir/main_TasMin.c.obj
main_Tas_Min.exe: CMakeFiles/main_Tas_Min.dir/echauffement/echauffement.c.obj
main_Tas_Min.exe: CMakeFiles/main_Tas_Min.dir/tas/tas.c.obj
main_Tas_Min.exe: CMakeFiles/main_Tas_Min.dir/tas/list.c.obj
main_Tas_Min.exe: CMakeFiles/main_Tas_Min.dir/build.make
main_Tas_Min.exe: CMakeFiles/main_Tas_Min.dir/linkLibs.rsp
main_Tas_Min.exe: CMakeFiles/main_Tas_Min.dir/objects1.rsp
main_Tas_Min.exe: CMakeFiles/main_Tas_Min.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projet\projet_algo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable main_Tas_Min.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main_Tas_Min.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_Tas_Min.dir/build: main_Tas_Min.exe
.PHONY : CMakeFiles/main_Tas_Min.dir/build

CMakeFiles/main_Tas_Min.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main_Tas_Min.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main_Tas_Min.dir/clean

CMakeFiles/main_Tas_Min.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projet\projet_algo C:\Projet\projet_algo C:\Projet\projet_algo\cmake-build-debug C:\Projet\projet_algo\cmake-build-debug C:\Projet\projet_algo\cmake-build-debug\CMakeFiles\main_Tas_Min.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_Tas_Min.dir/depend

