#include "headers/rect_sprite.hpp"
     
	 RectSprite::RectSprite(){}

	 RectSprite::RectSprite(int w,int h,RColor* c)
	{
	  locx = 0;
	  locy = 0;
	  width = w;
	  height = h;
	  color = c;
	  restore();
	}
	 RectSprite::RectSprite(int x,int y,int w,int h,RColor* c)
	{
	  locx = x;
	  locy = y;
	  width = w;
	  height = h;
	  color = c;
	  fill = true; // default: fill
	  restore(); // restore the sprite
	}
	// provide implementation of abstract methods:
	 void RectSprite::update() 
	{
	// does nothing
	}
	// check if sprite's visible before painting
	void RectSprite::paint(Renderer* r)
	 {
		 //std::cout << "RectSprite::paint().\n";
	   if (visible)
	   {
		   //std::cout << "RectSprite::paint():visible.\n";
	     if (fill)
	     {
			//std::cout << "RectSprite::paint():fill locx:"<<locx<<" locy:"<<locy<<" width:"<<width<<" height:"<<height<<" color r:"<<color->r<<"\n";
	       r->fillRect(locx,locy,width,height,*color);
		   
		   //SDL_RenderPresent(r->background_renderer);
	      }
	//     else 
	//     {
    //       r.fillRect(locx,locy,width,height,color);
	//       //r.drawRect(locx,locy,width,height);
	     }
	  }

	  
