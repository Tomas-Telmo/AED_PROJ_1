# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /snap/clion/250/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/250/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projeto_AED_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Projeto_AED_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Projeto_AED_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projeto_AED_1.dir/flags.make

CMakeFiles/Projeto_AED_1.dir/main.cpp.o: CMakeFiles/Projeto_AED_1.dir/flags.make
CMakeFiles/Projeto_AED_1.dir/main.cpp.o: /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/main.cpp
CMakeFiles/Projeto_AED_1.dir/main.cpp.o: CMakeFiles/Projeto_AED_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projeto_AED_1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto_AED_1.dir/main.cpp.o -MF CMakeFiles/Projeto_AED_1.dir/main.cpp.o.d -o CMakeFiles/Projeto_AED_1.dir/main.cpp.o -c /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/main.cpp

CMakeFiles/Projeto_AED_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto_AED_1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/main.cpp > CMakeFiles/Projeto_AED_1.dir/main.cpp.i

CMakeFiles/Projeto_AED_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto_AED_1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/main.cpp -o CMakeFiles/Projeto_AED_1.dir/main.cpp.s

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.o: CMakeFiles/Projeto_AED_1.dir/flags.make
CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.o: /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule\ Classes/Student.cpp
CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.o: CMakeFiles/Projeto_AED_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.o -MF CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.o.d -o CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.o -c "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/Student.cpp"

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/Student.cpp" > CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.i

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/Student.cpp" -o CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.s

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.o: CMakeFiles/Projeto_AED_1.dir/flags.make
CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.o: /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule\ Classes/StudentClass.cpp
CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.o: CMakeFiles/Projeto_AED_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.o -MF CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.o.d -o CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.o -c "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/StudentClass.cpp"

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/StudentClass.cpp" > CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.i

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/StudentClass.cpp" -o CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.s

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.o: CMakeFiles/Projeto_AED_1.dir/flags.make
CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.o: /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule\ Classes/UC.cpp
CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.o: CMakeFiles/Projeto_AED_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.o -MF CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.o.d -o CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.o -c "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/UC.cpp"

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/UC.cpp" > CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.i

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/UC.cpp" -o CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.s

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.o: CMakeFiles/Projeto_AED_1.dir/flags.make
CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.o: /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule\ Classes/Class.cpp
CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.o: CMakeFiles/Projeto_AED_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.o -MF CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.o.d -o CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.o -c "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/Class.cpp"

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/Class.cpp" > CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.i

CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/Class.cpp" -o CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.s

# Object files for target Projeto_AED_1
Projeto_AED_1_OBJECTS = \
"CMakeFiles/Projeto_AED_1.dir/main.cpp.o" \
"CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.o" \
"CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.o" \
"CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.o" \
"CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.o"

# External object files for target Projeto_AED_1
Projeto_AED_1_EXTERNAL_OBJECTS =

Projeto_AED_1: CMakeFiles/Projeto_AED_1.dir/main.cpp.o
Projeto_AED_1: CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Student.cpp.o
Projeto_AED_1: CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/StudentClass.cpp.o
Projeto_AED_1: CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/UC.cpp.o
Projeto_AED_1: CMakeFiles/Projeto_AED_1.dir/Schedule_Classes/Class.cpp.o
Projeto_AED_1: CMakeFiles/Projeto_AED_1.dir/build.make
Projeto_AED_1: CMakeFiles/Projeto_AED_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Projeto_AED_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projeto_AED_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projeto_AED_1.dir/build: Projeto_AED_1
.PHONY : CMakeFiles/Projeto_AED_1.dir/build

CMakeFiles/Projeto_AED_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projeto_AED_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projeto_AED_1.dir/clean

CMakeFiles/Projeto_AED_1.dir/depend:
	cd /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug /home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/cmake-build-debug/CMakeFiles/Projeto_AED_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projeto_AED_1.dir/depend
