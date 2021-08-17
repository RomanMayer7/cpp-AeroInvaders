 
 #pragma once
 
 #include "../infra_classes/headers/player_sprite.hpp"
 #include "../infra_classes/headers/missle_sprite.hpp"
 #include "../infra_classes/headers/rect_sprite.hpp"
 #include "../infra_classes/headers/enemy_sprite.hpp"
 #include "../headers/renderer.h"


#define MISSILE_WIDTH 5
#define MISSILE_HEIGHT 27
#define MISSILE_SPEED -27// missile flies upward
 
 class MissileSprite;
 class EnemySprite;

 class PlayerManager {

  private:

   PlayerSprite* gun; // player's gun/aircraft
   Renderer* renderer;
   int gun_width; // width of gun
   int gun_height;
   
    MissileSprite* missile[3];
   //MissileSprite missile[3];// = new MissileSprite[3]; // missile
  

   /*static */int width, height; // game window  dimensions
   //static GameManager game;
   int min_x, max_x; // min and max x coords

  // for player's sprite movement
   int gun_min_x, gun_max_x;
   int mis_min_x, mis_max_x;
   int gun_y;
   std::string energyString = "Energy";
   bool displayHit;
   int energy;
   int maxEnergy;
   int energyDec;
   RColor* MISSILE_COLOR; //Red Color by Default

  //AudioClip shotsound;
  public:

   PlayerManager(int _maxEnergy, int _energyDec, int _windowWidth, int _windowHeight,Renderer* _renderer,Intersect** target
                    /* ,Intersect** target2*/ );


   PlayerManager(int _maxEnergy, int _energyDec, int _windowWidth, int _windowHeight,Renderer* _renderer,EnemySprite** target
                    /* ,Intersect** target2*/ );
    
   void newGame();
  // move gun to the given x coordinate
   void moveGun(int x);
  // Fire Missile from given x coordinate
   void fireMissile(int x); 
  // handles a hit from an enemy
   void handleHit();
   void update();

  // Paint all sprites associated with gun
  // also paint status display for amount of energy left
   void paint(Renderer* g);
  // accessor method for player's sprite instance
   PlayerSprite* getGun();
   int getGunY();
   int getGunX();
   void setEnergyDec(int _energyDec);
   
};