/* Stave.cpp
Author: Joshua Prendergast */

#include "Stave.h"
#include "RenderComponent.h"
#include "Texture.h"
#include "Note.h"

namespace sight {

Stave::Stave(Game *game) : Entity(game), arrangement(2) {
    Texture *clef = new Texture(game->getRenderer(), "treble_clef.png");
    Texture *stave = new Texture(game->getRenderer(), "stave.png");

    clef->setOffset(20, 30);

    addComponent(new RenderComponent(this, stave));
    addComponent(new RenderComponent(this, clef));

    arrangement.randomize();
    refreshArrangement();
}

Stave::~Stave() {
}

void Stave::update() {
    Entity::update();

}

void Stave::start() {
    currentNote = 0;
    running = true;
}

void Stave::refreshArrangement() {
    Entity::destroyChildren();

    int i = 0;
    auto noteValues = arrangement.getNoteValues();
    for (auto it = noteValues.begin(); it != noteValues.end(); ++it) {
        int value = *it;

        Note *note = new Note(game, this, value);
        note->setLocalPosition((50 * i) + 100, (value * 9) - 5);

        addChild(note);
        game->addEntity(note);
        i++;
    }
}

}