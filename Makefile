CC=g++
PROJECT=sight-reader
LFLAGS=-L/usr/lib64 -lm -lSDL2 -lSDL2_image
CFLAGS=-Wall -std=gnu++0x -g -I/usr/include -Iinclude
OBJS=$(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(OBJS)
	$(CC) -o $(PROJECT) $^ $(LFLAGS) $(CFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o
	rm -f $(PROJECT)