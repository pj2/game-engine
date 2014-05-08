/* Note.h
Author: Joshua Prendergast */

#ifndef NOTE_H
#define NOTE_H

#include "Game.h"
#include "ParentableEntity.h"

namespace sight {

class Note : public ParentableEntity {
public:
    Note(Game *game, Entity *parent, int value);
    ~Note();
private:
    int value;
};

}

#endif // NOTE_H
