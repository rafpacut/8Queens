#include<SDL.h>
#include "SDL/SDL_image.h"
#include<string>
#include "hetmani.hpp"



//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

//Screen attributes
const int SCREEN_WIDTH = 950;
const int SCREEN_HEIGHT = 770;
const int SCREEN_BPP = 32;
//numer hetmana
int n = 0;
SDL_Event event;

//------------------------------------------------------------------------------------------------------------------------------------------------------

hetman::hetman()
{
    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;
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


//--------------------------------------------------------------------------------------------------------------------------------------------------

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
}//------------------------------------------------------------------------------------------------------------------------------------------------
void hetman::show()
{
    apply_surface( x, y, hetmans[n].queen, screen );
}//------------------------------------------------------------------------------------------------------------------------------------------------

void init()
{
	SDL_Init( SDL_INIT_EVERYTHING );

    //Set up the screen
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    //Set the window caption
    SDL_WM_SetCaption( "Osmiu hetmanow", NULL );

}

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

int main( int argc, char* args[] )
{
	init();
	load_files();
	
	ustaw(0);


    //Free the surfaces and quit SDL
    clean_up();

    return 0;
}
