
#pragma once
#include "bitmap_sprite.hpp"
#include "movable.hpp"
#include "SDL2/SDL_image.h"
#include <vector>



class BitmapLoop :public BitmapSprite, public Moveable 
{
protected:
   //----Refactor Code to use Smart Pointers----
   //SDL_Texture** texture_images; // sequence of bitmaps
    std::vector<std::shared_ptr<SDL_Texture>>texture_images; // sequence of bitmaps

   int num_of_images; //length of loop
   int currentImage; // the current bitmap's index
   int vx;
   int vy;
  // bool foreground; // are there foreground images?
  // bool background; // is there background image?
  

public:
   bool finalizing=false;
   // constructor. Assumes that background image is already loaded. 
   //----Refactor Code to use Smart Pointers----
   //BitmapLoop(int x, int y ,SDL_Rect _texture_rect,SDL_Texture**_texture_images,int _num_of_images);
   BitmapLoop(int x, int y ,SDL_Rect _texture_rect, std::vector<std::shared_ptr<SDL_Texture>>_texture_images,int _num_of_images);
   BitmapLoop();

  // cycle currentImage if sprite is active
  void update();

  //----Refactor Code to use Smart Pointers----
  //void paint_g(SDL_Renderer *renderer );
  void paint_g(std::shared_ptr<SDL_Renderer> renderer );

  // implement moveable interface
   void setPosition(int x, int y);
   void setVelocity(int x, int y);

  // update position according to velocity
   void updatePosition();
};