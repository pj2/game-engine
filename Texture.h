/* Texture.h
Author: Joshua Prendergast */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include "Renderable.h"

namespace sight {

class Texture : public Renderable {
public:
    Texture(SDL_Renderer *renderer, const std::string &filename);
    ~Texture();
    int load(SDL_Renderer *renderer, const std::string &filename);
    virtual void render(SDL_Renderer *renderer, Vector2f &pos);
private:
    SDL_Texture *texture;
    SDL_Rect srcR, destR;
};

};

#endif // TEXTURE_H
