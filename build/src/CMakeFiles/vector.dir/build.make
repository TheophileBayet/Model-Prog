# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build

# Include any dependencies generated for this target.
include src/CMakeFiles/vector.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/vector.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/vector.dir/flags.make

src/CMakeFiles/vector.dir/Dvector.cpp.o: src/CMakeFiles/vector.dir/flags.make
src/CMakeFiles/vector.dir/Dvector.cpp.o: ../src/Dvector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/vector.dir/Dvector.cpp.o"
	cd /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vector.dir/Dvector.cpp.o -c /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/src/Dvector.cpp

src/CMakeFiles/vector.dir/Dvector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector.dir/Dvector.cpp.i"
	cd /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/src/Dvector.cpp > CMakeFiles/vector.dir/Dvector.cpp.i

src/CMakeFiles/vector.dir/Dvector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector.dir/Dvector.cpp.s"
	cd /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/src/Dvector.cpp -o CMakeFiles/vector.dir/Dvector.cpp.s

src/CMakeFiles/vector.dir/Dvector.cpp.o.requires:
.PHONY : src/CMakeFiles/vector.dir/Dvector.cpp.o.requires

src/CMakeFiles/vector.dir/Dvector.cpp.o.provides: src/CMakeFiles/vector.dir/Dvector.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/vector.dir/build.make src/CMakeFiles/vector.dir/Dvector.cpp.o.provides.build
.PHONY : src/CMakeFiles/vector.dir/Dvector.cpp.o.provides

src/CMakeFiles/vector.dir/Dvector.cpp.o.provides.build: src/CMakeFiles/vector.dir/Dvector.cpp.o

# Object files for target vector
vector_OBJECTS = \
"CMakeFiles/vector.dir/Dvector.cpp.o"

# External object files for target vector
vector_EXTERNAL_OBJECTS =

src/lib/libvector.so: src/CMakeFiles/vector.dir/Dvector.cpp.o
src/lib/libvector.so: src/CMakeFiles/vector.dir/build.make
src/lib/libvector.so: src/CMakeFiles/vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library lib/libvector.so"
	cd /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/vector.dir/build: src/lib/libvector.so
.PHONY : src/CMakeFiles/vector.dir/build

src/CMakeFiles/vector.dir/requires: src/CMakeFiles/vector.dir/Dvector.cpp.o.requires
.PHONY : src/CMakeFiles/vector.dir/requires

src/CMakeFiles/vector.dir/clean:
	cd /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/src && $(CMAKE_COMMAND) -P CMakeFiles/vector.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/vector.dir/clean

src/CMakeFiles/vector.dir/depend:
	cd /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/src /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/src /user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/src/CMakeFiles/vector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/vector.dir/depend

