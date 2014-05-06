/* game.h
Author: Joshua Prendergast */

#ifndef GAME_H
#define GAME_H

#define STAVE_BARS 2
#define STAVE_LENGTH 400.0f
#define STAVE_LINES 5
#define STAVE_GAP 25

#include "node.h"
#include "renderables.h"

typedef struct {
	long ticks;
	unsigned int tempo; /* Ticks per bar */
	unsigned int notes[8];
	render_objs ro;
} game;

void game_init();

void game_exit();

void game_update();

void game_next_notes(unsigned int notes[], int size);

void game_render_stave();

void game_render_notes();

game *game_get();

#endif
