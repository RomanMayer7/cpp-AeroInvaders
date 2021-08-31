#include "enemy_manager.hpp"

//----Refactor Code to use Smart Pointers----
//EnemyManager::EnemyManager(int _startLevel, int _maxLevel, int _width, int _height,Renderer* _renderer,GameManager* gm)
 EnemyManager::EnemyManager(int _startLevel, int _maxLevel, int _width, int _height,std::shared_ptr<Renderer> _renderer,GameManager* gm/*std::shared_ptr<GameManager> gm*/)
     {
         width = _width;
         height = _height;
         renderer=_renderer;
         startLevel = _startLevel;
         maxLevel = maxLevel;
         _gm=gm;
        
        std::cout << " ctor in EnemyManager().\n";
       

     }

      void EnemyManager::InitializeManager()
     {
        //----Refactor Code to use Smart Pointers----
        //enemies= new EnemySprite *[NUM_OF_ENEMIES];
          std::cout << "enemy textures vector size: " << renderer->enemy_textures.size() << '\n';
           std::cout << "enemy_attack_textures vector size: " << renderer->enemy_attack_textures.size() << '\n';
            std::cout << "enemy_explode_textures vector size: " << renderer->enemy_explode_textures.size() << '\n';
        for (int i = 0; i < NUM_OF_ENEMIES; i++) 
        {
          //  enemies[i] = new EnemySprite( 70*i,60*i,renderer->texture_rect, 6,renderer->enemy_textures,
          //                                    renderer->enemy_attack_textures,renderer->enemy_explode_textures 
          //                                    ,width, height, this,_gm);
          
              enemies.emplace_back(std::make_shared<EnemySprite>( 70*i,60*i,renderer->texture_rect, 6,renderer->enemy_textures,
                                             renderer->enemy_attack_textures,renderer->enemy_explode_textures 
                                             ,width, height,shared_from_this(),_gm));

                                             
        }
        _gm->currentLevel=startLevel;

     }

   // allow the EnemyManager class to communicate with the PlayerManger
   //----Refactor Code to use Smart Pointers----
   //void EnemyManager::initialize(PlayerManager* pm)
     void EnemyManager::initialize(std::shared_ptr<PlayerManager> pm)
      {
        EnemySprite::initialize(pm);
      }
    
  // accessor method, so the missile knows where the targets are!
    //----Refactor Code to use Smart Pointers----
   //EnemySprite** EnemyManager::getEnemies()
    std::vector<std::shared_ptr<EnemySprite>> EnemyManager::getEnemies()
    {
      return enemies;
    }

  // This method tells the EnemySprite class where the PlayerSprite is 
  //(so the EnemySprites know if they’ve collided with it)
   void EnemyManager::newGame() 
  {
     std::cout << " EnemyManager()::newGame.\n";
    enemiesKilled = 0;
    level = startLevel; // start with 2 enemies
    // on the screen
    for (int i = 0; i < NUM_OF_ENEMIES; i++) {
      initializePosition(enemies[i]);
      enemies[i]->init(); //?
      if (i >= level) { // suspend enemies above the start level
        enemies[i]->suspend();

      }
    }
  }
  // tracks the number of enemies killed. If the
  // num_killed is divisible by KILL_FOR_NEXT_LEVEL - increment the level
   void EnemyManager::killed() 
   {
    enemiesKilled++;
    if (enemiesKilled % KILL_FOR_NEXT_LEVEL == 0) {
      level = (level == NUM_OF_ENEMIES) ? NUM_OF_ENEMIES : level + 1;
      _gm->currentLevel=level;
    }
  }

   void EnemyManager::setStartLevel(int start)
   {
    startLevel = start;
   }

   void EnemyManager::setSound(bool s)
    {
      playSound = s;
    }

   void EnemyManager::playExplosion() {}

  // paint all enemies in a level
   void EnemyManager::paintAll() 
   {

    for (int i = 0; i < level; i++)
     {
      enemies[i]->paint_g(renderer->background_renderer);
     }
  }

  // update all enemie in a level. Otherwise initiate an enemy if it's not on screen
   void EnemyManager::update() 
   {
    
    for (int i = 0; i < level; i++) 
    {
      if (enemies[i]->isActive()) 
      {
        //std::cout<<"Update Enemy:"<< i<<std::endl;
        enemies[i]->update();
      } 
      else 
      { // make new enemy
       std::cout<<"Make new Enemy"<<std::endl;
         initializePosition(enemies[i]);
         enemies[i]->init();
         enemies[i]->finalizing=false;
      }
    }
  }
     
  // set enemy at a random screen location
  //----Refactor Code to use Smart Pointers----
  //void EnemyManager::initializePosition(Moveable* m)
  void EnemyManager::initializePosition(std::shared_ptr<Moveable> m) 
      {
          int random1=EnemySprite::getRand(width - 100) + 50;
          int random2=EnemySprite::getRand(height - 150) + 10;
              std::cout<<"Random x: "<< random1<<std::endl;
               std::cout<<"Random y: "<< random2<<std::endl;
          m->setPosition(random1,random2);
      }