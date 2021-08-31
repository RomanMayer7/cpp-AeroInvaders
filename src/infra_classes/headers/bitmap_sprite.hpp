
#pragma once
#include "sprite2d.hpp"
#include "SDL2/SDL_image.h"


class BitmapSprite :public Sprite2D
 {

    protected:

		 // image dimensions
		 int width,height; 

         //----Refactor Code to use Smart Pointers----
		 //SDL_Texture *texture_img=NULL; // the bitmap
		 std::shared_ptr<SDL_Texture> texture_img=NULL; // the bitmap

         SDL_Rect texture_rect; //bitmap dimensions

    public:
		//----Refactor Code to use Smart Pointers----
		 //BitmapSprite(int x,int y,SDL_Rect _texture_rect, SDL_Texture *_texture_img);
		 BitmapSprite(int x,int y,SDL_Rect _texture_rect, std::shared_ptr<SDL_Texture> _texture_img);
		 BitmapSprite();
		 void setSize(int w,int h);
		 void update();
		//----Refactor Code to use Smart Pointers----
	    //void paint_g(SDL_Renderer *renderer);
        void paint_g(std::shared_ptr<SDL_Renderer> renderer ); 
	    
};