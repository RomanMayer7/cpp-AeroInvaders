#ifndef RENDERER_H
#define RENDERER_H


#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "./infra_classes/headers/rcolor.hpp"
#include "./infra_classes/headers/bitmap_sprite.hpp"
#include "./infra_classes/headers/player_sprite.hpp"
#include "./infra_classes/headers/bitmap_loop.hpp"
#include<memory>




class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render();
  void UpdateWindowTitle(int score, int fps, int level, int enemiesLanded);
  void UpdateWindowTitleEndGame(int score, int level,int enemiesLanded);
  bool loadMedia();



  // Render rectangle
  void draw_rectangle(SDL_Surface* surface, int x, int y, int width, int height);

 //----Refactor Code to use Smart Pointers----
  //void fillRect(int locx,int locy,int width,int height,RColor &color);
  void fillRect(int locx,int locy,int width,int height,std::shared_ptr<RColor> color);


  SDL_Window *sdl_window;
    //----Refactor Code to use Smart Pointers--------------------------
  /*
  BitmapSprite *aircraftSprite;
  BitmapSprite *aircraftSprite_two;
  PlayerSprite *aircraftSprite_three;
  BitmapLoop *enemySpriteLoop_one;
  BitmapLoop *enemySpriteLoop_two;
  BitmapLoop *enemySpriteLoop_three;*/

  std::shared_ptr<BitmapSprite> aircraftSprite;
  std::shared_ptr<BitmapSprite> aircraftSprite_two;
  std::shared_ptr<PlayerSprite> aircraftSprite_three;
  std::shared_ptr<BitmapLoop> enemySpriteLoop_one;
  std::shared_ptr<BitmapLoop> enemySpriteLoop_two;
  std::shared_ptr<BitmapLoop> enemySpriteLoop_three;
  //-----------------------------------------------------------------

  
   //----Refactor Code to use Smart Pointers--------------------------
   /*
   //The surface contained by the window
   SDL_Surface* background_surface = NULL;
  //The image we will load and show on the screen
    SDL_Texture* background_texture = NULL;
    SDL_Texture* aircraft_texture;
    SDL_Texture** enemy_textures;
    SDL_Texture** enemy_attack_textures;
    SDL_Texture** enemy_explode_textures;
    */

    //The surface contained by the window
    std::shared_ptr<SDL_Surface> background_surface = NULL;
    //The image we will load and show on the screen
    std::shared_ptr<SDL_Texture> background_texture = NULL;
    std::shared_ptr<SDL_Texture> aircraft_texture;
    std::vector<std::shared_ptr<SDL_Texture> > enemy_textures;
    std::vector<std::shared_ptr<SDL_Texture> > enemy_attack_textures;
    std::vector<std::shared_ptr<SDL_Texture> > enemy_explode_textures;
    //-----------------------------------------------------------------


    SDL_Rect texture_rect;
    //----Refactor Code to use Smart Pointers--------------------------
    //SDL_Renderer* background_renderer;
    std::shared_ptr<SDL_Renderer> background_renderer;


 private:
  
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

};

#endif