/* Stave.h
Author: Joshua Prendergast */

#ifndef STAVE_H
#define STAVE_H

#include "Entity.h"
#include "Game.h"
#include "Arrangement.h"
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
    void destroyNotes();
private:
    Arrangement arrangement;
    std::vector<Note *> notes;
    int currentNote;
    bool running;
};

}

#endif // STAVE_H
