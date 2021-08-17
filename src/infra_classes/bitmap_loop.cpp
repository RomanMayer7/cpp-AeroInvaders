#include "headers/bitmap_loop.hpp"
#include <iostream>


   BitmapLoop::BitmapLoop(int x, int y ,SDL_Rect _texture_rect,SDL_Texture**_texture_images,int _num_of_images)
   {

    	locx = x;
		  locy = y;
	  	texture_images = _texture_images;
      num_of_images=_num_of_images;
      texture_rect = _texture_rect;
      width=_texture_rect.w;
      height=_texture_rect.h;
      visible=true;
      active=true;

		  if (texture_images != NULL) 
        {
          texture_rect.x = x;  //the x coordinate
          texture_rect.y = y; // the y coordinate
        }
        
         currentImage = 0;

   }

   BitmapLoop::BitmapLoop(){}

    // cycle currentImage if sprite is active
   void BitmapLoop::update() 
   {
    if (active)
    {
      currentImage = (currentImage + 1) % num_of_images;
      //std::cout<<"current image: "<<currentImage<<std::endl;
    }
    updatePosition();
  }

   void BitmapLoop::paint_g(SDL_Renderer *renderer ) 
   {
     //std::cout<<"bitmap_loop render777";
      if (visible) 
      {
        //std::cout<<"bitmap_loop render";
        SDL_RenderCopy(renderer, texture_images[currentImage], NULL, &texture_rect);

      }
   }


  // implement moveable interface
    void BitmapLoop::setPosition(int x, int y) 
    {
     locx = x;
     locy = y;
    }

    void BitmapLoop::setVelocity(int x, int y)
     {
       vx = x;
       vy = y;
     }

  // update position according to velocity
   void BitmapLoop::updatePosition() 
    {
      locx += vx;
      locy += vy;
    }