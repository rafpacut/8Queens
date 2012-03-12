.PHONY: hetmani.e

all: hetmani.e

h_sdl.o: h_sdl.hpp h_sdl.cpp
	g++ -c h_sdl.cpp `sdl-config --cflags --libs` -o h_sdl.o

h_class.o: h_sdl.o h_class.hpp h_class.cpp
	g++ -c h_class.cpp h_sdl.o `sdl-config --cflags --libs` -o h_class.o

hetmani.e: h_class.o main.cpp   
	g++ main.cpp h_class.o `sdl-config --cflags --libs` -lSDL_image -o hetmani.e

clear:
	rm -f *.o *.e
