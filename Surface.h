/* Surface.h
Author: Joshua Prendergast */

#ifndef SURFACE_H
#define SURFACE_H

#include <SDL2/SDL.h>

namespace sight {

class Surface {
public:
    Surface(int w, int h);
    ~Surface();
private:
    SDL_Surface *surface;
};

}

#endif // SURFACE_H
