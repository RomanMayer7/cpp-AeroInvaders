#include "headers/renderer.h"

#include <iostream>
#include <string>


Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Aero Invaders Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

     if (nullptr != sdl_window) {
    std::cerr << "Window can  be created.\n";
  }


    background_renderer = SDL_CreateRenderer(sdl_window, -1, 0);

    loadMedia();
    background_texture = SDL_CreateTextureFromSurface(background_renderer, background_surface);

    //std::cerr << "11111111111111.\n";

    aircraft_texture = IMG_LoadTexture(background_renderer, "../img/gun5.bmp");
    texture_rect;
    texture_rect.x = 700;  //the x coordinate
    texture_rect.y = 500; // the y coordinate
    texture_rect.w = 51; //the width of the texture
    texture_rect.h = 92; //the height of the texture
    
    //std::cerr << "222222222222222222.\n";
    //aircraftSprite=new BitmapSprite();

     aircraftSprite=new BitmapSprite( 700,500,texture_rect,aircraft_texture);
     aircraftSprite_two=new BitmapSprite( 500,500,texture_rect,aircraft_texture);
     //aircraftSprite_three=new PlayerSprite( 600,600,texture_rect,aircraft_texture);

     //BitmapSprite aircraftSprite_( 700,500,texture_rect,aircraft_texture);
      //std::cerr << "333333333333333333.\n";


  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  // sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  // if (nullptr == sdl_renderer) {
  //   std::cerr << "Renderer could not be created.\n";
  //   std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  // }

    //Get window surface
    //gScreenSurface = SDL_GetWindowSurface( sdl_window );


}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render()
 {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;
  
  //std::cerr << "rrrrrrrrrrrrrrrrrrrrtr.\n";
 // Clear screen
  SDL_SetRenderDrawColor(background_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
 SDL_RenderClear(background_renderer);
 SDL_RenderCopy(background_renderer, background_texture, NULL, NULL);



  /*
  SDL_SetRenderDrawColor(background_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(background_renderer, &block);
  */


  //Render Aircraft
  //SDL_RenderCopy(background_renderer, aircraft_texture, NULL, &texture_rect);

  
   // aircraftSprite->paint_g(background_renderer);
    //aircraftSprite_two->paint_g(background_renderer);

    //std::cerr << "rfsfsfsssssssssss.\n";
    //aircraftSprite_three->paint_g(background_renderer);
    //std::cout<< "Aircraft Position |Renderer  x: "<<aircraftSprite_three->getLocX()<<" ,y:"<<aircraftSprite_three->getLocY()<<std::endl;

 
  // Update Screen
 //SDL_RenderPresent(background_renderer);


}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Your Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

bool Renderer::loadMedia()
{
  // std::cout<<"loadMedia"<<std::endl;
    //Loading success flag
    bool success = true;

    //Load splash image
    background_surface = SDL_LoadBMP( "../img/skycity_background.bmp" );
    if( background_surface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "img/skycity_background.bmp", SDL_GetError() );
        success = false;
    }
    else
    {
      std::cout<<"LOAD IMAGES SUCCESS";
    }

     

    return success;
}

void Renderer::draw_rectangle(SDL_Surface* surface, int x, int y, int width, int height)
{
    SDL_LockSurface(surface);
    std::vector<uint8_t> pixels(surface->h * surface->pitch, 0);

    int dy, dx;
    int maxwidth = width * 3;
    for (dy = y; dy < height; dy++) {
        for (dx = x; dx < maxwidth; dx += 3) {
            pixels[dx + (dy * surface->pitch)] = 0;
            pixels[dx + (dy * surface->pitch) + 1] = 255;
            pixels[dx + (dy * surface->pitch) + 2] = 0;
        }
    }
    memcpy(surface->pixels, pixels.data(), surface->pitch * surface->h);

    SDL_UnlockSurface(surface);
}

// Render rectangle
void Renderer::fillRect(int locx,int locy,int width,int height,RColor &color)
{ 
  SDL_Rect block;
  block.w = width;
  block.h = height;

  //SDL_SetRenderDrawColor(background_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  SDL_SetRenderDrawColor(background_renderer, color.r, color.g, color.b, color.a);
  block.x = locx ;
  block.y = locy ;
  std::cout << "Renderer::fillRect:"<<locx<<" locy:"<<locy<<" width:"<<width<<" height:"<<height<<" color r:"<<color.r<<"\n";
  SDL_RenderFillRect(background_renderer, &block);
  // SDL_RenderPresent(background_renderer);

}
