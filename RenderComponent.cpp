/* RenderComponent.cpp
Author: Joshua Prendergast */

#include "RenderComponent.h"

namespace sight {

RenderComponent::RenderComponent(Entity *owner, Renderable *renderable) : Component(owner), renderable(renderable) {
}

RenderComponent::~RenderComponent() {
    delete renderable;
}

void RenderComponent::render(SDL_Renderer *renderer, Vector2f &pos) {
    renderable->render(renderer, pos);
}

int RenderComponent::getType() const {
    return COMPONENT_RENDER;
}

}