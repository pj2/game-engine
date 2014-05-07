/* Renderable.h
Author: Joshua Prendergast */

#ifndef RENDERABLE_H
#define RENDERABLE_H

namespace sight {

class Renderable {
public:
    virtual void render(SDL_Renderer *renderer) = 0;
};

}

#endif // RENDERABLE_H
