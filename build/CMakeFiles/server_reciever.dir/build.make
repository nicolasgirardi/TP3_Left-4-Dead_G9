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
CMAKE_SOURCE_DIR = /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build

# Include any dependencies generated for this target.
include CMakeFiles/server_reciever.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server_reciever.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_reciever.dir/flags.make

CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.o: CMakeFiles/server_reciever.dir/flags.make
CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.o: ../server_start/server_reciever.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_reciever.cpp

CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_reciever.cpp > CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.i

CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_reciever.cpp -o CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.s

server_reciever: CMakeFiles/server_reciever.dir/server_start/server_reciever.cpp.o
server_reciever: CMakeFiles/server_reciever.dir/build.make

.PHONY : server_reciever

# Rule to build all files generated by this target.
CMakeFiles/server_reciever.dir/build: server_reciever

.PHONY : CMakeFiles/server_reciever.dir/build

CMakeFiles/server_reciever.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_reciever.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_reciever.dir/clean

CMakeFiles/server_reciever.dir/depend:
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9 /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9 /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles/server_reciever.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server_reciever.dir/depend

