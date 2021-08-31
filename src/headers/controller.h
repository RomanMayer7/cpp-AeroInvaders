#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../infra_classes/headers/player_sprite.hpp"
#include "../managers/player_manager.hpp"
#include<memory>

class PlayerManager;

class Controller {
 public:
  Controller();
  //----Refactor Code to use Smart Pointers----
  //Controller(PlayerManager *pm);
  Controller( std::shared_ptr<PlayerManager> pm);

  void HandleInput(bool &running/*, Snake &snake*/) const;

  //----Refactor Code to use Smart Pointers----
  /* PlayerSprite* player;
     PlayerManager* player_manager;
  */
  std::shared_ptr<PlayerSprite> player;
  std::shared_ptr<PlayerManager> player_manager;
  

 private:
  //void ChangeDirection(Snake &snake, Snake::Direction input,
                       //Snake::Direction opposite) const;
};

#endif