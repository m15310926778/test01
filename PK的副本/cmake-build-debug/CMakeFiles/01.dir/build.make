# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Applications/CLion 2.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Applications/CLion 2.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhengxu/CLionProjects/PK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhengxu/CLionProjects/PK/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/01.dir/flags.make

CMakeFiles/01.dir/演讲比赛管理.cpp.o: CMakeFiles/01.dir/flags.make
CMakeFiles/01.dir/演讲比赛管理.cpp.o: ../演讲比赛管理.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhengxu/CLionProjects/PK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/01.dir/演讲比赛管理.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/01.dir/演讲比赛管理.cpp.o -c /Users/zhengxu/CLionProjects/PK/演讲比赛管理.cpp

CMakeFiles/01.dir/演讲比赛管理.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01.dir/演讲比赛管理.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhengxu/CLionProjects/PK/演讲比赛管理.cpp > CMakeFiles/01.dir/演讲比赛管理.cpp.i

CMakeFiles/01.dir/演讲比赛管理.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01.dir/演讲比赛管理.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhengxu/CLionProjects/PK/演讲比赛管理.cpp -o CMakeFiles/01.dir/演讲比赛管理.cpp.s

CMakeFiles/01.dir/speechManager.cpp.o: CMakeFiles/01.dir/flags.make
CMakeFiles/01.dir/speechManager.cpp.o: ../speechManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhengxu/CLionProjects/PK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/01.dir/speechManager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/01.dir/speechManager.cpp.o -c /Users/zhengxu/CLionProjects/PK/speechManager.cpp

CMakeFiles/01.dir/speechManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01.dir/speechManager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhengxu/CLionProjects/PK/speechManager.cpp > CMakeFiles/01.dir/speechManager.cpp.i

CMakeFiles/01.dir/speechManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01.dir/speechManager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhengxu/CLionProjects/PK/speechManager.cpp -o CMakeFiles/01.dir/speechManager.cpp.s

# Object files for target 01
01_OBJECTS = \
"CMakeFiles/01.dir/演讲比赛管理.cpp.o" \
"CMakeFiles/01.dir/speechManager.cpp.o"

# External object files for target 01
01_EXTERNAL_OBJECTS =

01: CMakeFiles/01.dir/演讲比赛管理.cpp.o
01: CMakeFiles/01.dir/speechManager.cpp.o
01: CMakeFiles/01.dir/build.make
01: CMakeFiles/01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhengxu/CLionProjects/PK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/01.dir/build: 01

.PHONY : CMakeFiles/01.dir/build

CMakeFiles/01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/01.dir/clean

CMakeFiles/01.dir/depend:
	cd /Users/zhengxu/CLionProjects/PK/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhengxu/CLionProjects/PK /Users/zhengxu/CLionProjects/PK /Users/zhengxu/CLionProjects/PK/cmake-build-debug /Users/zhengxu/CLionProjects/PK/cmake-build-debug /Users/zhengxu/CLionProjects/PK/cmake-build-debug/CMakeFiles/01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/01.dir/depend

