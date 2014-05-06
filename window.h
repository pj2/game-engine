/* window.h
Author: Joshua Prendergast */

#ifndef WINDOW_H
#define WINDOW_H

void window_init(int *argc, char **argv);
void window_start();
void window_update(int value);
void window_display();
void window_idle();
void window_reshape(int w, int h);

#endif