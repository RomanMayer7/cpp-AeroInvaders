#ifndef RENDERER_H
#define RENDERER_H


#include <vector>
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "./infra_classes/headers/rcolor.hpp"
#include "./infra_classes/headers/bitmap_sprite.hpp"
#include "./infra_classes/headers/player_sprite.hpp"
#include "./infra_classes/headers/bitmap_loop.hpp"




class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(/*Snake const snake, SDL_Point const &food*/);
  void UpdateWindowTitle(int score, int fps, int level);
  bool loadMedia();
  void draw_rectangle(SDL_Surface* surface, int x, int y, int width, int height);
  void fillRect(int locx,int locy,int width,int height,RColor &color);
  SDL_Window *sdl_window;
  BitmapSprite *aircraftSprite;
  BitmapSprite *aircraftSprite_two;
  PlayerSprite *aircraftSprite_three;
  BitmapLoop *enemySpriteLoop_one;
  BitmapLoop *enemySpriteLoop_two;
  BitmapLoop *enemySpriteLoop_three;



   //The surface contained by the window
   SDL_Surface* background_surface = NULL;
   //The image we will load and show on the screen
    SDL_Texture* background_texture = NULL;
    SDL_Texture* aircraft_texture;
    SDL_Texture** enemy_textures;
    SDL_Texture** enemy_attack_textures;
    SDL_Texture** enemy_explode_textures;

    SDL_Rect texture_rect;
    SDL_Renderer* background_renderer;


 private:
  
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

};

#endif