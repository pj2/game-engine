/* Text.cpp
Author: Joshua Prendergast */ 

#include "Text.h"

namespace sight {

Text::Text(SDL_Renderer *renderer, Font *font) : Texture(renderer), font(font) {
}

Text::Text(SDL_Renderer *renderer, Font *font, const std::string &text) : Texture(renderer), font(font), text(text) {
    rebuild();
}

Text::~Text() {
}

void Text::rebuild() {
    // Something was changed; re-create the texture
    SDL_Surface *surface = TTF_RenderText_Solid(font->getSDLFont(), text.c_str(), color);

    Texture::createTexture(surface);
}

void Text::setFont(Font *font) {
    this->font = font;
}

Font *Text::getFont() {
    return font;
}

void Text::setText(const std::string &text) {
    this->text = text;
}

std::string &Text::getText() {
    return text;
}

void Text::setColor(SDL_Color color) {
    this->color = color;
}

SDL_Color &Text::getColor() {
    return color;
}

}