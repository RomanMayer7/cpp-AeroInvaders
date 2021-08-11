#include "headers/bitmap_sprite.hpp"
#include <iostream>

		 BitmapSprite::BitmapSprite(int x,int y,SDL_Rect _texture_rect, SDL_Texture *_texture_img)
        {

		    locx = x;
		    locy = y;
		    texture_img = _texture_img;
        texture_rect = _texture_rect;
        width=_texture_rect.w;
        height=_texture_rect.h;

		    if (texture_img != NULL) 
            {
              texture_rect.x = x;  //the x coordinate
              texture_rect.y = y; // the y coordinate
            }
        }

		 BitmapSprite::BitmapSprite()
         {

         }
		 void BitmapSprite::setSize(int w,int h)
         {
            width = w;
		        height = h;
         }
         //update location of the sprite
		 void BitmapSprite::update() 
         {
             
              texture_rect.x = locx;  //the x coordinate
              //texture_rect.y = locy; // the y coordinate
         }

         //render the sprite
	     void BitmapSprite::paint_g(SDL_Renderer *renderer )
         {
           //std::cout << "BitmapManager::paint().\n";
             SDL_RenderCopy(renderer, texture_img, NULL, &texture_rect);
               // Update Screen
               // SDL_RenderPresent(renderer);
         }

        // void BitmapSprite::paint (Renderer r) 
        //   {
             
        //   }