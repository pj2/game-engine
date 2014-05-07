/* Renderable.h
Author: Joshua Prendergast */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "Vector.h"

namespace sight {

class Renderable {
public:
    virtual void render(SDL_Renderer *renderer, Vector2f &pos) = 0;
};

}

#endif // RENDERABLE_H
