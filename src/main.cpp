#include <iostream>
#include "headers/controller.h"
#include "managers/game_manager.hpp"
#include <memory>



int main() {
  //constexpr std::size_t kFramesPerSecond{80};
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{1000};
  constexpr std::size_t kScreenHeight{750};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  //CREATE RENDERER INSTANCE
  //----Refactor Code to use Smart Pointers----
  //Renderer* renderer=new Renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  std::shared_ptr<Renderer> renderer = std::make_shared<Renderer> (kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  

   GameManager game_manager(kScreenWidth, kScreenHeight,renderer,kMsPerFrame);
   game_manager.init();
   game_manager.newGame();
   game_manager.run();

  std::cout << "Game has terminated successfully!\n";

  return 0;
}