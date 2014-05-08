/* Note.cpp
Author: Joshua Prendergast */

#ifndef NOTE_CPP
#define NOTE_CPP

#include "Note.h"

namespace sight {

Note::Note(Game *game) : Entity(game) {
    addComponent(new RenderComponent(this, new Texture(game->getRenderer(), "note.png")));
}

Note::~Note() {
}

}

#endif // NOTE_CPP
