/* RenderComponent.cpp
Author: Joshua Prendergast */

#include "RenderComponent.h"

namespace sight {

RenderComponent::RenderComponent(Entity *owner, Renderable *renderable) : Component(owner), renderable(renderable), visible(true) {
}

RenderComponent::~RenderComponent() {
    delete renderable;
}

void RenderComponent::render() {
    if (visible)
        renderable->render(owner->getPosition());
}

int RenderComponent::getType() const {
    return COMPONENT_RENDER;
}

void RenderComponent::setVisible(bool visible) {
    this->visible = visible;
}

bool RenderComponent::getVisible() { 
    return visible;
}

}