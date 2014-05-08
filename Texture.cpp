/* Texture.cpp
Author: Joshua Prendergast */

#include "Texture.h"
#include "util.h"

namespace sight {

const std::string Texture::TEXTURE_FOLDER = "textures/";

Texture::Texture(SDL_Renderer *renderer, const std::string &filename) : texture(NULL) {
    load(renderer, filename);
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

int Texture::load(SDL_Renderer *renderer, const std::string &filename) {
    SDL_Surface *surface = IMG_Load((TEXTURE_FOLDER + filename).c_str());
    if (surface) {
    	/* Fill render rects */
    	srcR.x = dstR.x = 0;
    	srcR.y = dstR.y = 0;
    	srcR.w = dstR.w = surface->w;
    	srcR.h = dstR.h = surface->h;

        memcpy(&originalDimensions, &srcR, sizeof(SDL_Rect));

    	texture = SDL_CreateTextureFromSurface(renderer, surface);
    	SDL_FreeSurface(surface);
    	return 1;
    }
    printSdlError();
    return 0;
}

void Texture::render(SDL_Renderer *renderer, Vector2f &pos) {
    dstR.x = pos.x + offset.x;
    dstR.y = pos.y + offset.y;
    
	SDL_RenderCopy(renderer, texture, &srcR, &dstR);
}

SDL_Rect &Texture::getOriginalDimensions() {
    return originalDimensions;
}

void Texture::setSrcSubRect(SDL_Rect &srcR) {
    memcpy(&this->srcR, &srcR, sizeof(SDL_Rect));
}

void Texture::setDstSubRect(SDL_Rect &dstR) {
    memcpy(&this->dstR, &dstR, sizeof(SDL_Rect));
}

void Texture::setOffset(Vector2f &offset) {
    this->offset = offset;
}

Vector2f &Texture::getOffset() {
    return offset;
}

SDL_Rect &Texture::getSrcSubRect() {
    return srcR;
}

SDL_Rect &Texture::getDstSubRect() {
    return dstR;
}

}
