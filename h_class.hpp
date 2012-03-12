#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <SDL.h>

#include "h_sdl.hpp"

//The dimensions of the queen
int hetman_width = 85;
int hetman_height = 85;

class hetman
{
public :
  SDL_Surface *queen;
  SDL_Surface *rect;
  int x;
  int y;
  int xVel;
  int yVel;

  hetman();
  void move();
  void show();

  int dest_y;
};


bool kolizja(int n);
void ustaw(int n);
