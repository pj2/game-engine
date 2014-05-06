/* window.c
Author: Joshua Prendergast */

#include "game.h"
#include "window.h"

void window_init(int *argc, char **argv) {
	/* Create GLUT window */
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	// glutInitWindowPosition(100, 300);
	glutCreateWindow("SightReader");

	glutDisplayFunc(&window_display);
	glutTimerFunc(1000.0f / 30.0f, &window_update, 0);
	glutReshapeFunc(&window_reshape);
	glutIdleFunc(&window_idle);

	glClearColor(0.75f, 0.75f, 0.75f, 0.75f);
}

void window_start() {
	glutMainLoop();
}

 /* Update game state; called every 1/30s */
void window_update(int value) {
	game_update();
}

/* Render a frame */
void window_display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game_render_stave();
	game_render_notes();

	glutSwapBuffers();
}

void window_idle() {
}

void window_reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, w, h, 0.0f, -1.0f, 1.0f); // Set origin to top-left
}