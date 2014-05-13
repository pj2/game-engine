/* Note.h
Author: Joshua Prendergast */

#ifndef NOTE_H
#define NOTE_H

#include "Game.h"
#include "AnchorableEntity.h"
#include "RenderComponent.h"

namespace sight {

class Note : public AnchorableEntity {
public:
    Note(Game *game, Entity *parent, int value);
    ~Note();
    void setHighlight(bool highlight);
private:
    int value;
    RenderComponent *marker;
};

}

#endif // NOTE_H
