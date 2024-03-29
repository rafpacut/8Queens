#include "h_sdl.hpp"

SDL_Surface *load_image( std::string filename )
{
  //The image that's loaded
  SDL_Surface* loadedImage = NULL;

  //The optimized image that will be used
  SDL_Surface* optimizedImage = NULL;

  //Load the image
  loadedImage = IMG_Load( filename.c_str() );

  //If the image loaded
  if( loadedImage != NULL )
  {
    //Create an optimized image
    optimizedImage = SDL_DisplayFormat( loadedImage );

    //Free the old image
    SDL_FreeSurface( loadedImage );

    //If the image was optimized just fine
    if( optimizedImage != NULL )
    {
      //Map the color key
      Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );

      //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
      SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
    }
  }

  //Return the optimized image
  return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
  //Temporary rectangle to hold the offsets
  SDL_Rect offset;

  //Get the offsets
  offset.x = x;
  offset.y = y;

  //Blit the surface
  SDL_BlitSurface( source, NULL, destination, &offset );
}

void Window::init(int width, int height, int bpp)
{
  screen_width = width;
  screen_height = height;
  screen_bpp = bpp;
  
  SDL_Init( SDL_INIT_EVERYTHING );

  //Set the window caption
  SDL_WM_SetCaption( "Osmiu hetmanow", NULL );

  //Set up the screen
  screen = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE);
}
