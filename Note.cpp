/* Note.cpp
Author: Joshua Prendergast */

#ifndef NOTE_CPP
#define NOTE_CPP

#include "Note.h"

namespace sight {

Note::Note(Game *game, Entity *parent, int value) : AnchorableEntity(game, parent), value(value) {
    addComponent(new RenderComponent(this, new Texture(game->getRenderer(), "crochet.png")));

    Texture *tex = new Texture(game->getRenderer(), "marker.png");
    tex->setOffset(10, -15);

    marker = new RenderComponent(this, tex);
    marker->setVisible(false);
    addComponent(marker);
}

Note::~Note() {
}

void Note::setHighlight(bool highlight) {
    marker->setVisible(highlight);
}

}

#endif // NOTE_CPP
