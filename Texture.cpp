/* Texture.cpp
Author: Joshua Prendergast */

#include "Texture.h"
#include "util.h"

namespace sight {

const std::string Texture::TEXTURE_FOLDER = "textures/";

Texture::Texture(SDL_Renderer *renderer) : Renderable(renderer), texture(NULL) {
}

Texture::Texture(SDL_Renderer *renderer, SDL_Surface *surface) : Renderable(renderer) {
    createTexture(surface);
}

Texture::Texture(SDL_Renderer *renderer, const std::string &filename) : Renderable(renderer) {
    createTexture(filename);
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

void Texture::createTexture(SDL_Surface *surface) {
    if (surface) {
        /* Fill render rects */
        setWidth(surface->w);
        setHeight(surface->h);

        texture = SDL_CreateTextureFromSurface(getRenderer(), surface);

        setBlendMode(SDL_BLENDMODE_BLEND);
    } else {
        throw std::runtime_error("failed to load texture");
    }
}

void Texture::createTexture(const std::string &filename) {
    SDL_Surface *surf = IMG_Load((TEXTURE_FOLDER + filename).c_str()); // Load surface from image file
    
    createTexture(surf);
    SDL_FreeSurface(surf);
}

void Texture::render(Vector2f pos) {
    SDL_Rect r = getDstRect();
    r.x += pos.x;
    r.y += pos.y;

    if (texture)
        SDL_RenderCopy(getRenderer(), texture, getSrcRect(), &r);
}

void Texture::setBlendMode(SDL_BlendMode blendMode) {
    SDL_SetTextureBlendMode(texture, blendMode);
}

SDL_BlendMode Texture::getBlendMode() {
    SDL_BlendMode out;
    SDL_GetTextureBlendMode(texture, &out);
    return out;
}

}
