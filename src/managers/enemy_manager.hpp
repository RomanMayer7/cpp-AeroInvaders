#pragma once
#include "../headers/renderer.h"
#include "../infra_classes/headers/enemy_sprite.hpp"
#include <memory>

//Forward Declare classes
class GameManager;
class PlayerManager;
class EnemySprite;

class EnemyManager :public std::enable_shared_from_this<EnemyManager>
{
  public:
  int width, height; // GAME WINDOW dimensions


  int enemiesKilled; // counter of enemies killed
  int level; 

  //----Refactor Code to use Smart Pointers----
  // Renderer* renderer;
  // PlayerManager* pm;
   GameManager* _gm;
  std::shared_ptr<Renderer> renderer;
  std::shared_ptr<PlayerManager> pm;
  //std::shared_ptr<GameManager> _gm;

  int startLevel;
  int maxLevel;
   // kill 13 ufos to reach the next level
  static constexpr int KILL_FOR_NEXT_LEVEL=13;
  static constexpr int NUM_OF_ENEMIES= 9;
  bool playSound = false;
  
    //----Refactor Code to use Smart Pointers----
  //EnemyManager(int _startLevel, int _maxLevel, int _width, int _height,Renderer* _renderer,GameManager* gm);
  EnemyManager(int _startLevel, int _maxLevel, int _width, int _height,std::shared_ptr<Renderer> _renderer,GameManager* gm/*std::shared_ptr<GameManager> gm*/);

   // allow the EnemyManager class to communicate with the PlayerManger
   //----Refactor Code to use Smart Pointers----
   //void initialize(PlayerManager* pm);
   void initialize(std::shared_ptr<PlayerManager> pm);
   void InitializeManager();
  
  // accessor method, so the missile knows where the targets are!
  //----Refactor Code to use Smart Pointers----
  //EnemySprite** getEnemies();
  std::vector<std::shared_ptr<EnemySprite>> getEnemies();

  // This method tells the EnemySprite class where
  // the PlayerSprite is (so the EnemySprites know if they’ve collided with it)
   void newGame();

  // tracks the number  of ufos killed. If the
  // num_killed is divisible by KILL_FOR_NEXT_LEVEL - increment the level
   void killed();

   void setStartLevel(int start);
   void setSound(bool s);
   void playExplosion();
  // paint all enemies in a level
   void paintAll();

  // update all enemies in a level. Otherwise initiate an enemy if it's not on screen
   void update();
     
   private:
      //Group of Enemies
      //----Refactor Code to use Smart Pointers----
      //EnemySprite** enemies;
      std::vector<std::shared_ptr<EnemySprite>> enemies;

      //----Refactor Code to use Smart Pointers----
      // set enemy at a random screen location
      // void initializePosition(Moveable* m);
      void initializePosition(std::shared_ptr<Moveable> m);


};