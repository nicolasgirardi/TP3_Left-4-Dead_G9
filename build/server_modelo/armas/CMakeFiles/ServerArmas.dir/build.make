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
include server_modelo/armas/CMakeFiles/ServerArmas.dir/depend.make

# Include the progress variables for this target.
include server_modelo/armas/CMakeFiles/ServerArmas.dir/progress.make

# Include the compile flags for this target's objects.
include server_modelo/armas/CMakeFiles/ServerArmas.dir/flags.make

server_modelo/armas/CMakeFiles/ServerArmas.dir/arma.cpp.o: server_modelo/armas/CMakeFiles/ServerArmas.dir/flags.make
server_modelo/armas/CMakeFiles/ServerArmas.dir/arma.cpp.o: ../server_modelo/armas/arma.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object server_modelo/armas/CMakeFiles/ServerArmas.dir/arma.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerArmas.dir/arma.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/arma.cpp

server_modelo/armas/CMakeFiles/ServerArmas.dir/arma.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerArmas.dir/arma.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/arma.cpp > CMakeFiles/ServerArmas.dir/arma.cpp.i

server_modelo/armas/CMakeFiles/ServerArmas.dir/arma.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerArmas.dir/arma.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/arma.cpp -o CMakeFiles/ServerArmas.dir/arma.cpp.s

server_modelo/armas/CMakeFiles/ServerArmas.dir/creador_armas.cpp.o: server_modelo/armas/CMakeFiles/ServerArmas.dir/flags.make
server_modelo/armas/CMakeFiles/ServerArmas.dir/creador_armas.cpp.o: ../server_modelo/armas/creador_armas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object server_modelo/armas/CMakeFiles/ServerArmas.dir/creador_armas.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerArmas.dir/creador_armas.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/creador_armas.cpp

server_modelo/armas/CMakeFiles/ServerArmas.dir/creador_armas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerArmas.dir/creador_armas.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/creador_armas.cpp > CMakeFiles/ServerArmas.dir/creador_armas.cpp.i

server_modelo/armas/CMakeFiles/ServerArmas.dir/creador_armas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerArmas.dir/creador_armas.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/creador_armas.cpp -o CMakeFiles/ServerArmas.dir/creador_armas.cpp.s

server_modelo/armas/CMakeFiles/ServerArmas.dir/idf.cpp.o: server_modelo/armas/CMakeFiles/ServerArmas.dir/flags.make
server_modelo/armas/CMakeFiles/ServerArmas.dir/idf.cpp.o: ../server_modelo/armas/idf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object server_modelo/armas/CMakeFiles/ServerArmas.dir/idf.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerArmas.dir/idf.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/idf.cpp

server_modelo/armas/CMakeFiles/ServerArmas.dir/idf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerArmas.dir/idf.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/idf.cpp > CMakeFiles/ServerArmas.dir/idf.cpp.i

server_modelo/armas/CMakeFiles/ServerArmas.dir/idf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerArmas.dir/idf.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/idf.cpp -o CMakeFiles/ServerArmas.dir/idf.cpp.s

server_modelo/armas/CMakeFiles/ServerArmas.dir/p90.cpp.o: server_modelo/armas/CMakeFiles/ServerArmas.dir/flags.make
server_modelo/armas/CMakeFiles/ServerArmas.dir/p90.cpp.o: ../server_modelo/armas/p90.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object server_modelo/armas/CMakeFiles/ServerArmas.dir/p90.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerArmas.dir/p90.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/p90.cpp

server_modelo/armas/CMakeFiles/ServerArmas.dir/p90.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerArmas.dir/p90.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/p90.cpp > CMakeFiles/ServerArmas.dir/p90.cpp.i

server_modelo/armas/CMakeFiles/ServerArmas.dir/p90.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerArmas.dir/p90.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/p90.cpp -o CMakeFiles/ServerArmas.dir/p90.cpp.s

server_modelo/armas/CMakeFiles/ServerArmas.dir/scout.cpp.o: server_modelo/armas/CMakeFiles/ServerArmas.dir/flags.make
server_modelo/armas/CMakeFiles/ServerArmas.dir/scout.cpp.o: ../server_modelo/armas/scout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object server_modelo/armas/CMakeFiles/ServerArmas.dir/scout.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerArmas.dir/scout.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/scout.cpp

server_modelo/armas/CMakeFiles/ServerArmas.dir/scout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerArmas.dir/scout.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/scout.cpp > CMakeFiles/ServerArmas.dir/scout.cpp.i

server_modelo/armas/CMakeFiles/ServerArmas.dir/scout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerArmas.dir/scout.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas/scout.cpp -o CMakeFiles/ServerArmas.dir/scout.cpp.s

# Object files for target ServerArmas
ServerArmas_OBJECTS = \
"CMakeFiles/ServerArmas.dir/arma.cpp.o" \
"CMakeFiles/ServerArmas.dir/creador_armas.cpp.o" \
"CMakeFiles/ServerArmas.dir/idf.cpp.o" \
"CMakeFiles/ServerArmas.dir/p90.cpp.o" \
"CMakeFiles/ServerArmas.dir/scout.cpp.o"

# External object files for target ServerArmas
ServerArmas_EXTERNAL_OBJECTS =

server_modelo/armas/libServerArmas.a: server_modelo/armas/CMakeFiles/ServerArmas.dir/arma.cpp.o
server_modelo/armas/libServerArmas.a: server_modelo/armas/CMakeFiles/ServerArmas.dir/creador_armas.cpp.o
server_modelo/armas/libServerArmas.a: server_modelo/armas/CMakeFiles/ServerArmas.dir/idf.cpp.o
server_modelo/armas/libServerArmas.a: server_modelo/armas/CMakeFiles/ServerArmas.dir/p90.cpp.o
server_modelo/armas/libServerArmas.a: server_modelo/armas/CMakeFiles/ServerArmas.dir/scout.cpp.o
server_modelo/armas/libServerArmas.a: server_modelo/armas/CMakeFiles/ServerArmas.dir/build.make
server_modelo/armas/libServerArmas.a: server_modelo/armas/CMakeFiles/ServerArmas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libServerArmas.a"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && $(CMAKE_COMMAND) -P CMakeFiles/ServerArmas.dir/cmake_clean_target.cmake
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ServerArmas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server_modelo/armas/CMakeFiles/ServerArmas.dir/build: server_modelo/armas/libServerArmas.a

.PHONY : server_modelo/armas/CMakeFiles/ServerArmas.dir/build

server_modelo/armas/CMakeFiles/ServerArmas.dir/clean:
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas && $(CMAKE_COMMAND) -P CMakeFiles/ServerArmas.dir/cmake_clean.cmake
.PHONY : server_modelo/armas/CMakeFiles/ServerArmas.dir/clean

server_modelo/armas/CMakeFiles/ServerArmas.dir/depend:
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9 /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_modelo/armas /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_modelo/armas/CMakeFiles/ServerArmas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server_modelo/armas/CMakeFiles/ServerArmas.dir/depend
