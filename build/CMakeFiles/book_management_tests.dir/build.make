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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/build"

# Include any dependencies generated for this target.
include CMakeFiles/book_management_tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/book_management_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/book_management_tests.dir/flags.make

CMakeFiles/book_management_tests.dir/unit_tests.c.o: CMakeFiles/book_management_tests.dir/flags.make
CMakeFiles/book_management_tests.dir/unit_tests.c.o: ../unit_tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/book_management_tests.dir/unit_tests.c.o"
	/usr/local/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/book_management_tests.dir/unit_tests.c.o   -c "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/unit_tests.c"

CMakeFiles/book_management_tests.dir/unit_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/book_management_tests.dir/unit_tests.c.i"
	/usr/local/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/unit_tests.c" > CMakeFiles/book_management_tests.dir/unit_tests.c.i

CMakeFiles/book_management_tests.dir/unit_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/book_management_tests.dir/unit_tests.c.s"
	/usr/local/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/unit_tests.c" -o CMakeFiles/book_management_tests.dir/unit_tests.c.s

CMakeFiles/book_management_tests.dir/book_management.c.o: CMakeFiles/book_management_tests.dir/flags.make
CMakeFiles/book_management_tests.dir/book_management.c.o: ../book_management.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/book_management_tests.dir/book_management.c.o"
	/usr/local/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/book_management_tests.dir/book_management.c.o   -c "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/book_management.c"

CMakeFiles/book_management_tests.dir/book_management.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/book_management_tests.dir/book_management.c.i"
	/usr/local/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/book_management.c" > CMakeFiles/book_management_tests.dir/book_management.c.i

CMakeFiles/book_management_tests.dir/book_management.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/book_management_tests.dir/book_management.c.s"
	/usr/local/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/book_management.c" -o CMakeFiles/book_management_tests.dir/book_management.c.s

CMakeFiles/book_management_tests.dir/unity/src/unity.c.o: CMakeFiles/book_management_tests.dir/flags.make
CMakeFiles/book_management_tests.dir/unity/src/unity.c.o: ../unity/src/unity.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/book_management_tests.dir/unity/src/unity.c.o"
	/usr/local/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/book_management_tests.dir/unity/src/unity.c.o   -c "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/unity/src/unity.c"

CMakeFiles/book_management_tests.dir/unity/src/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/book_management_tests.dir/unity/src/unity.c.i"
	/usr/local/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/unity/src/unity.c" > CMakeFiles/book_management_tests.dir/unity/src/unity.c.i

CMakeFiles/book_management_tests.dir/unity/src/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/book_management_tests.dir/unity/src/unity.c.s"
	/usr/local/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/unity/src/unity.c" -o CMakeFiles/book_management_tests.dir/unity/src/unity.c.s

# Object files for target book_management_tests
book_management_tests_OBJECTS = \
"CMakeFiles/book_management_tests.dir/unit_tests.c.o" \
"CMakeFiles/book_management_tests.dir/book_management.c.o" \
"CMakeFiles/book_management_tests.dir/unity/src/unity.c.o"

# External object files for target book_management_tests
book_management_tests_EXTERNAL_OBJECTS =

book_management_tests: CMakeFiles/book_management_tests.dir/unit_tests.c.o
book_management_tests: CMakeFiles/book_management_tests.dir/book_management.c.o
book_management_tests: CMakeFiles/book_management_tests.dir/unity/src/unity.c.o
book_management_tests: CMakeFiles/book_management_tests.dir/build.make
book_management_tests: CMakeFiles/book_management_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable book_management_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/book_management_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/book_management_tests.dir/build: book_management_tests

.PHONY : CMakeFiles/book_management_tests.dir/build

CMakeFiles/book_management_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/book_management_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/book_management_tests.dir/clean

CMakeFiles/book_management_tests.dir/depend:
	cd "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1" "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1" "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/build" "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/build" "/Users/tomaspzpeborges/OneDrive - University of Leeds/Programming Project/sc19tpzp/CW1/build/CMakeFiles/book_management_tests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/book_management_tests.dir/depend

