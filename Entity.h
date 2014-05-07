/* Entity.cpp
Author: Joshua Prendergast */

#ifndef ENTITY_H
#define ENTITY_H

#include "RenderComponent.h"
#include <SDL2/SDL.h>

namespace sight {

class Entity {
public:
    Entity(Game *game, RenderComponent *renderc);
    virtual ~Entity();
    virtual void update();
    virtual void render(SDL_Renderer *window);
private:
    Game *game;
    RenderComponent *renderc;
};

}

#endif // ENTITY_H
