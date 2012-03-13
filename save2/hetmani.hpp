//g++ hetmani.cpp `sdl-config --cflags --libs` -lSDL_image -o  hetmani.o

#include <iostream>
#include <SDL.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//The dimensions of the queen
const int hetman_width = 10;
const int hetman_height = 10;


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
vector<hetman> hetmans( 8, hetman() );


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
