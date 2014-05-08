/* Background.h
Author: Joshua Prendergast */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Entity.h"
#include "RenderComponent.h"
#include "SDL/SDL.h"
#include "Vector.h"

namespace sight {

class Background : public Entity {
public:
    Background(Game *game);
    virtual ~Background();
    void render(SDL_Renderer *renderer);
};

}

#endif // BACKGROUND_H