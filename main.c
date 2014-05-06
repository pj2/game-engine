/* main.c
Author: Joshua Prendergast */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "window.h"
#include "game.h"

int main(int argc, char **argv) {
	window_init(&argc, argv);
	game_init();

	printf("Entering main loop\n");
	window_start();

	return 0;
}