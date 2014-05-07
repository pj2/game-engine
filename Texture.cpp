/* Texture.cpp
Author: Joshua Prendergast */

#include "Texture.h"

namespace sight {

Texture::Texture(SDL_Renderer *renderer, const std::string &filename) : texture(NULL) {
    load(renderer, filename);
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

int Texture::load(SDL_Renderer *renderer, const std::string &filename) {
    SDL_Surface *surface = IMG_Load(filename.c_str());
    if (surface) {
    	/* Fill render rects */
    	srcR.x = dstR.x = 0;
    	srcR.y = dstR.y = 0;
    	srcR.w = dstR.w = surface->w;
    	srcR.h = dstR.h = surface->h;

    	texture = SDL_CreateTextureFromSurface(renderer, surface);
    	SDL_FreeSurface(surface);
    	return 1;
    }
    return 0;
}

void Texture::render(SDL_Renderer *renderer, Vector2f &pos) {
    dstR.x = pos.x;
    dstR.y = pos.y;
    
	SDL_RenderCopy(renderer, texture, srcR, dstR);
}

}