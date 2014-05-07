/* Background.h
Author: Joshua Prendergast */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Entity.h"

namespace sight {

class Background : public Entity {
public:
    Background(Game *game);
    virtual ~Background();
private:
};

}

#endif // BACKGROUND_H