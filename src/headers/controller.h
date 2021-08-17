#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../infra_classes/headers/player_sprite.hpp"
#include "../managers/player_manager.hpp"

class PlayerManager;

class Controller {
 public:
  Controller();
  Controller(PlayerManager *pm);
  void HandleInput(bool &running/*, Snake &snake*/) const;
  PlayerSprite* player;
  PlayerManager* player_manager;

 private:
  //void ChangeDirection(Snake &snake, Snake::Direction input,
                       //Snake::Direction opposite) const;
};

#endif