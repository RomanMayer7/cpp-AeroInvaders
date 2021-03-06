 #include "player_manager.hpp"


 //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**--*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**--*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**--*-*-*-**-*-*-*-*-*-*-*-*
 //----Refactor Code to use Smart Pointers----
 /*PlayerManager::PlayerManager(int _maxEnergy, int _energyDec, int _windowWidth, int _windowHeight,Renderer* _renderer,Intersect** target
                     ,Intersect** target2 ) */
  PlayerManager :: PlayerManager(int _maxEnergy, int _energyDec, int _windowWidth, int _windowHeight,std::shared_ptr<Renderer> _renderer,
                 std::vector<std::shared_ptr<Intersect>> target /* ,Intersect** target2*/ )
    {
    
    
   std::cout << "PlayerManager().\n";
    maxEnergy = _maxEnergy;
    energyDec = _energyDec;
    width = _windowWidth;
    height = _windowHeight;
    renderer=_renderer;
    
    //----Refactor Code to use Smart Pointers----
    //MISSILE_COLOR=new RColor(255,0,0,255);
    MISSILE_COLOR=std::make_shared<RColor>(255,0,0,255);
    

    //*****************************************************************
    //SDL_Rect player_texture_rect;
    //player_texture_rect.w = 51; //the width of the texture
    //player_texture_rect.h = 92; //the height of the texture

    //----Refactor Code to use Smart Pointers----
    //gun=new PlayerSprite( 600,600,renderer->texture_rect,renderer->aircraft_texture);
    gun=std::make_shared<PlayerSprite>( 600,600,renderer->texture_rect,renderer->aircraft_texture);

    //*****************************************************************


    gun_width = renderer->texture_rect.w / 2;
    gun_height = renderer->texture_rect.h;

    gun_y = height - gun_height;
    min_x = gun_width;
    max_x = width - gun_width;
    gun_min_x = 0;
    gun_max_x = width - 2 * gun_width;
    mis_min_x = min_x - 2;
    mis_max_x = max_x - 2;

    //gun->setPosition(width / 2 - gun_width, gun_y); //set Aircraft in Center of Screen
    //std::cout << " height :"<<height<<" gun_height:"<<gun_height<<"\n";

    //INITIALIZE MISSLES for Player

    for (int i = 0; i < 3; i++)
     {
      //----Refactor Code to use Smart Pointers----
      // missile[i] = new MissileSprite(MISSILE_WIDTH, MISSILE_HEIGHT,MISSILE_COLOR, MISSILE_SPEED,
      //                                height - gun_height,0, target /*, target2*/);
         missile[i] = std::make_shared<MissileSprite>(MISSILE_WIDTH, MISSILE_HEIGHT,MISSILE_COLOR, MISSILE_SPEED,
                                     height - gun_height,0, target /*, target2*/);
     }
     
  }

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**--*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**--*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**--*-*-*-**-*-*-*-*-*-*-*-*
   //----Refactor Code to use Smart Pointers----
   //PlayerManager::PlayerManager(int _maxEnergy, int _energyDec, int _windowWidth, int _windowHeight,Renderer* _renderer,EnemySprite** target)
  PlayerManager::PlayerManager(int _maxEnergy, int _energyDec, int _windowWidth, int _windowHeight,std::shared_ptr<Renderer> _renderer,
                 std::vector<std::shared_ptr<EnemySprite>> target)
   {
   
    std::cout << "PlayerManager::ctor().\n";
    maxEnergy = _maxEnergy;
    energyDec = _energyDec;
    width = _windowWidth;
    height = _windowHeight;
    renderer=_renderer;
    
    //----Refactor Code to use Smart Pointers----
    //MISSILE_COLOR=new RColor(255,0,0,255);
    MISSILE_COLOR=std::make_shared<RColor>(255,0,0,255);
    

    //*****************************************************************

    //SDL_Rect player_texture_rect;
    //player_texture_rect.w = 51; //the width of the texture
    //player_texture_rect.h = 92; //the height of the texture
    
    //----Refactor Code to use Smart Pointers----
    //gun=new PlayerSprite( 600,600,renderer->texture_rect,renderer->aircraft_texture);
    gun=std::make_shared<PlayerSprite>( 600,600,renderer->texture_rect,renderer->aircraft_texture);


    //*****************************************************************


    gun_width = renderer->texture_rect.w / 2;
    gun_height = renderer->texture_rect.h;

    gun_y = height - gun_height;
    min_x = gun_width;
    max_x = width - gun_width;
    gun_min_x = 0;
    gun_max_x = width - 2 * gun_width;
    mis_min_x = min_x - 2;
    mis_max_x = max_x - 2;
    //gun->setPosition(width / 2 - gun_width, gun_y); //set Aircraft in Center of Screen
    //std::cout << " height :"<<height<<" gun_height:"<<gun_height<<"\n";

    //INITIALIZE MISSLES for Player
    for (int i = 0; i < 3; i++)
     {
      //----Refactor Code to use Smart Pointers---
      // missile[i] = new MissileSprite(MISSILE_WIDTH, MISSILE_HEIGHT,MISSILE_COLOR, MISSILE_SPEED,
      //                                height - gun_height,0, target /*, target2*/);
        missile.emplace_back(std::make_shared<MissileSprite>(MISSILE_WIDTH, MISSILE_HEIGHT,MISSILE_COLOR, MISSILE_SPEED,
                                     height - gun_height,0, target /*, target2*/));
     }
     std::cout << " after INITIALIZE MISSLES for Player.\n";
  }
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**--*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**--*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**--*-*-*-**-*-*-*-*-*-*-*-*


   void PlayerManager::newGame() 
   {
    //gun->setPosition(width / 2 - gun_width, gun_y);
    gun->restore();
    displayHit = false;
    energy = maxEnergy;
   }


  // move gun to the given x coordinate
   void PlayerManager::moveGun(int x) {
    if (x <= min_x) {
      gun->setPosition(gun_min_x+gun_width, gun_y);
    } else if (x >= max_x) {
      gun->setPosition(gun_max_x-gun_width, gun_y);
    } else {
      gun->setPosition(x , gun_y);
    }
  }

  // Fire Missile from given x coordinate
   void PlayerManager::fireMissile(int x) {
     std::cout << "PM:fireMissile():.\n";
    if (!missile[0]->isActive()) { // if missile sprite
      // isn't active
      if (x <= min_x) {
        missile[0]->init(mis_min_x);
      } else if (x >= max_x) {
        missile[0]->init(mis_max_x);
      } else {
        missile[0]->init(x - 2); // initialize missile
      }
    } else if (!missile[1]->isActive()) { // if missile sprite
      // isn't active
      if (x <= min_x) {
        missile[1]->init(mis_min_x);
      } else if (x >= max_x) {
        missile[1]->init(mis_max_x);
      } else {
        missile[1]->init(x - 2); // initialize missile
      }
    } else if (!missile[2]->isActive()) { // if missile sprite
      // isn't active
      if (x <= min_x) {
        missile[2]->init(mis_min_x);
      } else if (x >= max_x) {
        missile[2]->init(mis_max_x);
      } else {
        missile[2]->init(x - 2); // initialize missile
      }
    }
  }


  // handles a hit from an enemy
   void PlayerManager::handleHit() {
    displayHit = true; // set display hit flag
    energy -= energyDec; // update energy
    if (energy <= 0) { // game over if energy <= 0
      //game.gameOver(); // notify game manager
      gun->suspend(); // turn off sprites
      for (int i = 0; i < 3; i++) {
        missile[i]->suspend();
      }
    }
  }


  // Update all the parameters associated with the
  // Player. In this case, only the Missle needs to move
  // automatically. Aircraft is moved by player
  //Also the gun manager checks if the missile hits anything
   void PlayerManager::update() {
    for (int i = 0; i < 3; i++) {
      missile[i]->update();
    }
  }


    //----Refactor Code to use Smart Pointers----
   //void PlayerManager::paint(Renderer* g)
  void PlayerManager::paint(std::shared_ptr<Renderer> g)
  {
    // TODO::if gun is hit, flash a red rectangle
    // instead of painting gun
    //PSEUDOCODE EXAMPLE
    // if (displayHit) {
    //   g.setColor(Color.red);
    //   g.fillRect(0, gun_y, width, gun_height);
    //   displayHit = false;
    // } else {
      gun->paint_g(g->background_renderer);
  //}

    //Paint all  missles associated with Player 
    for (int i = 0; i < 3; i++) 
    {
      missile[i]->paint(g);         
    }

    // TODO::display energy left
    //PSEUDOCODE EXAMPLE
    //g.setColor(Color.red);
    //g.drawString(energyString, 3, 13);
    //g.fillRect(0, 17, energy, 10);
  }


  // accessor method for player's sprite instance
  //----Refactor Code to use Smart Pointers----
  // PlayerSprite* PlayerManager::getGun()
   std::shared_ptr<PlayerSprite> PlayerManager::getGun()
   {
       return gun;
   }

   int PlayerManager::getGunY()
   {
      return gun_y;
   }

   int PlayerManager::getGunX()
  {
    return gun->getLocX();
  }

   void PlayerManager::setEnergyDec(int _energyDec)
  {
   energyDec = _energyDec;
  }

