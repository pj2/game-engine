/* Note.cpp
Author: Joshua Prendergast */

#ifndef NOTE_CPP
#define NOTE_CPP

#include "Note.h"

namespace sight {

Note::Note(Game *game, Entity *parent, int value) : ParentableEntity(game, parent), value(value) {
    addComponent(new RenderComponent(this, new Texture(game->getRenderer(), "crochet.png")));
}

Note::~Note() {
}

}

#endif // NOTE_CPP
