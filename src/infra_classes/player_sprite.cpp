#include "headers/player_sprite.hpp"


//PlayerSprite::PlayerSprite(int _locx,int _locy, SDL_Rect _texture_rect, SDL_Texture *_texture_img)
//                         :BitmapSprite(_locx,_locy,_texture_rect,_texture_img)
PlayerSprite::PlayerSprite(int _locx, int _locy, SDL_Rect _texture_rect,std::shared_ptr<SDL_Texture>_texture_img)
:BitmapSprite(_locx,_locy,_texture_rect,_texture_img)
  {
      std::cout << "PlayerSprite::ctor().\n";

  }

PlayerSprite::PlayerSprite()
 {

 }

// the following methods implement Moveable:
 void PlayerSprite::setPosition(int x,int y)
 {
     locx = x;
     locy = y;
 }
 void PlayerSprite::setVelocity(int x,int y) {
}
 void PlayerSprite::updatePosition() {
}
// the following methods implement Intersect:
//compare bounding boxes
 bool PlayerSprite::intersect(int x1,int y1,int x2,int y2) 
  {
    return visible && (x2 >= locx) && (locx+width >= x1)
                   && (y2 >= locy) && (locy+height >= y1);
  }

// echo to stdout
 void PlayerSprite::hit() 
  {
    std::cout<<"HIT!";
    //gm.handleHit(); // notify manager of hit
  }