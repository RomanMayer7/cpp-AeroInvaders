# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/cmake/918/bin/cmake

# The command to remove a file.
RM = /snap/cmake/918/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build

# Include any dependencies generated for this target.
include CMakeFiles/SnakeGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SnakeGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SnakeGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SnakeGame.dir/flags.make

CMakeFiles/SnakeGame.dir/src/main.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/SnakeGame.dir/src/main.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SnakeGame.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/main.cpp.o -MF CMakeFiles/SnakeGame.dir/src/main.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/main.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/main.cpp

CMakeFiles/SnakeGame.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/main.cpp > CMakeFiles/SnakeGame.dir/src/main.cpp.i

CMakeFiles/SnakeGame.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/main.cpp -o CMakeFiles/SnakeGame.dir/src/main.cpp.s

CMakeFiles/SnakeGame.dir/src/game.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/game.cpp.o: ../src/game.cpp
CMakeFiles/SnakeGame.dir/src/game.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SnakeGame.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/game.cpp.o -MF CMakeFiles/SnakeGame.dir/src/game.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/game.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/game.cpp

CMakeFiles/SnakeGame.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/game.cpp > CMakeFiles/SnakeGame.dir/src/game.cpp.i

CMakeFiles/SnakeGame.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/game.cpp -o CMakeFiles/SnakeGame.dir/src/game.cpp.s

CMakeFiles/SnakeGame.dir/src/controller.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/controller.cpp.o: ../src/controller.cpp
CMakeFiles/SnakeGame.dir/src/controller.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SnakeGame.dir/src/controller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/controller.cpp.o -MF CMakeFiles/SnakeGame.dir/src/controller.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/controller.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/controller.cpp

CMakeFiles/SnakeGame.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/controller.cpp > CMakeFiles/SnakeGame.dir/src/controller.cpp.i

CMakeFiles/SnakeGame.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/controller.cpp -o CMakeFiles/SnakeGame.dir/src/controller.cpp.s

CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.o: ../src/infra_classes/rect_sprite.cpp
CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.o -MF CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/rect_sprite.cpp

CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/rect_sprite.cpp > CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.i

CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/rect_sprite.cpp -o CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.s

CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.o: ../src/infra_classes/bitmap_sprite.cpp
CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.o -MF CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/bitmap_sprite.cpp

CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/bitmap_sprite.cpp > CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.i

CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/bitmap_sprite.cpp -o CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.s

CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.o: ../src/infra_classes/missle_sprite.cpp
CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.o -MF CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/missle_sprite.cpp

CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/missle_sprite.cpp > CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.i

CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/missle_sprite.cpp -o CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.s

CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.o: ../src/infra_classes/rcolor.cpp
CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.o -MF CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/rcolor.cpp

CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/rcolor.cpp > CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.i

CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/rcolor.cpp -o CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.s

CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.o: ../src/infra_classes/player_sprite.cpp
CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.o -MF CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/player_sprite.cpp

CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/player_sprite.cpp > CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.i

CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/infra_classes/player_sprite.cpp -o CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.s

CMakeFiles/SnakeGame.dir/src/renderer.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/renderer.cpp.o: ../src/renderer.cpp
CMakeFiles/SnakeGame.dir/src/renderer.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SnakeGame.dir/src/renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/renderer.cpp.o -MF CMakeFiles/SnakeGame.dir/src/renderer.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/renderer.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/renderer.cpp

CMakeFiles/SnakeGame.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/renderer.cpp > CMakeFiles/SnakeGame.dir/src/renderer.cpp.i

CMakeFiles/SnakeGame.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/renderer.cpp -o CMakeFiles/SnakeGame.dir/src/renderer.cpp.s

CMakeFiles/SnakeGame.dir/src/snake.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/src/snake.cpp.o: ../src/snake.cpp
CMakeFiles/SnakeGame.dir/src/snake.cpp.o: CMakeFiles/SnakeGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SnakeGame.dir/src/snake.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnakeGame.dir/src/snake.cpp.o -MF CMakeFiles/SnakeGame.dir/src/snake.cpp.o.d -o CMakeFiles/SnakeGame.dir/src/snake.cpp.o -c /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/snake.cpp

CMakeFiles/SnakeGame.dir/src/snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/src/snake.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/snake.cpp > CMakeFiles/SnakeGame.dir/src/snake.cpp.i

CMakeFiles/SnakeGame.dir/src/snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/src/snake.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/src/snake.cpp -o CMakeFiles/SnakeGame.dir/src/snake.cpp.s

# Object files for target SnakeGame
SnakeGame_OBJECTS = \
"CMakeFiles/SnakeGame.dir/src/main.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/game.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/controller.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/renderer.cpp.o" \
"CMakeFiles/SnakeGame.dir/src/snake.cpp.o"

# External object files for target SnakeGame
SnakeGame_EXTERNAL_OBJECTS =

SnakeGame: CMakeFiles/SnakeGame.dir/src/main.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/game.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/controller.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/infra_classes/rect_sprite.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/infra_classes/bitmap_sprite.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/infra_classes/missle_sprite.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/infra_classes/rcolor.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/infra_classes/player_sprite.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/renderer.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/src/snake.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/build.make
SnakeGame: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
SnakeGame: CMakeFiles/SnakeGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable SnakeGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SnakeGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SnakeGame.dir/build: SnakeGame
.PHONY : CMakeFiles/SnakeGame.dir/build

CMakeFiles/SnakeGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SnakeGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SnakeGame.dir/clean

CMakeFiles/SnakeGame.dir/depend:
	cd /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build /home/romanmay/Development/CPP_Projects/CPP-Aero-Invaders/build/CMakeFiles/SnakeGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SnakeGame.dir/depend
