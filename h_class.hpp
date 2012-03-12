#ifndef h_class_hpp
#define h_class_hpp


#include <iostream>
#include <SDL.h>
#include <string>
#include <vector>
#include <algorithm>
#include "h_sdl.cpp"
using namespace std;

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


hetman::hetman()
{
  //Initialize the offsets
  x = 0;
  y = 0;

  //Initialize the velocity
  xVel = 0;
  yVel = 0;
}


void hetman::show()
{
  apply_surface( x, y, hetmans[n].queen, screen );
}

void hetman::move()
{
  //Move the queen left or right
  x += xVel;

  //If the queen went too far to the left or right
  if( ( x < 0 ) || ( x + hetman_width > SCREEN_WIDTH ) )
  {
    //move back
    x -= xVel;
  }

  //Move the queen up or down
  y += yVel;

  //If the queen went too far up or down
  if( ( y < 0 ) || ( y + hetman_height > SCREEN_HEIGHT ) )
  {
    //move back
    y -= yVel;
  }
}


bool kolizja(int n)
{
  bool p = false;
  for( int i = 0 ; i < n ; i++ )
  {
    if( hetmans[i].dest_y == hetmans[n].dest_y || abs( hetmans[n].dest_y - hetmans[i].dest_y ) == n - i )
      p = true;
  }
  return p;
}


void ustaw(int n)
{
  for( int i = 0 ; i < 8 ; i++ )
  {
    hetmans[n].dest_y = i;
    if( !kolizja(n) )
      if( n < 7 )
        ustaw(n+1);
      else
        game_loop();
  }
}

#endif
