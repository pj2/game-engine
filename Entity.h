/* Entity.cpp
Author: Joshua Prendergast */

#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include "RenderComponent.h"
#include <SDL2/SDL.h>
#include <map>

namespace sight {

class Game;

class Entity {
public:
    Entity(Game *game);
    virtual ~Entity();
    virtual void update();
    virtual void render(SDL_Renderer *window);
    void addComponent(Component *component);
    void setPosition(float x, float y);
    void setPosition(Vector2f &pos);
    Vector2f &getPosition();
protected:
    Vector2f pos;
private:
    Game *game;
    std::multimap<int, Component *> components;
};

}

#endif // ENTITY_H
