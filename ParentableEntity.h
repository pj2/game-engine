/* ParentableEntity.h
Author: Joshua Prendergast */

#ifndef PARENTABLE_ENTITY_H
#define PARENTABLE_ENTITY_H

#include "Entity.h"

namespace sight {

class Game;

class ParentableEntity : public Entity {
public:
    ParentableEntity(Game *game, Entity *parent);
    virtual ~ParentableEntity();
    virtual void update();
    void setLocalPosition(float x, float y);
    void setLocalPosition(Vector2f &pos);
    void setParent(Entity *parent);
    Entity *getParent();
private:
    Entity *parent;
    Vector2f localPos;
};

}

#endif // PARENTABLE_ENTITY_H