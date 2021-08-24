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


void Controller::HandleInput(bool &running) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        
        case SDLK_SPACE:
                          //std::cout << "SPACE PRESSED.\n";
                          player_manager->fireMissile(player->getLocX());
                          //std::cout << "fireMissile locx:"<<player->getLocX()<<"\n";

        case SDLK_UP:

                           //std::cout << "UUUUUUUUUUUUUUUUUUUUUUUUUu.\n";
                          player_manager->fireMissile(player->getLocX());
                          //std::cout << "fireMissile locx:"<<player->getLocX()<<"\n";
          break;

        case SDLK_DOWN:

                          //std::cout << "DDDDDDDDDDDDDDDDD.\n";
                          player_manager->fireMissile(player->getLocX());
                          //std::cout << "fireMissile locx:"<<player->getLocX()<<"\n";
          break;

        case SDLK_LEFT:

                          //player->setPosition((player->getLocX()-5),player->getLocY());
                          player_manager->moveGun(player->getLocX()-10);
                          player->update();
                          //std::cout<< "Aircraft Position  x: "<<player->getLocX()<<" ,y:"<<player->getLocY()<<std::endl;
          break;

        case SDLK_RIGHT:

                          //player->setPosition((player->getLocX()+5),player->getLocY());
                          player_manager->moveGun(player->getLocX()+10);
                          player->update();
          break;
      }
    }
  }
}