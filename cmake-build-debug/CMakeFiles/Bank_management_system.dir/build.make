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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/bindu/CLionProjects/Bank management system"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/bindu/CLionProjects/Bank management system/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Bank_management_system.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bank_management_system.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bank_management_system.dir/flags.make

CMakeFiles/Bank_management_system.dir/main.c.o: CMakeFiles/Bank_management_system.dir/flags.make
CMakeFiles/Bank_management_system.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/bindu/CLionProjects/Bank management system/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Bank_management_system.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Bank_management_system.dir/main.c.o   -c "/Users/bindu/CLionProjects/Bank management system/main.c"

CMakeFiles/Bank_management_system.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Bank_management_system.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/bindu/CLionProjects/Bank management system/main.c" > CMakeFiles/Bank_management_system.dir/main.c.i

CMakeFiles/Bank_management_system.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Bank_management_system.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/bindu/CLionProjects/Bank management system/main.c" -o CMakeFiles/Bank_management_system.dir/main.c.s

# Object files for target Bank_management_system
Bank_management_system_OBJECTS = \
"CMakeFiles/Bank_management_system.dir/main.c.o"

# External object files for target Bank_management_system
Bank_management_system_EXTERNAL_OBJECTS =

Bank_management_system: CMakeFiles/Bank_management_system.dir/main.c.o
Bank_management_system: CMakeFiles/Bank_management_system.dir/build.make
Bank_management_system: CMakeFiles/Bank_management_system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/bindu/CLionProjects/Bank management system/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Bank_management_system"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bank_management_system.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bank_management_system.dir/build: Bank_management_system

.PHONY : CMakeFiles/Bank_management_system.dir/build

CMakeFiles/Bank_management_system.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bank_management_system.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bank_management_system.dir/clean

CMakeFiles/Bank_management_system.dir/depend:
	cd "/Users/bindu/CLionProjects/Bank management system/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/bindu/CLionProjects/Bank management system" "/Users/bindu/CLionProjects/Bank management system" "/Users/bindu/CLionProjects/Bank management system/cmake-build-debug" "/Users/bindu/CLionProjects/Bank management system/cmake-build-debug" "/Users/bindu/CLionProjects/Bank management system/cmake-build-debug/CMakeFiles/Bank_management_system.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Bank_management_system.dir/depend

