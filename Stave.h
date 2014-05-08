/* Stave.h
Author: Joshua Prendergast */

#ifndef STAVE_H
#define STAVE_H

#include "Entity.h"
#include "Game.h"
#include <vector>

namespace sight {

class Stave : public Entity {
public:
    Stave(Game *game);
    ~Stave();
    void update();
private:
    int length;
    std::vector<int> notes;
};

}

#endif // STAVE_H
