/* Entity.h
Author: Joshua Prendergast */

#include "Entity.h"

namespace sight {

Entity::Entity(Game *game) : game(game), autoDelete(true) {
}

Entity::~Entity() {
    for (auto it = components.begin(); it != components.end(); ++it) {
        delete it->second;
    }
    destroyChildren();
}

void Entity::update() {
}

void Entity::render(SDL_Renderer *renderer) {
    auto pair = components.equal_range(COMPONENT_RENDER);
    for (auto it = pair.first; it != pair.second; ++it) {
        ((RenderComponent *) it->second)->render(renderer, pos);
    }
}

void Entity::addComponent(Component *component) {
    components.insert(std::pair<int, Component *>(component->getType(), component));
}

void Entity::addChild(Entity *entity) {
    children.push_back(entity);
    entity->setAutoDelete(false);
}

void Entity::destroyChildren() {
    for (auto it = children.begin(); it != children.end(); ++it) {
        delete *it;
    }
}

void Entity::setPosition(float x, float y) {
    pos.x = x;
    pos.y = y;
}

void Entity::setPosition(Vector2f &pos) {
    this->pos = pos;
}

Vector2f &Entity::getPosition() {
    return pos;
}

void Entity::setAutoDelete(bool autoDelete) {
    this->autoDelete = autoDelete;
}

bool Entity::isAutoDelete() {
    return autoDelete;
}

}