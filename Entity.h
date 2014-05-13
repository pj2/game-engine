/* Entity.h
Author: Joshua Prendergast */

#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include "RenderComponent.h"
#include <SDL2/SDL.h>
#include <map>
#include <list>

namespace sight {

class Game;

class Entity {
public:
    Entity(Game *game);
    virtual ~Entity();

    /**
     * @brief Performs entity logic
     */
    virtual void update();

    /**
     * @brief Renders the entity
     * @param renderer The target renderer
     */
    virtual void render(SDL_Renderer *renderer);

    /**
     * @brief Registers a new component to this entity
     * @param component The new component
     */
    void addComponent(Component *component);

    /**
     * @brief Adds an entity as a child of this entity
     * @details Child entities have their lifetime tied to their parent. By default, all entities last until
     * the engine stops or they are explicitly removed. An entity may have one parent only.
     * 
     * @param entity The child
     */
    void addChild(Entity *entity);

    /**
     * @brief Deletes every child of this entity
     */
    void destroyChildren();
    
    void setPosition(float x, float y);
    void setPosition(Vector2f &pos);
    Vector2f &getPosition();
    void setAutoDelete(bool autoDelete);
    bool isAutoDelete();
protected:
    Vector2f pos;
    Game *game;
    std::multimap<int, Component *> components;
    std::list<Entity *> children;
    bool autoDelete; // True if the engine is reponsible for deleting this entity
};

}

#endif // ENTITY_H
