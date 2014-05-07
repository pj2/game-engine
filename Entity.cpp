/* Entity.h
Author: Joshua Prendergast */

#include "Entity.h"

namespace sight {

Entity::Entity(RenderComponent *renderc) : renderc(renderc) {
}

Entity::~Entity() {
}

void Entity::update() {
    
}

void Entity::render(SDL_Window &window) {
    if (renderc) 
            renderc->render(window);
}

}