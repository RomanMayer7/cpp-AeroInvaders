cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)
include_directories(${SDL2_IMAGE_INCLUDE_DIR} src)
include_directories(${PROJECT_SOURCE_DIR}/src/headers)
include_directories(${PROJECT_SOURCE_DIR}/src/infra_classes/headers)
include_directories(${PROJECT_SOURCE_DIR}/src/infra_classes/)
link_directories(${PROJECT_SOURCE_DIR}/src/infra_classes/)

add_executable(AeroInvadersGame src/main.cpp src/managers/game_manager.hpp src/managers/player_manager.hpp src/controller.cpp src/infra_classes/rect_sprite.cpp src/infra_classes/bitmap_sprite.cpp src/infra_classes/missle_sprite.cpp src/infra_classes/rcolor.cpp src/infra_classes/player_sprite.cpp src/renderer.cpp )

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(AeroInvadersGame ${SDL2_LIBRARIES}
                          ${SDL2_IMAGE_LIBRARIES})
