/* AnchorableEntity.h
Author: Joshua Prendergast */

#ifndef ANCHORABLE_ENTITY_H
#define ANCHORABLE_ENTITY_H

#include "Entity.h"

namespace sight {

class Game;

class AnchorableEntity : public Entity {
public:
    AnchorableEntity(Game *game, Entity *anchor);
    virtual ~AnchorableEntity();
    virtual void update();
    void setLocalPosition(float x, float y);
    void setLocalPosition(Vector2f &pos);
    void setAnchor(Entity *anchor);
    Entity *getAnchor();
private:
    Entity *anchor;
    Vector2f localPos;
};

}

#endif // ANCHORABLE_ENTITY_H