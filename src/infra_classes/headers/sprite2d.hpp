
#pragma once
#include "./sprite.hpp"
#include <memory>
 
 class Sprite2D : public Sprite
{


  protected:
   int locx;
   int locy;

  public:
   //----Refactor Code to use Smart Pointers----
   //RColor* color;
   std::shared_ptr<RColor> color;

   bool fill;

   bool getFill()
   {
    return fill;
   }
   void setFill(bool b)
   {
    fill = b;
   }
   
   //----Refactor Code to use Smart Pointers----
   // void setColor(RColor* c) 
   void setColor(std::shared_ptr<RColor> c )
   {
     color = c;
   }

   //----Refactor Code to use Smart Pointers----
   //RColor* getColor()
   std::shared_ptr<RColor> getColor()
   {
    return color;
   }

   int getLocY()
   {
     return locy;
   }

   int getLocX()
   {
     return locx;
   }
};