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
include Catch2/src/CMakeFiles/Catch2WithMain.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Catch2/src/CMakeFiles/Catch2WithMain.dir/compiler_depend.make

# Include the progress variables for this target.
include Catch2/src/CMakeFiles/Catch2WithMain.dir/progress.make

# Include the compile flags for this target's objects.
include Catch2/src/CMakeFiles/Catch2WithMain.dir/flags.make

Catch2/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.obj: Catch2/src/CMakeFiles/Catch2WithMain.dir/flags.make
Catch2/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.obj: Catch2/src/CMakeFiles/Catch2WithMain.dir/includes_CXX.rsp
Catch2/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.obj: C:/Users/Adrian/Documents/Projects/STM32_WS2812B/tests/Catch2/src/catch2/internal/catch_main.cpp
Catch2/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.obj: Catch2/src/CMakeFiles/Catch2WithMain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Catch2/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.obj"
	cd /d C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\Catch2\src && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Catch2/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.obj -MF CMakeFiles\Catch2WithMain.dir\catch2\internal\catch_main.cpp.obj.d -o CMakeFiles\Catch2WithMain.dir\catch2\internal\catch_main.cpp.obj -c C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\Catch2\src\catch2\internal\catch_main.cpp

Catch2/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.i"
	cd /d C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\Catch2\src && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\Catch2\src\catch2\internal\catch_main.cpp > CMakeFiles\Catch2WithMain.dir\catch2\internal\catch_main.cpp.i

Catch2/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.s"
	cd /d C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\Catch2\src && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\Catch2\src\catch2\internal\catch_main.cpp -o CMakeFiles\Catch2WithMain.dir\catch2\internal\catch_main.cpp.s

# Object files for target Catch2WithMain
Catch2WithMain_OBJECTS = \
"CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.obj"

# External object files for target Catch2WithMain
Catch2WithMain_EXTERNAL_OBJECTS =

Catch2/src/libCatch2Main.a: Catch2/src/CMakeFiles/Catch2WithMain.dir/catch2/internal/catch_main.cpp.obj
Catch2/src/libCatch2Main.a: Catch2/src/CMakeFiles/Catch2WithMain.dir/build.make
Catch2/src/libCatch2Main.a: Catch2/src/CMakeFiles/Catch2WithMain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCatch2Main.a"
	cd /d C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\Catch2\src && $(CMAKE_COMMAND) -P CMakeFiles\Catch2WithMain.dir\cmake_clean_target.cmake
	cd /d C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\Catch2\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Catch2WithMain.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Catch2/src/CMakeFiles/Catch2WithMain.dir/build: Catch2/src/libCatch2Main.a
.PHONY : Catch2/src/CMakeFiles/Catch2WithMain.dir/build

Catch2/src/CMakeFiles/Catch2WithMain.dir/clean:
	cd /d C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\Catch2\src && $(CMAKE_COMMAND) -P CMakeFiles\Catch2WithMain.dir\cmake_clean.cmake
.PHONY : Catch2/src/CMakeFiles/Catch2WithMain.dir/clean

Catch2/src/CMakeFiles/Catch2WithMain.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\Catch2\src C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\Catch2\src C:\Users\Adrian\Documents\Projects\STM32_WS2812B\tests\out\Catch2\src\CMakeFiles\Catch2WithMain.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Catch2/src/CMakeFiles/Catch2WithMain.dir/depend

