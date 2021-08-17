#pragma once
#include "../headers/renderer.h"
#include "../infra_classes/headers/enemy_sprite.hpp"

//Forward Declare classes
class GameManager;
class PlayerManager;
class EnemySprite;

class EnemyManager
{
  public:
  int width, height; // GAME WINDOW dimensions


  int enemiesKilled; // counter of enemies killed
  int level; 
  Renderer* renderer;
  PlayerManager* pm;
  GameManager* _gm;
  int startLevel;
  int maxLevel;
   // kill 13 ufos to reach the next level
  static constexpr int KILL_FOR_NEXT_LEVEL=13;
  static constexpr int NUM_OF_ENEMIES= 9;
  bool playSound = false;
  
  EnemyManager(int _startLevel, int _maxLevel, int _width, int _height,Renderer* _renderer,GameManager* gm);

   // allow the EnemyManager class to communicate with the PlayerManger
   void initialize(PlayerManager* pm);   
  // accessor method, so the missile knows where
  // the targets are!
   EnemySprite** getEnemies();

  // This method tells the EnemySprite class where
  // the PlayerSprite is (so the EnemySprites know if they’ve
  // collided with it)
   void newGame();
  // tracks the number of ufos killed. If the
  // num_killed is divisible by KILL_FOR_NEXT_LEVEL
  // increment the level
   void killed();

   void setStartLevel(int start);
   void setSound(bool s);
   void playExplosion();
  // paint all enemies in a level
   void paintAll();

  // update all ufos in a level. Otherwise start
  // ufo if it's not on screen
   void update();
     
   private:
      //Group of Enemies
      EnemySprite** enemies;
      
      // set ufo at a random screen location
      void initializePosition(Moveable* m);

};