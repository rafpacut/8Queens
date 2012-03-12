#include "h_class.hpp"
#include "h_sdl.cpp"

//numer hetmana
int n = 0;
//vector of our hetmans
vector<hetman> hetmans( 8, hetman() );

void load_files()
{
  background = load_image( "szachownica.jpg" );
  for( int i = 0 ; i < 8 ; i++ )
  {
    hetmans[i].rect = load_image( "rect.jpg" );
    hetmans[i].queen = load_image( "Queen.jpg" );
  }
}

void clean_up()
{
  //Free the surfaces
  SDL_FreeSurface( background );
  for( int i = 0 ; i < 8 ; i++ )
  {
    SDL_FreeSurface( hetmans[i].rect );
    SDL_FreeSurface( hetmans[i].queen );
  }

  //Quit SDL
  SDL_Quit();
}




void game_loop()
{
  bool quit = false;
  while( quit == false )
  {
    while( SDL_PollEvent( &event ) )
    {
      if( event.type == SDL_QUIT )
      {
        quit = true;
      }
      if(event.type == SDL_KEYDOWN)
      {
        SDLKey keyPressed = event.key.keysym.sym;
        switch(keyPressed)
        {
          case SDLK_RETURN:
            if(n == 7)
            {hetman(); n= 0;
              break;}
            n++;break;
          case SDLK_ESCAPE:
            SDL_Quit();
          case SDLK_UP: hetmans[n].yVel -= 5; break;
          case SDLK_DOWN: hetmans[n].yVel += 5; break;
          case SDLK_LEFT: hetmans[n].xVel -= 5; break;
          case SDLK_RIGHT: hetmans[n].xVel += 5; break;

        }
      }
      //If a key was released
      else if( event.type == SDL_KEYUP )
      {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
          case SDLK_UP: hetmans[n].yVel += 5; break;
          case SDLK_DOWN: hetmans[n].yVel -= 5; break;
          case SDLK_LEFT: hetmans[n].xVel += 5; break;
          case SDLK_RIGHT:hetmans[n]. xVel -= 5; break;
        }
      }
    }
    hetmans[n].move();
    apply_surface( (n*118.75), (hetmans[n].dest_y*96.25), hetmans[n].rect, screen );
    for( int i = 0 ; i <= n ; i++ )
    {
      hetmans[i].show();
    }
    //Update the screen
    SDL_Flip( screen );
    //Apply the background to the screen
    apply_surface( 0, 0, background, screen );
  }
}

int main( int argc, char* args[] )
{
  init();
  load_files();

  ustaw(0);


  //Free the surfaces and quit SDL
  clean_up();

  return 0;
}
