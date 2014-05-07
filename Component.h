/* Component.h
Author: Joshua Prendergast */

#ifndef COMPONENT_H
#define COMPONENT_H

namespace sight {

class Entity;

class Component {
public:
    Component(Entity *owner) : owner(owner);
private:
    Entity *owner;
};

}

#endif // COMPONENT_H
