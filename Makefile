CC=gcc
PROJECT=sight-reader
LFLAGS=-L/usr/lib64 -lglut -lGL -lm
CFLAGS=-Wall -g -I/usr/include -Iinclude

PHONY: all

all: game.o main.o node.o renderables.o window.o
	$(CC) $(CFLAGS) -o $(PROJECT) $^ $(LFLAGS)

$.o: $.c
	$(CC) -c $(CFLAGS) -o $<
