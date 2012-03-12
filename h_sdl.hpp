#pragma once

#include <string>
#include <vector>

#include <SDL.h>
#include "SDL/SDL_image.h"
#include "h_class.hpp"

SDL_Surface *load_image( std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
void init();
void load_files();
void clean_up();
void game_loop();
