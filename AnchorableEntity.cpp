/* AnchorableEntity.cpp
Author: Joshua Prendergast */

#include "AnchorableEntity.h"

namespace sight {

AnchorableEntity::AnchorableEntity(Game *game, Entity *anchor) : Entity(game), anchor(anchor) {
}

AnchorableEntity::~AnchorableEntity() {
}

void AnchorableEntity::update() {
    /* Follow anchor around */
    if (anchor) {
        Vector2f &anchorPos = anchor->getPosition();
        setPosition(anchorPos.x + localPos.x, anchorPos.y + localPos.y);
    }
}

void AnchorableEntity::setLocalPosition(float x, float y) {
    this->localPos.x = x;
    this->localPos.y = y;
}

void AnchorableEntity::setLocalPosition(Vector2f &pos) {
    setLocalPosition(pos.x, pos.y);

}
void AnchorableEntity::setAnchor(Entity *anchor) {
    this->anchor = anchor;

}
Entity *AnchorableEntity::getAnchor() {
    return anchor;
}

}