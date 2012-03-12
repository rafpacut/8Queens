#include "h_class.hpp"

extern std::vector<hetman> hetmans;
extern int n;
extern SDL_Surface *background;
extern SDL_Surface *screen;

//The dimensions of the queen
int hetman_width = 85;
int hetman_height = 85;

hetman::hetman(Window& window) : window(window)
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
  apply_surface( x, y, hetmans[n].queen, window.screen );
}

void hetman::move()
{
  //Move the queen left or right
  x += xVel;

  //If the queen went too far to the left or right
  if( ( x < 0 ) || ( x + hetman_width > window.screen_width ) )
  {
    //move back
    x -= xVel;
  }

  //Move the queen up or down
  y += yVel;

  //If the queen went too far up or down
  if( ( y < 0 ) || ( y + hetman_height > window.screen_height ) )
  {
    //move back
    y -= yVel;
  }
}
