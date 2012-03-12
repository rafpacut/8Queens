#pragma once

#include <string>
#include <vector>

#include <SDL.h>
#include "SDL/SDL_image.h"
#include "h_class.hpp"

struct Window
{
  SDL_Surface *background;
  SDL_Surface *screen;
  int screen_width;
  int screen_height;
  int screen_bpp;

  void init(int width, int height, int bpp);
};

SDL_Surface *load_image( std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
