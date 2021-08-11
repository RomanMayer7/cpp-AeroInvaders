
#pragma once
#include "./sprite.hpp"
 
 class Sprite2D : public Sprite
{


  protected:
   int locx;
   int locy;

  public:
   RColor* color;
   bool fill;

   bool getFill()
   {
    return fill;
   }
   void setFill(bool b)
   {
    fill = b;
   }

   void setColor(RColor* c) 
   {
   color = c;
   }
   RColor* getColor()
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