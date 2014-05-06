/* renderables.c
Author: Joshua Prendergast */

#include "game.h"
#include "renderables.h"
#include "vector.h"
#include <math.h>

#include <GL/glut.h>

render_objs render_init() {
	render_objs out;
	GLuint first = glGenLists(2);
	out.stave = render_gen_stave(first);
	out.note = render_gen_note(first+1);

	return out;
}

void render_cleanup(render_objs *ro) {
	glDeleteLists(ro->stave, 2);
}

GLuint render_gen_stave(GLuint id) {
	int i;

	glNewList(id, GL_COMPILE);
	glBegin(GL_LINES);

	glColor3f(0, 0, 0);

	/* Vertical lines */
	render_line(0.0f, 0.0f, 0.0f, (STAVE_LINES - 1) * STAVE_GAP);
	render_line(STAVE_LENGTH, 0.0f, STAVE_LENGTH, (STAVE_LINES - 1) * STAVE_GAP);

	/* Draw individual horizontal lines */
	for (i = 0; i < STAVE_LINES; i++) {
		render_line(0, STAVE_GAP * i, STAVE_LENGTH, STAVE_GAP * i);
	}

	glEnd();
	glEndList();
	return id;
}

GLuint render_gen_note(GLuint id) {
	glNewList(id, GL_COMPILE);
	render_circle(1.5f, 1.5f, STAVE_GAP / 2, 25);
	glEndList();
	return id;
}

void render_line(float x1, float y1, float x2, float y2) {
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
}

void render_line_simple(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	render_line(x1, y1, x2, y2);
	glEnd();
}

void render_circle(float cx, float cy, float r, int segments) {
	// See http://slabode.exofire.net/circle_draw.shtml
	int i;

	float theta = 2 * 3.1415926 / (float) segments;
	float c = cos(theta);
	float s = sin(theta);
	float t;

	float x = r;
	float y = 0;

	glBegin(GL_LINE_LOOP);
	for (i = 0; i < segments; i++) {
		glVertex2f(x + cx, y + cy);

		// Apply rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}