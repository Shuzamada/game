# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /home/sembi/.local/bin/cmake

# The command to remove a file.
RM = /home/sembi/.local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sembi/Arduino/tetris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sembi/Arduino/tetris

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/sembi/.local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/home/sembi/.local/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/sembi/Arduino/tetris/CMakeFiles /home/sembi/Arduino/tetris//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/sembi/Arduino/tetris/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -P /home/sembi/Arduino/tetris/CMakeFiles/VerifyGlobs.cmake
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named run

# Build rule for target.
run: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 run
.PHONY : run

# fast build rule for target.
run/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/build
.PHONY : run/fast

#=============================================================================
# Target rules for targets named MySFMLProject

# Build rule for target.
MySFMLProject: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MySFMLProject
.PHONY : MySFMLProject

# fast build rule for target.
MySFMLProject/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/build
.PHONY : MySFMLProject/fast

src/Slider-SFML/SliderSFML.o: src/Slider-SFML/SliderSFML.cpp.o

.PHONY : src/Slider-SFML/SliderSFML.o

# target to build an object file
src/Slider-SFML/SliderSFML.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/src/Slider-SFML/SliderSFML.cpp.o
.PHONY : src/Slider-SFML/SliderSFML.cpp.o

src/Slider-SFML/SliderSFML.i: src/Slider-SFML/SliderSFML.cpp.i

.PHONY : src/Slider-SFML/SliderSFML.i

# target to preprocess a source file
src/Slider-SFML/SliderSFML.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/src/Slider-SFML/SliderSFML.cpp.i
.PHONY : src/Slider-SFML/SliderSFML.cpp.i

src/Slider-SFML/SliderSFML.s: src/Slider-SFML/SliderSFML.cpp.s

.PHONY : src/Slider-SFML/SliderSFML.s

# target to generate assembly for a file
src/Slider-SFML/SliderSFML.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/src/Slider-SFML/SliderSFML.cpp.s
.PHONY : src/Slider-SFML/SliderSFML.cpp.s

src/field.o: src/field.cpp.o

.PHONY : src/field.o

# target to build an object file
src/field.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/src/field.cpp.o
.PHONY : src/field.cpp.o

src/field.i: src/field.cpp.i

.PHONY : src/field.i

# target to preprocess a source file
src/field.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/src/field.cpp.i
.PHONY : src/field.cpp.i

src/field.s: src/field.cpp.s

.PHONY : src/field.s

# target to generate assembly for a file
src/field.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/src/field.cpp.s
.PHONY : src/field.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MySFMLProject.dir/build.make CMakeFiles/MySFMLProject.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... run"
	@echo "... MySFMLProject"
	@echo "... src/Slider-SFML/SliderSFML.o"
	@echo "... src/Slider-SFML/SliderSFML.i"
	@echo "... src/Slider-SFML/SliderSFML.s"
	@echo "... src/field.o"
	@echo "... src/field.i"
	@echo "... src/field.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -P /home/sembi/Arduino/tetris/CMakeFiles/VerifyGlobs.cmake
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

