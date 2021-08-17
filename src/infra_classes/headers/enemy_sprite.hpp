  #pragma once
  #include "bitmap_loop.hpp"
  #include "intersect.hpp"
  #include "../../managers/game_manager.hpp"
  #include "../../managers/enemy_manager.hpp"
  #include <cstdlib> 
  #include <ctime> 

  // Enemy States
  #define STANDBY 0
  #define ATTACK = 1;
  #define RETREAT = 2;
  #define LAND = 3;
  #define EXPLODE = 4;

  // probability of state transitions
  constexpr double STANDBY_EXIT{0.95};
  constexpr double ATTACK_EXIT{0.95};
  constexpr double RETREAT_EXIT{0.95};
  constexpr double LAND_EXIT{0.95};
  constexpr double FLIP_X{0.9};
  constexpr double RETREAT_Y{17};
  

 class EnemySprite :BitmapLoop,Intersect
  {

    int state;
    protected:  
    //Enemy state Image arrays
       
       SDL_Texture** normal_images;
       SDL_Texture** attack_images;
       SDL_Texture** explode_images;
       int explosion_counter;
       EnemyManager* em;  

       int max_x, max_y; // max coords of this Enemy
       Intersect* target; // refers to the player
       int player_y; // the y-coord of the player
       GameManager* game; // ptr to game manager 

       void landingRoutine();
       void startStandby();
      // start attack state
       void startAttack();
      // start retreating state
       void startRetreat();
       // start landing state
       void startLand();
      // start explosion state
       void startExplode();

       public:

        EnemySprite(int x,int y,SDL_Rect _texture_rect,int _num_of_images,
         SDL_Texture** enemyImages, SDL_Texture** attackImages,
         SDL_Texture** explodeImages, int max_x, int max_y, EnemyManager _em,GameManager _gm);

        EnemySprite() {}
        
        // finish initializing info about the player's gun
        void initialize(PlayerManager* pm); 
        // implement Intersect interface:
        bool intersect(int x1, int y1, int x2, int y2);
        // this is called if a missile hits the alien
        void hit();
       // set state and images loop
        void init();
       //this implements the 'State Machine'
        void update();

       int getRand(int x);
       double fRand(double fMin, double fMax);

};