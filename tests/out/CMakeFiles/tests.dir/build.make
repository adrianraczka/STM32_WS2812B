# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/test.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test.cpp.obj: CMakeFiles/tests.dir/includes_CXX.rsp
CMakeFiles/tests.dir/test.cpp.obj: C:/Users/Adrian/Documents/Projects/STM32_WS2812B/tests/test.cpp
CMakeFiles/tests.dir/test.cpp.obj: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/test.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/test.cpp.obj -MF CMakeFiles\tests.dir\test.cpp.obj.d -o CMakeFiles\tests.dir\test.cpp.obj -c C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\test.cpp

CMakeFiles/tests.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\test.cpp > CMakeFiles\tests.dir\test.cpp.i

CMakeFiles/tests.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\test.cpp -o CMakeFiles\tests.dir\test.cpp.s

CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.obj: CMakeFiles/tests.dir/includes_C.rsp
CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.obj: C:/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c
CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.obj: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.obj"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.obj -MF CMakeFiles\tests.dir\C_\Users\Adrian\Documents\Projects\STM32_WS2812B\CubeMX_files\Src\rgb_hsl_hsv.c.obj.d -o CMakeFiles\tests.dir\C_\Users\Adrian\Documents\Projects\STM32_WS2812B\CubeMX_files\Src\rgb_hsl_hsv.c.obj -c C:\Users\Adrian\Documents\Projects\STM32_WS2812B\CubeMX_files\Src\rgb_hsl_hsv.c

CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.i"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Adrian\Documents\Projects\STM32_WS2812B\CubeMX_files\Src\rgb_hsl_hsv.c > CMakeFiles\tests.dir\C_\Users\Adrian\Documents\Projects\STM32_WS2812B\CubeMX_files\Src\rgb_hsl_hsv.c.i

CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.s"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Adrian\Documents\Projects\STM32_WS2812B\CubeMX_files\Src\rgb_hsl_hsv.c -o CMakeFiles\tests.dir\C_\Users\Adrian\Documents\Projects\STM32_WS2812B\CubeMX_files\Src\rgb_hsl_hsv.c.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test.cpp.obj" \
"CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.obj"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests.exe: CMakeFiles/tests.dir/test.cpp.obj
tests.exe: CMakeFiles/tests.dir/C_/Users/Adrian/Documents/Projects/STM32_WS2812B/CubeMX_files/Src/rgb_hsl_hsv.c.obj
tests.exe: CMakeFiles/tests.dir/build.make
tests.exe: Catch2/src/libCatch2Main.a
tests.exe: Catch2/src/libCatch2.a
tests.exe: CMakeFiles/tests.dir/linkLibs.rsp
tests.exe: CMakeFiles/tests.dir/objects1.rsp
tests.exe: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests.exe
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\CMakeFiles\tests.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend

