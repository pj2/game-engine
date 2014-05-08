/* ParentableEntity.cpp
Author: Joshua Prendergast */

#include "ParentableEntity.h"

namespace sight {

ParentableEntity::ParentableEntity(Game *game, Entity *parent) : Entity(game), parent(parent) {
}

ParentableEntity::~ParentableEntity() {
}

void ParentableEntity::update() {
    /* Follow parent around */
    if (parent) {
        Vector2f &parentPos = parent->getPosition();
        setPosition(parentPos.x + localPos.x, parentPos.y + localPos.y);
    }
}

void ParentableEntity::setLocalPosition(float x, float y) {
    this->localPos.x = x;
    this->localPos.y = y;
}

void ParentableEntity::setLocalPosition(Vector2f &pos) {
    setLocalPosition(pos.x, pos.y);

}
void ParentableEntity::setParent(Entity *parent) {
    this->parent = parent;

}
Entity *ParentableEntity::getParent() {
    return parent;
}

}