#pragma once
//#include "../../headers/renderer.h"
#include "SDL.h"
#include "./infra_classes/headers/rcolor.hpp"


 // abstract class
class Sprite
{
protected:
   bool visible; // is sprite visible
   bool active; // is sprite updateable

  // abstract methods:
  //virtual void paint (Renderer& r) = 0; //probably better to use move semantics
  virtual void update() = 0;
  // accessor methods:
   bool isVisible() 
  {
    return visible;
  }
  public:
   void setVisible(bool b)
  {
	visible = b;
  }
   bool isActive()
  {
    return active;
  }
   void setActive(bool b)
  {
    active = b;
  }
  // suspend the sprite
   void suspend()
  {
    setVisible(false);
    setActive(false);
  }
  // restore the sprite
   void restore() 
  {
    setVisible(true);
    setActive(true);
  }


 };