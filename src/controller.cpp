#include "headers/controller.h"
#include <iostream>
#include "SDL.h"


Controller::Controller()
{

}

Controller::Controller(PlayerManager* pm)
{
  player=pm->getGun();
  player_manager =pm;
}

// void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
//                                  Snake::Direction opposite) const {
//   if (snake.direction != opposite || snake.size == 1) snake.direction = input;
//   return;
// }

void Controller::HandleInput(bool &running/*, Snake &snake */) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          //ChangeDirection(snake, Snake::Direction::kUp,
                          //Snake::Direction::kDown);
                           //std::cout << "UUUUUUUUUUUUUUUUUUUUUUUUUu.\n";
          break;

        case SDLK_DOWN:
          //ChangeDirection(snake, Snake::Direction::kDown,
                          //Snake::Direction::kUp);
                          //std::cout << "DDDDDDDDDDDDDDDDD.\n";
                          player_manager->fireMissile(player->getLocX());
                          //std::cout << "fireMissile locx:"<<player->getLocX()<<"\n";
          break;

        case SDLK_LEFT:
          //ChangeDirection(snake, Snake::Direction::kLeft,
                          //Snake::Direction::kRight);
                          player->setPosition((player->getLocX()-5),player->getLocY());
                          //std::cout<< "Aircraft Position  x: "<<player->getLocX()<<" ,y:"<<player->getLocY()<<std::endl;
                          player->update();
                          //std::cout<< "Aircraft Position  x: "<<player->getLocX()<<" ,y:"<<player->getLocY()<<std::endl;
          break;

        case SDLK_RIGHT:
          //ChangeDirection(snake, Snake::Direction::kRight,
                          //Snake::Direction::kLeft);
                          player->setPosition((player->getLocX()+5),player->getLocY());
                          player->update();
          break;
      }
    }
  }
}