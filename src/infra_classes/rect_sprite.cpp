#include "headers/rect_sprite.hpp"
     
	 RectSprite::RectSprite(){}

    //----Refactor Code to use Smart Pointers----
	//RectSprite::RectSprite(int w,int h,RColor* c)
	RectSprite::RectSprite(int w,int h,std::shared_ptr<RColor> c)
	{
	  locx = 0;
	  locy = 0;
	  width = w;
	  height = h;
	  color = c;
	  restore();
	}

	//----Refactor Code to use Smart Pointers----
	 //RectSprite::RectSprite(int x,int y,int w,int h,RColor* c)
	 RectSprite::RectSprite(int x,int y,int w,int h,std::shared_ptr<RColor> c)
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
    
	//----Refactor Code to use Smart Pointers----
	//void RectSprite::paint(Renderer* r)
	void RectSprite::paint(std::shared_ptr<Renderer> r)
	 {
		 //std::cout << "RectSprite::paint().\n";
	   if (visible)
	   {
		   //std::cout << "RectSprite::paint():visible.\n";
	     if (fill)
	     {
			//std::cout << "RectSprite::paint():fill locx:"<<locx<<" locy:"<<locy<<" width:"<<width<<" height:"<<height<<" color r:"<<color->r<<"\n";
           
		   //----Refactor Code to use Smart Pointers----
	       //r->fillRect(locx,locy,width,height,*color);
		   r->fillRect(locx,locy,width,height,color);
		   
		   //SDL_RenderPresent(r->background_renderer);
	      }
	//     else 
	//     {
    //       r.fillRect(locx,locy,width,height,color);
	//       //r.drawRect(locx,locy,width,height);
	     }
	  }

	  
