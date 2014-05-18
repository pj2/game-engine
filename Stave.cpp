/* Stave.cpp
Author: Joshua Prendergast */

#include "Stave.h"
#include "RenderComponent.h"
#include "Texture.h"
#include "Note.h"

namespace sight {

Stave::Stave(Game *game) : Entity(game), length(8) {
    Texture *clef = new Texture(game->getRenderer(), "treble_clef.png");
    Texture *stave = new Texture(game->getRenderer(), "stave.png");

    clef->setPosition(20, 30);

    addComponent(new RenderComponent(this, stave));
    addComponent(new RenderComponent(this, clef));

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

    int offsets[] = {115, 103, 92, 79, 68, 55, 43};
    for (int i = 0; i < length; i++) {
        int value = (rand() % 24) / 2;

        Note *note = new Note(game, this, value, 0);
        note->setLocalPosition(120 + i * 55, 119 - (10 * value / 2) - (13 * (value + 1) / 2));

        addChild(note);
        game->addEntity(note);
    }
}

}