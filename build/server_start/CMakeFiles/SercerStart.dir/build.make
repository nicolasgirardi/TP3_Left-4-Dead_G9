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
include server_start/CMakeFiles/SercerStart.dir/depend.make

# Include the progress variables for this target.
include server_start/CMakeFiles/SercerStart.dir/progress.make

# Include the compile flags for this target's objects.
include server_start/CMakeFiles/SercerStart.dir/flags.make

server_start/CMakeFiles/SercerStart.dir/server_aceptador.cpp.o: server_start/CMakeFiles/SercerStart.dir/flags.make
server_start/CMakeFiles/SercerStart.dir/server_aceptador.cpp.o: ../server_start/server_aceptador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object server_start/CMakeFiles/SercerStart.dir/server_aceptador.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SercerStart.dir/server_aceptador.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_aceptador.cpp

server_start/CMakeFiles/SercerStart.dir/server_aceptador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SercerStart.dir/server_aceptador.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_aceptador.cpp > CMakeFiles/SercerStart.dir/server_aceptador.cpp.i

server_start/CMakeFiles/SercerStart.dir/server_aceptador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SercerStart.dir/server_aceptador.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_aceptador.cpp -o CMakeFiles/SercerStart.dir/server_aceptador.cpp.s

server_start/CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.o: server_start/CMakeFiles/SercerStart.dir/flags.make
server_start/CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.o: ../server_start/server_cliente_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object server_start/CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_cliente_handler.cpp

server_start/CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_cliente_handler.cpp > CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.i

server_start/CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_cliente_handler.cpp -o CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.s

server_start/CMakeFiles/SercerStart.dir/server_main.cpp.o: server_start/CMakeFiles/SercerStart.dir/flags.make
server_start/CMakeFiles/SercerStart.dir/server_main.cpp.o: ../server_start/server_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object server_start/CMakeFiles/SercerStart.dir/server_main.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SercerStart.dir/server_main.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_main.cpp

server_start/CMakeFiles/SercerStart.dir/server_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SercerStart.dir/server_main.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_main.cpp > CMakeFiles/SercerStart.dir/server_main.cpp.i

server_start/CMakeFiles/SercerStart.dir/server_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SercerStart.dir/server_main.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_main.cpp -o CMakeFiles/SercerStart.dir/server_main.cpp.s

server_start/CMakeFiles/SercerStart.dir/server_protocolo.cpp.o: server_start/CMakeFiles/SercerStart.dir/flags.make
server_start/CMakeFiles/SercerStart.dir/server_protocolo.cpp.o: ../server_start/server_protocolo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object server_start/CMakeFiles/SercerStart.dir/server_protocolo.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SercerStart.dir/server_protocolo.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_protocolo.cpp

server_start/CMakeFiles/SercerStart.dir/server_protocolo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SercerStart.dir/server_protocolo.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_protocolo.cpp > CMakeFiles/SercerStart.dir/server_protocolo.cpp.i

server_start/CMakeFiles/SercerStart.dir/server_protocolo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SercerStart.dir/server_protocolo.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_protocolo.cpp -o CMakeFiles/SercerStart.dir/server_protocolo.cpp.s

server_start/CMakeFiles/SercerStart.dir/server_reciever.cpp.o: server_start/CMakeFiles/SercerStart.dir/flags.make
server_start/CMakeFiles/SercerStart.dir/server_reciever.cpp.o: ../server_start/server_reciever.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object server_start/CMakeFiles/SercerStart.dir/server_reciever.cpp.o"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SercerStart.dir/server_reciever.cpp.o -c /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_reciever.cpp

server_start/CMakeFiles/SercerStart.dir/server_reciever.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SercerStart.dir/server_reciever.cpp.i"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_reciever.cpp > CMakeFiles/SercerStart.dir/server_reciever.cpp.i

server_start/CMakeFiles/SercerStart.dir/server_reciever.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SercerStart.dir/server_reciever.cpp.s"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start/server_reciever.cpp -o CMakeFiles/SercerStart.dir/server_reciever.cpp.s

# Object files for target SercerStart
SercerStart_OBJECTS = \
"CMakeFiles/SercerStart.dir/server_aceptador.cpp.o" \
"CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.o" \
"CMakeFiles/SercerStart.dir/server_main.cpp.o" \
"CMakeFiles/SercerStart.dir/server_protocolo.cpp.o" \
"CMakeFiles/SercerStart.dir/server_reciever.cpp.o"

# External object files for target SercerStart
SercerStart_EXTERNAL_OBJECTS =

server_start/libSercerStart.a: server_start/CMakeFiles/SercerStart.dir/server_aceptador.cpp.o
server_start/libSercerStart.a: server_start/CMakeFiles/SercerStart.dir/server_cliente_handler.cpp.o
server_start/libSercerStart.a: server_start/CMakeFiles/SercerStart.dir/server_main.cpp.o
server_start/libSercerStart.a: server_start/CMakeFiles/SercerStart.dir/server_protocolo.cpp.o
server_start/libSercerStart.a: server_start/CMakeFiles/SercerStart.dir/server_reciever.cpp.o
server_start/libSercerStart.a: server_start/CMakeFiles/SercerStart.dir/build.make
server_start/libSercerStart.a: server_start/CMakeFiles/SercerStart.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libSercerStart.a"
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && $(CMAKE_COMMAND) -P CMakeFiles/SercerStart.dir/cmake_clean_target.cmake
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SercerStart.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server_start/CMakeFiles/SercerStart.dir/build: server_start/libSercerStart.a

.PHONY : server_start/CMakeFiles/SercerStart.dir/build

server_start/CMakeFiles/SercerStart.dir/clean:
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start && $(CMAKE_COMMAND) -P CMakeFiles/SercerStart.dir/cmake_clean.cmake
.PHONY : server_start/CMakeFiles/SercerStart.dir/clean

server_start/CMakeFiles/SercerStart.dir/depend:
	cd /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9 /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/server_start /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start /home/fede/Desktop/Facultad/Taller/TP3_Left-4-Dead_G9/build/server_start/CMakeFiles/SercerStart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server_start/CMakeFiles/SercerStart.dir/depend

