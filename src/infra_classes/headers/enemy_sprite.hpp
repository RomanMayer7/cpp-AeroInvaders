  #pragma once
  #include "bitmap_loop.hpp"
  #include "intersect.hpp"
  //#include <cstdlib> 
  //#include <ctime> 
  #include <random>
  #include <chrono>
  #include "../../managers/game_manager.hpp"

  // Enemy States
  #define STANDBY 0
  #define ATTACK  1
  #define RETREAT 2
  #define LAND 3
  #define EXPLODE 4

  // probability of state transitions
  constexpr double STANDBY_EXIT{0.95};
  constexpr double ATTACK_EXIT{0.95};
  constexpr double RETREAT_EXIT{0.95};
  constexpr double LAND_EXIT{0.95};
  constexpr double FLIP_X{0.9};
  constexpr double RETREAT_Y{17};
  
  //Forward Declare classes
  class EnemyManager;
  class GameManager;
  class PlayerManager;

 class EnemySprite :public BitmapLoop,public Intersect
  {

    int state;
    protected:  
    //Enemy state Image arrays
        //----Refactor Code to use Smart Pointers----
      //  SDL_Texture** normal_images;
      //  SDL_Texture** attack_images;
      //  SDL_Texture** explode_images;
       std::vector<std::shared_ptr<SDL_Texture>> normal_images;
       std::vector<std::shared_ptr<SDL_Texture>> attack_images;
       std::vector<std::shared_ptr<SDL_Texture>> explode_images;
       int explosion_counter;
        //----Refactor Code to use Smart Pointers----
      //EnemyManager* em; 
      std::shared_ptr<EnemyManager> em; 

       int max_x, max_y; // max coords of this Enemy
        //----Refactor Code to use Smart Pointers----
       //inline static Intersect* target; // refers to the player
       inline static std::shared_ptr<Intersect>  target; // refers to the player
       inline static int player_y; // the y-coord of the player
       //----Refactor Code to use Smart Pointers----
       GameManager* game; // ptr to game manager
       //std::shared_ptr<GameManager> game; // ptr to game manager

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
        
        //----Refactor Code to use Smart Pointers----
        // EnemySprite(int x,int y,SDL_Rect _texture_rect,int _num_of_images,
        //  SDL_Texture** enemyImages, SDL_Texture** attackImages,
        //  SDL_Texture** explodeImages, int max_x, int max_y, EnemyManager* _em,GameManager* _gm);
         EnemySprite(int x,int y,SDL_Rect _texture_rect,int _num_of_images,
          std::vector<std::shared_ptr<SDL_Texture>> enemyImages, std::vector<std::shared_ptr<SDL_Texture>> attackImages,
          std::vector<std::shared_ptr<SDL_Texture>> explodeImages, int _max_x, int _max_y,
          std::shared_ptr<EnemyManager> _em,GameManager* _gm/*std::shared_ptr<GameManager> _gm*/);

        EnemySprite();
        
        // finish initializing info about the player's gun
        //----Refactor Code to use Smart Pointers----
        //static void initialize(PlayerManager* pm); 
        static void initialize(std::shared_ptr<PlayerManager> pm);


        // implement Intersect interface:
        bool intersect(int x1, int y1, int x2, int y2);
        // this is called if a missile hits the alien
        void hit();
       // set state and images loop
        void init();
       //this implements the 'State Machine'
        void update();

       static int getRand(int x);
       static double fRand(double fMin, double fMax);

};