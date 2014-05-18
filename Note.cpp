/* Note.cpp
Author: Joshua Prendergast */

#ifndef NOTE_CPP
#define NOTE_CPP

#include "Note.h"
#include "Text.h"

namespace sight {

std::string Note::NOTES[] = {"C", "D", "E", "F", "G", "A", "B"};

Note::Note(Game *game, Entity *parent, int value, int modifiers) : AnchorableEntity(game, parent), value(value), modifiers(modifiers) {
    addComponent(new RenderComponent(this, new Texture(game->getRenderer(), "crochet.png")));

    Texture *texture = new Texture(game->getRenderer(), "marker.png");
    texture->setPosition(10, -15);

    marker = new RenderComponent(this, texture);
    marker->setVisible(false);
    addComponent(marker);

    Text *text = new Text(game->getRenderer(), game->getStdFont(), Note::getNoteName(value, modifiers));
    text->setPosition(10, 70);

    label = new RenderComponent(this, text);
    addComponent(label);
}

Note::~Note() {
}

void Note::setHighlight(bool highlight) {
    marker->setVisible(highlight);
}

std::string Note::getNoteName(int value, int modifiers) {
    return NOTES[value % 7];
}

}

#endif // NOTE_CPP
