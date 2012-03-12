#include "h_class.hpp"
#include "h_sdl.cpp"

int main( int argc, char* args[] )
{
	init();
	load_files();
	
	ustaw(0);


    //Free the surfaces and quit SDL
    clean_up();

    return 0;
}
