/* renderables.h
Author: Joshua Prendergast */

#ifndef RENDERABLES_H
#define RENDERABLES_H

#include <GL/glut.h>

typedef struct {
	GLuint stave;
	GLuint note;
} render_objs;

render_objs render_init();

void render_cleanup();

GLuint render_gen_stave(GLuint id);

GLuint render_gen_note(GLuint id);

/* Shortcut to add a pair of vertices to a GL_BEGIN / GL_END segment */
void render_line(float x1, float y1, float x2, float y2);

/* Render a single line in a new GL_BEGIN / GL_END segment */
void render_line_simple(float x1, float y1, float x2, float y2);

void render_circle(float cx, float cy, float r, int segments);

#endif