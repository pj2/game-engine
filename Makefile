CC=g++
PROJECT=sight-reader
LFLAGS=-L/usr/lib64 -lm -lSDL2 -lSDL2_image
CFLAGS=-Wall -std=gnu++0x -g -I/usr/include -Iinclude

PHONY: all

all: Entity.o Game.o Texture.o main.o
	$(CC) $(CFLAGS) -o $(PROJECT) $^ $(LFLAGS)

$.o: $.cpp
	$(CC) -c -o $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f $(PROJECT)