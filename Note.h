/* Note.h
Author: Joshua Prendergast */

#ifndef NOTE_H
#define NOTE_H

#include "Game.h"
#include "Entity.h"

namespace sight {

class Note : public Entity {
public:
    Note(Game *game);
    ~Note();
};

}

#endif // NOTE_H
