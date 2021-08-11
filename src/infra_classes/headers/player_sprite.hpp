#pragma once

#include "bitmap_sprite.hpp"
#include "movable.hpp"
#include "intersect.hpp"
#include <iostream>

class PlayerSprite : public BitmapSprite,Moveable,Intersect 
{
	//protected GunManager gm; // pointer to manager class
public:

  PlayerSprite(int _locx, int _locy, SDL_Rect _texture_rect, SDL_Texture *_texture_img);
  PlayerSprite();

// the following methods implement Moveable:
 void setPosition(int x,int y);
 void setVelocity(int x,int y);
 void updatePosition();

// the following methods implement Intersect:
//compare bounding boxes
 bool intersect(int x1,int y1,int x2,int y2);

// echo to stdout
 void hit();
};