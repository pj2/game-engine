/* Entity.cpp
Author: Joshua Prendergast */

#ifndef ENTITY_H
#define ENTITY_H

#include "RenderComponent.h"
#include <SDL2/SDL.h>

namespace sight {

class Entity {
public:
    Entity(RenderComponent *renderc);
    virtual ~Entity();
    virtual void update();
    virtual void render(SDL_Window &window);
private:
    RenderComponent *renderc;
};

}

#endif // ENTITY_H
