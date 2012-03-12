.PHONY: hetmani.e
hetmani.e: h_class.hpp h_sdl.cpp main.cpp   
	g++ main.cpp  `sdl-config --cflags --libs` -lSDL_image -o hetmani.e
