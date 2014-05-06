/* game.c
Author: Joshua Prendergast */

#include <stdlib.h>
#include "game.h"

void game_init() {
	game *g = game_get();
	game_next_notes(g->notes, 8);
	g->ro = render_init();

	atexit(&game_exit);
}

void game_exit() {
	render_cleanup(game_get()->ro);
}

void game_update() {
	game *g = game_get();
	g->ticks++;

	glutPostRedisplay();
}

void game_next_notes(unsigned int notes[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		notes[i] = rand() % 13;
	}
}

void game_render_stave() {
	glPushMatrix();
	glTranslatef(10, 10, 0);
	glCallList(game_get()->ro.stave);
	glPopMatrix();
}

void game_render_notes() {
	glPushMatrix();
	glTranslatef(40, 40, 0);
	glCallList(game_get()->ro.note);
	glPopMatrix();
}

game *game_get() {
	static game g;
	return &g;
}