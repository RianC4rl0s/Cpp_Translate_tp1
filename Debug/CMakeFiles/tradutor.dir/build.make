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
CMAKE_SOURCE_DIR = /home/rian/Compiladores/Lab08

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rian/Compiladores/Lab08/Debug

# Include any dependencies generated for this target.
include CMakeFiles/tradutor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tradutor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tradutor.dir/flags.make

CMakeFiles/tradutor.dir/lexer.cpp.o: CMakeFiles/tradutor.dir/flags.make
CMakeFiles/tradutor.dir/lexer.cpp.o: ../lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rian/Compiladores/Lab08/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tradutor.dir/lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tradutor.dir/lexer.cpp.o -c /home/rian/Compiladores/Lab08/lexer.cpp

CMakeFiles/tradutor.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tradutor.dir/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rian/Compiladores/Lab08/lexer.cpp > CMakeFiles/tradutor.dir/lexer.cpp.i

CMakeFiles/tradutor.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tradutor.dir/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rian/Compiladores/Lab08/lexer.cpp -o CMakeFiles/tradutor.dir/lexer.cpp.s

CMakeFiles/tradutor.dir/parser.cpp.o: CMakeFiles/tradutor.dir/flags.make
CMakeFiles/tradutor.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rian/Compiladores/Lab08/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tradutor.dir/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tradutor.dir/parser.cpp.o -c /home/rian/Compiladores/Lab08/parser.cpp

CMakeFiles/tradutor.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tradutor.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rian/Compiladores/Lab08/parser.cpp > CMakeFiles/tradutor.dir/parser.cpp.i

CMakeFiles/tradutor.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tradutor.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rian/Compiladores/Lab08/parser.cpp -o CMakeFiles/tradutor.dir/parser.cpp.s

CMakeFiles/tradutor.dir/symtable.cpp.o: CMakeFiles/tradutor.dir/flags.make
CMakeFiles/tradutor.dir/symtable.cpp.o: ../symtable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rian/Compiladores/Lab08/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tradutor.dir/symtable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tradutor.dir/symtable.cpp.o -c /home/rian/Compiladores/Lab08/symtable.cpp

CMakeFiles/tradutor.dir/symtable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tradutor.dir/symtable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rian/Compiladores/Lab08/symtable.cpp > CMakeFiles/tradutor.dir/symtable.cpp.i

CMakeFiles/tradutor.dir/symtable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tradutor.dir/symtable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rian/Compiladores/Lab08/symtable.cpp -o CMakeFiles/tradutor.dir/symtable.cpp.s

CMakeFiles/tradutor.dir/error.cpp.o: CMakeFiles/tradutor.dir/flags.make
CMakeFiles/tradutor.dir/error.cpp.o: ../error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rian/Compiladores/Lab08/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tradutor.dir/error.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tradutor.dir/error.cpp.o -c /home/rian/Compiladores/Lab08/error.cpp

CMakeFiles/tradutor.dir/error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tradutor.dir/error.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rian/Compiladores/Lab08/error.cpp > CMakeFiles/tradutor.dir/error.cpp.i

CMakeFiles/tradutor.dir/error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tradutor.dir/error.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rian/Compiladores/Lab08/error.cpp -o CMakeFiles/tradutor.dir/error.cpp.s

CMakeFiles/tradutor.dir/tradutor.cpp.o: CMakeFiles/tradutor.dir/flags.make
CMakeFiles/tradutor.dir/tradutor.cpp.o: ../tradutor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rian/Compiladores/Lab08/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tradutor.dir/tradutor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tradutor.dir/tradutor.cpp.o -c /home/rian/Compiladores/Lab08/tradutor.cpp

CMakeFiles/tradutor.dir/tradutor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tradutor.dir/tradutor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rian/Compiladores/Lab08/tradutor.cpp > CMakeFiles/tradutor.dir/tradutor.cpp.i

CMakeFiles/tradutor.dir/tradutor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tradutor.dir/tradutor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rian/Compiladores/Lab08/tradutor.cpp -o CMakeFiles/tradutor.dir/tradutor.cpp.s

# Object files for target tradutor
tradutor_OBJECTS = \
"CMakeFiles/tradutor.dir/lexer.cpp.o" \
"CMakeFiles/tradutor.dir/parser.cpp.o" \
"CMakeFiles/tradutor.dir/symtable.cpp.o" \
"CMakeFiles/tradutor.dir/error.cpp.o" \
"CMakeFiles/tradutor.dir/tradutor.cpp.o"

# External object files for target tradutor
tradutor_EXTERNAL_OBJECTS =

tradutor: CMakeFiles/tradutor.dir/lexer.cpp.o
tradutor: CMakeFiles/tradutor.dir/parser.cpp.o
tradutor: CMakeFiles/tradutor.dir/symtable.cpp.o
tradutor: CMakeFiles/tradutor.dir/error.cpp.o
tradutor: CMakeFiles/tradutor.dir/tradutor.cpp.o
tradutor: CMakeFiles/tradutor.dir/build.make
tradutor: CMakeFiles/tradutor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rian/Compiladores/Lab08/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable tradutor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tradutor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tradutor.dir/build: tradutor

.PHONY : CMakeFiles/tradutor.dir/build

CMakeFiles/tradutor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tradutor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tradutor.dir/clean

CMakeFiles/tradutor.dir/depend:
	cd /home/rian/Compiladores/Lab08/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rian/Compiladores/Lab08 /home/rian/Compiladores/Lab08 /home/rian/Compiladores/Lab08/Debug /home/rian/Compiladores/Lab08/Debug /home/rian/Compiladores/Lab08/Debug/CMakeFiles/tradutor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tradutor.dir/depend

