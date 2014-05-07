/* Entity.h
Author: Joshua Prendergast */

#include "Entity.h"

namespace sight {

Entity::Entity(Game *game, RenderComponent *renderc) : game(game), renderc(renderc) {
}

Entity::~Entity() {
    delete renderc;
}

void Entity::update() {
}

void Entity::render(SDL_Renderer *renderer) {
    if (renderc) 
        renderc->render(renderer);
}

}