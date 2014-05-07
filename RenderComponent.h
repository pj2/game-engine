/* RenderComponent.h
Author: Joshua Prendergast */

#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "Renderable.h"
#include <SDL2/SDL.h>

namespace sight {

class Entity;

class RenderComponent : public Renderable, public Component {
public:
	RenderComponent(Entity *owner);
};

}

#endif // RENDERCOMPONENT_H
