# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ng\2d-tree-brenscrazy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ng\2d-tree-brenscrazy\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2d_tree_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2d_tree_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2d_tree_lib.dir/flags.make

CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.obj: CMakeFiles/2d_tree_lib.dir/flags.make
CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.obj: CMakeFiles/2d_tree_lib.dir/includes_CXX.rsp
CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.obj: ../src/kdtree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ng\2d-tree-brenscrazy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2d_tree_lib.dir\src\kdtree.cpp.obj -c D:\ng\2d-tree-brenscrazy\src\kdtree.cpp

CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ng\2d-tree-brenscrazy\src\kdtree.cpp > CMakeFiles\2d_tree_lib.dir\src\kdtree.cpp.i

CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ng\2d-tree-brenscrazy\src\kdtree.cpp -o CMakeFiles\2d_tree_lib.dir\src\kdtree.cpp.s

CMakeFiles/2d_tree_lib.dir/src/point.cpp.obj: CMakeFiles/2d_tree_lib.dir/flags.make
CMakeFiles/2d_tree_lib.dir/src/point.cpp.obj: CMakeFiles/2d_tree_lib.dir/includes_CXX.rsp
CMakeFiles/2d_tree_lib.dir/src/point.cpp.obj: ../src/point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ng\2d-tree-brenscrazy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/2d_tree_lib.dir/src/point.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2d_tree_lib.dir\src\point.cpp.obj -c D:\ng\2d-tree-brenscrazy\src\point.cpp

CMakeFiles/2d_tree_lib.dir/src/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2d_tree_lib.dir/src/point.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ng\2d-tree-brenscrazy\src\point.cpp > CMakeFiles\2d_tree_lib.dir\src\point.cpp.i

CMakeFiles/2d_tree_lib.dir/src/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2d_tree_lib.dir/src/point.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ng\2d-tree-brenscrazy\src\point.cpp -o CMakeFiles\2d_tree_lib.dir\src\point.cpp.s

CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.obj: CMakeFiles/2d_tree_lib.dir/flags.make
CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.obj: CMakeFiles/2d_tree_lib.dir/includes_CXX.rsp
CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.obj: ../src/rbtree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ng\2d-tree-brenscrazy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2d_tree_lib.dir\src\rbtree.cpp.obj -c D:\ng\2d-tree-brenscrazy\src\rbtree.cpp

CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ng\2d-tree-brenscrazy\src\rbtree.cpp > CMakeFiles\2d_tree_lib.dir\src\rbtree.cpp.i

CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ng\2d-tree-brenscrazy\src\rbtree.cpp -o CMakeFiles\2d_tree_lib.dir\src\rbtree.cpp.s

CMakeFiles/2d_tree_lib.dir/src/rect.cpp.obj: CMakeFiles/2d_tree_lib.dir/flags.make
CMakeFiles/2d_tree_lib.dir/src/rect.cpp.obj: CMakeFiles/2d_tree_lib.dir/includes_CXX.rsp
CMakeFiles/2d_tree_lib.dir/src/rect.cpp.obj: ../src/rect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ng\2d-tree-brenscrazy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/2d_tree_lib.dir/src/rect.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2d_tree_lib.dir\src\rect.cpp.obj -c D:\ng\2d-tree-brenscrazy\src\rect.cpp

CMakeFiles/2d_tree_lib.dir/src/rect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2d_tree_lib.dir/src/rect.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ng\2d-tree-brenscrazy\src\rect.cpp > CMakeFiles\2d_tree_lib.dir\src\rect.cpp.i

CMakeFiles/2d_tree_lib.dir/src/rect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2d_tree_lib.dir/src/rect.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ng\2d-tree-brenscrazy\src\rect.cpp -o CMakeFiles\2d_tree_lib.dir\src\rect.cpp.s

# Object files for target 2d_tree_lib
2d_tree_lib_OBJECTS = \
"CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.obj" \
"CMakeFiles/2d_tree_lib.dir/src/point.cpp.obj" \
"CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.obj" \
"CMakeFiles/2d_tree_lib.dir/src/rect.cpp.obj"

# External object files for target 2d_tree_lib
2d_tree_lib_EXTERNAL_OBJECTS =

lib2d_tree_lib.a: CMakeFiles/2d_tree_lib.dir/src/kdtree.cpp.obj
lib2d_tree_lib.a: CMakeFiles/2d_tree_lib.dir/src/point.cpp.obj
lib2d_tree_lib.a: CMakeFiles/2d_tree_lib.dir/src/rbtree.cpp.obj
lib2d_tree_lib.a: CMakeFiles/2d_tree_lib.dir/src/rect.cpp.obj
lib2d_tree_lib.a: CMakeFiles/2d_tree_lib.dir/build.make
lib2d_tree_lib.a: CMakeFiles/2d_tree_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ng\2d-tree-brenscrazy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library lib2d_tree_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles\2d_tree_lib.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2d_tree_lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2d_tree_lib.dir/build: lib2d_tree_lib.a

.PHONY : CMakeFiles/2d_tree_lib.dir/build

CMakeFiles/2d_tree_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2d_tree_lib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2d_tree_lib.dir/clean

CMakeFiles/2d_tree_lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ng\2d-tree-brenscrazy D:\ng\2d-tree-brenscrazy D:\ng\2d-tree-brenscrazy\cmake-build-debug D:\ng\2d-tree-brenscrazy\cmake-build-debug D:\ng\2d-tree-brenscrazy\cmake-build-debug\CMakeFiles\2d_tree_lib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2d_tree_lib.dir/depend

