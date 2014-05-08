/* Stave.cpp
Author: Joshua Prendergast */

#include "Stave.h"
#include "RenderComponent.h"
#include "Texture.h"
#include "Note.h"

namespace sight {

Stave::Stave(Game *game) : Entity(game), arrangement(2) {
    Texture *clef = new Texture(game->getRenderer(), "treble_clef.png");
    staveTexture = new Texture(game->getRenderer(), "stave.png");

    Vector2f offset = {20, 30};
    clef->setOffset(offset);

    addComponent(new RenderComponent(this, staveTexture));
    addComponent(new RenderComponent(this, clef));

    arrangement.randomize();
    refreshArrangement();
}

Stave::~Stave() {
    destroyNotes(); // TODO, fix segfault on game destroy
}

void Stave::update() {
    Entity::update();
}

void Stave::refreshArrangement() {
    destroyNotes();

    int staveHeight = staveTexture->getDstSubRect().y;
    int i = 0;
    auto noteValues = arrangement.getNoteValues();
    for (auto it = noteValues.begin(); it != noteValues.end(); ++it) {
        int value = *it;

        Note *note = new Note(game, this, value);
        note->setLocalPosition((50 * i) + 100, (value * 9) - 5);

        notes.push_back(note);
        game->addEntity(note);

        i++;
    }
}

void Stave::destroyNotes() {
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        delete *it;
    }
}

}