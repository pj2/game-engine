/* Stave.h
Author: Joshua Prendergast */

#ifndef STAVE_H
#define STAVE_H

#include "Entity.h"
#include "Game.h"
#include "Note.h"
#include <vector>

namespace sight {

class Stave : public Entity {
public:
    Stave(Game *game);
    ~Stave();
    void update();
    void start();
    void refreshArrangement();
private:
    std::vector<Note *> notes;
    int currentNote;
    int length;
    bool running;
};

}

#endif // STAVE_H
