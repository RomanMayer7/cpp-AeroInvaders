#include "headers/enemy_sprite.hpp"


void EnemySprite::landingRoutine() 
       {
         // tell game manager that  Enemy aircraft has landed
         game->alienLanded(); 
        
          suspend();
       }

void EnemySprite::startStandby()
       {
         vx = getRand(8) - 4;
         vy = 0;
         state = STANDBY;
       }

      // start attack state
void EnemySprite::startAttack()
       {
         vx = getRand(10) - 5;
         vy = getRand(5) + 7;
         texture_images = attack_images; // change to attack animation loop
         state = ATTACK;
       }

      // start retreating state
void EnemySprite::startRetreat()
       {
         vx = 0;
         vy = -getRand(3) - 2;
         texture_images = normal_images; // change to usual animation loop
         state = RETREAT;
       }

void EnemySprite::startLand()
       {
         vx = 0;
         vy = getRand(3) + 2;
         state = LAND;
       }

      // start explosion state
void EnemySprite::startExplode() 
       {
         texture_images = explode_images; // set bitmap to explosion sequence
         currentImage = 0; // start at beginning of animation
         explosion_counter = 0; // count the number of frames

       //em.playExplosion(); // play explosion sound:
       //---em is reference to the EnemyManager class---
         state = EXPLODE;
       }


EnemySprite::EnemySprite(int x,int y,SDL_Rect _texture_rect,int _num_of_images,
         SDL_Texture** enemyImages, SDL_Texture** attackImages,
         SDL_Texture** explodeImages, int max_x, int max_y, EnemyManager _em,GameManager _gm)
        :BitmapLoop(x,y,_texture_rect,enemyImages,_num_of_images)
        {
    
           max_x = max_x;
           max_y = max_y;
           em = _em;
           game = _gm;

           normal_images = enemyImages;
           attack_images = attackImages;
           explode_images = explodeImages;
           currentImage = getRand(5); // start at random image
           startStandby();
        }

EnemySprite::EnemySprite() {}
        
        // finish initializing info about the player's gun
void EnemySprite::initialize(PlayerManager* pm)
        {
          target = pm->getGun(); // refers to gun sprite
          player_y = pm->getGunY(); // get gun y-coordinate
        }  

        // implement Intersect interface:
bool EnemySprite::intersect(int x1, int y1, int x2, int y2)
         {
           return visible && (x2 >= locx) && (locx + width >= x1) &&
                             (y2 >= locy) && (locy + height >= y1);
         }

        // this is called if a missile hits the alien
void EnemySprite::hit() 
        {
           // enemy is invulnerable when it's attacking
           // but it gets "pushed back"
           if (state == ATTACK) 
           {
              locy -= 37;
           }
          // otherwise explode!
           else if (state != EXPLODE)
           {
             startExplode(); // start explode state
             em->killed(); // tell UFOManager
             game->incrementScore(); // add to score
            // another UFO's dead
            }
        }

       // set state and images loop
void EnemySprite::init()
        {
          startStandby();
           texture_images = normal_images;
          restore();
        }


       //--------------------this implements the 'State Machine'---------------------------------
void EnemySprite::update()
       {
         // if enemy hits target
         if ((locy + height >= player_y) && target->intersect(locx, locy, locx + width, locy + height)) 
              {
                target->hit();
                suspend();
                return;
              }         
         // otherwise, update Enemy state
         // pick random nums
         double r1 = fRand(0,1); 
         double r2 = fRand(0,1);
    
        switch (state) 
        {
          case STANDBY:
            if (r1 > STANDBY_EXIT) 
            {
               if (r2 > 0.5) 
               {
                  startAttack();
               }
               else 
               {
                  startLand();
               }
            }
           // else change the direction by flipping
           // the x-velocity. Net result: ufo moves
           // from side to side. And if the ufo gets close to
           // the left or right side of screen, it always changes
           // direction.
            else if ((locx < width) || (locx > max_x - width) ||(r2 > FLIP_X)) 
            {
               vx = -vx;
            }
          break;

          case ATTACK:
            // retreat if the enemy flies too close to
            // the ground
            if ((r1 > ATTACK_EXIT) || (locy > player_y - 17)) 
            {
              startRetreat();
            }
            // flip x-direction if it gets too close to edges
            else if ((locx < width) || (locx > max_x - width) || (r2 > FLIP_X))
            {
              vx = -vx;
            }
          break;

          case RETREAT:
            if (r1 > RETREAT_EXIT)
             {
               if (r2 > 0.5)
                {
                  startAttack();
                }
                else
                {
                  startStandby();
                }
             }
            // stop retreat if enemy goes too close
            // to top of screen
            else if (locy < RETREAT_Y)
             {
               startStandby();
             }
          break;

          case LAND:
            if (r1 > LAND_EXIT)
             {
               startStandby();
             } 
             else if (locy >= max_y - height) 
             {
               landingRoutine();
             }
          break;

          case EXPLODE:
            explosion_counter++; // bump counter
           // suspend once animation is finished
           if (explosion_counter == num_of_images)
            {
               suspend();
            }
          break;
       }
       BitmapLoop::update(); // BitmapLoop update draws the appropriate image
    }
    //--------------------this is end of implementation of the 'State Machine'---------------------------------

  
int EnemySprite::getRand(int x) 
  {
    srand((unsigned)time(0));
    int random;
    random = rand() % x + 1;     // v2 in the range 1 to x
    return random;
  }

double EnemySprite::fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}