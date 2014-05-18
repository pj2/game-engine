/* RenderComponent.h
Author: Joshua Prendergast */

#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "Renderable.h"
#include "Vector.h"
#include "Component.h"
#include "Entity.h"

#define COMPONENT_RENDER 1

namespace sight {

class RenderComponent : public Component {
public:
	RenderComponent(Entity *owner, Renderable *renderable);
    ~RenderComponent();
    void render();
    int getType() const;
    void setVisible(bool visible);
    bool getVisible();
    Renderable *getRenderable();
private:
    Renderable *renderable;
    bool visible;
};

}

#endif // RENDERCOMPONENT_H
