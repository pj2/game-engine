/* Component.h
Author: Joshua Prendergast */

#ifndef COMPONENT_H
#define COMPONENT_H

namespace sight {

class Entity;

class Component {
public:
    Component(Entity *owner);
    virtual ~Component() {};
    virtual int getType() const = 0; // Returns a unique type identifier
private:
    Entity *owner;
};

}

#endif // COMPONENT_H
