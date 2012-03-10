.PHONY: hetmani.o
z1_for_500pts.o: hetmani.cpp hetmani.hpp 
	g++ hetmani.cpp  `sdl-config --cflags --libs` -lSDL_image -o hetmani.o
