#include <iostream>
#include "headers/controller.h"
#include "managers/game_manager.hpp"




int main() {
  //constexpr std::size_t kFramesPerSecond{80};
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{1000};
  constexpr std::size_t kScreenHeight{750};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  //CREATE RENDERER INSTANCE
  Renderer* renderer=new Renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  //Load Media
 //renderer.loadMedia();
  //PlayerSprite* ps = renderer.aircraftSprite_three;
  //Controller controller(ps);
  
  GameManager game_manager(kScreenWidth, kScreenHeight,renderer,kMsPerFrame);
  game_manager.init();
  game_manager.newGame();
  game_manager.run();

  //Game game(kGridWidth, kGridHeight);
  //game.Run(controller, renderer, kMsPerFrame);

  std::cout << "Game has terminated successfully!\n";
  //std::cout << "Score: " << game.GetScore() << "\n";
  //std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}