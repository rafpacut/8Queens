.PHONY: hetmani.e
h_class.o: h_class.hpp h_class.cpp
	g++ -c h_class.cpp `sdl-config --cflags --libs` -o h_class.o
hetmani.e: h_class.o h_sdl.cpp main.cpp   
	g++ main.cpp h_class.o `sdl-config --cflags --libs` -lSDL_image -o hetmani.e
