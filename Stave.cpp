/* Stave.cpp
Author: Joshua Prendergast */

#include "Stave.h"
#include "RenderComponent.h"
#include "Texture.h"

namespace sight {

Stave::Stave(Game *game) : Entity(game), notes() {
    Vector2f offset = {20, -30};

    Texture *stave = new Texture(game->getRenderer(), "stave.png");
    Texture *clef = new Texture(game->getRenderer(), "treble_clef.png");

    clef->setOffset(offset);

    addComponent(new RenderComponent(this, stave));
    addComponent(new RenderComponent(this, clef));
}

Stave::~Stave() {
}

void Stave::update() {
    Entity::update();


}

}