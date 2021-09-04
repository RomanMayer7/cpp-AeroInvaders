# CPPND: Capstone "Aero Invaders" Game Example

 Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="Aero_Invaders-demo2.gif"/>

# By RomanMayer7

https://github.com/RomanMayer7

In this project, i am building C++ application , following the principles i have learned throughout this Nanodegree Program.
## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./AeroInvaders`.

## Application code structure

The application consists of the `main()` function and three manager classes,one renderer class and one controller class
Also there are number of infrastructure classes: `Sprite`,`Sprite2D`,`RColor`,`RectSprite`,`BitmapSprite`,`BitmapLoop`
                                                ,`MissleSprite`,`PlayerSprite`,`BitmapSprite`,`EnemySprite`
And two interfaces:`Movable`,`Intersect`

1. `GameManager` : contains main game loop and game logic.it manages instances of two other managers: `PlayerManager` , `EnemyManager`
    Also have instance of `Controller` and `Renderer` classes.
    * Objects: `renderer`, `controller`, `em`, `pm`
    * Getters/Setters/Initializators: `init`
    * Behaviour methods: `incrementScore`, `alienLanded`, `newGame`, `gameOver`, `updateManagers`, `paint`,`run`,`stop`
    
2. `PlayerManager` :  manages the behaviour of Aircraft controlled by Player via `Controller` and renders it via  `Renderer` .
    * Objects: `missile` , `gun` , `renderer` 
    * Getters/Setters/Initializators: `getGunY`, `getGunX`, `getGun`
    * Behaviour methods: `newGame`, `moveGun`, `fireMissile` , `handleHit`, `update` , `paint` 

3. `EnemyManager` : manages the behaviour of Enemy aircrafts controlled by AI and renders them with help of `Renderer` .
    * Objects: `gm`, `pm`, `renderer`, `enemies`
    * Getters/Setters/Initializators: `initialize`, `InitializeManager`, `setStartLevel`, `initializePosition`, `getEnemies`
    * Behaviour methods: `newGame`, `killed`, `paintAll`, `update`

4. `Controller` : is responsible for player's controlls
    * Objects: `player`, `player_manager`
    * Behaviour methods: `HandleInput`

5. `Renderer` : is responsible for rendering game objects such as ,`MissleSprite`,`PlayerSprite`,`EnemySprite`.
    * Objects: `background_texture`, `aircraft_texture`, `enemy_textures`, `enemy_attack_textures`, `enemy_explode_textures`
    * Behaviour methods: `Render`, `UpdateWindowTitle`, `UpdateWindowTitleEndGame`, `loadMedia`, `draw_rectangle`

The `main()` function instantiates an object for each class and then runs the simulation in an infinite loop. The application is run in a single thread. A future implementation could add concurrency, though it's not necessary since the application is plenty fast. 

## Rubric points addressed in the code

1. *The project demonstrates an understanding of C++ functions and control structures:* `missle_sprite.cpp` lines 93-162 is a good example of constrol structures using IF conditions and FOR loops

2. *The project uses Object Oriented Programming techniques:* the project has many infrastructure classes with rich inheritance chains.
 The `EnemySprite` inherits from `BitmapLoop` and implements `Intersect` interface
 The `BitmapLoop`  inherits from `BitmapSprite` and implements `Moveable` interface
 The `BitmapSprite`  inherits from `Sprite2D` which inherits from `Sprite`

3. *Classes use appropriate access specifiers for class members:* The EnemyManager class declaration in `enemy_manager.hpp` shows the use of the `public` (line 13) and `private` (line 67) access specifiers.

4. *Class constructors utilize member initialization lists:* The MissileSprite class constructors on lines 8,23,40 and 57 in `missle_sprite.hpp` use  Initializer Lists.

5. *The project uses smart pointers instead of raw pointers:* lines 46 to 49 in `game_manager.hpp` are a good example of the use of `shared_ptr` for shared class objects.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
