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
CMAKE_SOURCE_DIR = /home/connor/Documents/GitHub/Tortilla/lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/connor/Documents/GitHub/Tortilla/lib

# Include any dependencies generated for this target.
include CMakeFiles/Tortilla.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tortilla.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tortilla.dir/flags.make

CMakeFiles/Tortilla.dir/main.cpp.o: CMakeFiles/Tortilla.dir/flags.make
CMakeFiles/Tortilla.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/connor/Documents/GitHub/Tortilla/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tortilla.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tortilla.dir/main.cpp.o -c /home/connor/Documents/GitHub/Tortilla/lib/main.cpp

CMakeFiles/Tortilla.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tortilla.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/connor/Documents/GitHub/Tortilla/lib/main.cpp > CMakeFiles/Tortilla.dir/main.cpp.i

CMakeFiles/Tortilla.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tortilla.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/connor/Documents/GitHub/Tortilla/lib/main.cpp -o CMakeFiles/Tortilla.dir/main.cpp.s

CMakeFiles/Tortilla.dir/CHIP8.cpp.o: CMakeFiles/Tortilla.dir/flags.make
CMakeFiles/Tortilla.dir/CHIP8.cpp.o: CHIP8.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/connor/Documents/GitHub/Tortilla/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tortilla.dir/CHIP8.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tortilla.dir/CHIP8.cpp.o -c /home/connor/Documents/GitHub/Tortilla/lib/CHIP8.cpp

CMakeFiles/Tortilla.dir/CHIP8.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tortilla.dir/CHIP8.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/connor/Documents/GitHub/Tortilla/lib/CHIP8.cpp > CMakeFiles/Tortilla.dir/CHIP8.cpp.i

CMakeFiles/Tortilla.dir/CHIP8.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tortilla.dir/CHIP8.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/connor/Documents/GitHub/Tortilla/lib/CHIP8.cpp -o CMakeFiles/Tortilla.dir/CHIP8.cpp.s

# Object files for target Tortilla
Tortilla_OBJECTS = \
"CMakeFiles/Tortilla.dir/main.cpp.o" \
"CMakeFiles/Tortilla.dir/CHIP8.cpp.o"

# External object files for target Tortilla
Tortilla_EXTERNAL_OBJECTS =

Tortilla: CMakeFiles/Tortilla.dir/main.cpp.o
Tortilla: CMakeFiles/Tortilla.dir/CHIP8.cpp.o
Tortilla: CMakeFiles/Tortilla.dir/build.make
Tortilla: CMakeFiles/Tortilla.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/connor/Documents/GitHub/Tortilla/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Tortilla"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tortilla.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tortilla.dir/build: Tortilla

.PHONY : CMakeFiles/Tortilla.dir/build

CMakeFiles/Tortilla.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tortilla.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tortilla.dir/clean

CMakeFiles/Tortilla.dir/depend:
	cd /home/connor/Documents/GitHub/Tortilla/lib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/connor/Documents/GitHub/Tortilla/lib /home/connor/Documents/GitHub/Tortilla/lib /home/connor/Documents/GitHub/Tortilla/lib /home/connor/Documents/GitHub/Tortilla/lib /home/connor/Documents/GitHub/Tortilla/lib/CMakeFiles/Tortilla.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tortilla.dir/depend
