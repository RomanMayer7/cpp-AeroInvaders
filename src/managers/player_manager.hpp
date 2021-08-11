 
 #pragma once
 
 #include "../infra_classes/headers/player_sprite.hpp"
 #include "../infra_classes/headers/missle_sprite.hpp"
 #include "../infra_classes/headers/rect_sprite.hpp"
 #include "../headers/renderer.h"


#define MISSILE_WIDTH 5
#define MISSILE_HEIGHT 27
#define MISSILE_SPEED -27// missile flies upward
 

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

   bool displayHit;
   int energy;
   int maxEnergy;
   int energyDec;
   RColor* MISSILE_COLOR; //Red Color by Default

  //AudioClip shotsound;
  public:

   PlayerManager(int _maxEnergy, int _energyDec, int _windowWidth, int _windowHeight,Renderer* _renderer,Intersect** target,Intersect** target2
                    /*Image gunImage,*/ /*Intersect target[], Intersect target2[],*/ ) 
    {
    
    
   std::cout << "PlayerManager().\n";
    maxEnergy = _maxEnergy;
    energyDec = _energyDec;
    width = _windowWidth;
    height = _windowHeight;
    renderer=_renderer;

    MISSILE_COLOR=new RColor(255,0,0,255);
    

    //this.shotsound = shotsound;
    //game = (GameManager) a;

    //*****************************************************************

    // gun = new PlayerSprite(gunImage, a, this);
    //SDL_Rect player_texture_rect;
    //player_texture_rect.w = 51; //the width of the texture
    //player_texture_rect.h = 92; //the height of the texture

    gun=new PlayerSprite( 600,600,renderer->texture_rect,renderer->aircraft_texture);


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
    gun->setPosition(width / 2 - gun_width, gun_y); //set Aircraft in Center of Screen

       //std::cout << " height :"<<height<<" gun_height:"<<gun_height<<"\n";

    //INITIALIZE MISSLES for Player

    for (int i = 0; i < 3; i++)
     {
      missile[i] = new MissileSprite(MISSILE_WIDTH, MISSILE_HEIGHT,MISSILE_COLOR, MISSILE_SPEED,
                                     height - gun_height,0, target, target2);
     }
     
  }


   void newGame() 
   {
    //gun->setPosition(width / 2 - gun_width, gun_y);
    gun->restore();
    displayHit = false;
    energy = maxEnergy;
   }


  // move gun to the given x coordinate
   void moveGun(int x) {
    if (x <= min_x) {
      gun->setPosition(gun_min_x, gun_y);
    } else if (x >= max_x) {
      gun->setPosition(gun_max_x, gun_y);
    } else {
      gun->setPosition(x - gun_width, gun_y);
    }
  }

  // Fire Missile from given x coordinate
   void fireMissile(int x) {
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
   void handleHit() {
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
  // Player(gun). In this case, only the Missle needs to move
  // automatically. Aircraft is moved by player
  //Also the gun manager checks if the
  // missile hits anything
   void update() {
    for (int i = 0; i < 3; i++) {
      missile[i]->update();
    }
  }


  // Paint all sprites associated with gun
  // also paint status display for amount of energy left
  std::string energyString = "Energy";


   void paint(Renderer* g)
  {
    // if gun is hit, flash a red rectangle
    // instead of painting gun

    // if (displayHit) {
    //   g.setColor(Color.red);
    //   g.fillRect(0, gun_y, width, gun_height);
    //   displayHit = false;
      //std::cout << "PlayerManager::paint().\n";
    // } else {
      gun->paint_g(g->background_renderer);
  //}

    //Paint all  missles associated with Player 
    for (int i = 0; i < 3; i++) 
    {
      missile[i]->paint(g);         
    }

    // display energy left
    //g.setColor(Color.red);
    //g.drawString(energyString, 3, 13);
    //g.fillRect(0, 17, energy, 10);
  }


  // accessor method for player's sprite instance
   PlayerSprite* getGun()
   {
       return gun;
   }
   int getGunY()
   {
      return gun_y;
   }

   int getGunX()
  {
    return gun->getLocX();
  }

   void setEnergyDec(int _energyDec)
  {
   energyDec = _energyDec;
  }
};