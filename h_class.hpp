#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <SDL.h>

#include "h_sdl.hpp"

class hetman
{
public:
  Window& window;
  SDL_Surface *queen;
  SDL_Surface *rect;
  int x;
  int y;
  int xVel;
  int yVel;

  hetman(Window& window);
  void move();
  void show();

  int dest_y;
};
