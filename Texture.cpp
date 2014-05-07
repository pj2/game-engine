/* Texture.cpp
Author: Joshua Prendergast */

#include "Texture.h"

namespace sight {

Texture::Texture(SDL_Renderer *renderer, const std::string &filename) {
    load(renderer, filename);
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

int Texture::load(SDL_Renderer *renderer, const std::string &filename) {
    SDL_Surface *surface = IMG_Load(filename.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
}

void Texture::render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, )
}

}