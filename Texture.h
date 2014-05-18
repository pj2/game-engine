/* Texture.h
Author: Joshua Prendergast */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include "Vector.h"
#include "Renderable.h"

namespace sight {

class Texture : public Renderable {
public:
    Texture(SDL_Renderer *renderer);
    Texture(SDL_Renderer *renderer, SDL_Surface *surface);
    Texture(SDL_Renderer *renderer, const std::string &filename);
    ~Texture();
    virtual void render(Vector2f pos);
    void createTexture(SDL_Surface *surface);
    void createTexture(const std::string &filename);
    void setBlendMode(SDL_BlendMode blendMode);
    SDL_BlendMode getBlendMode();
    static const std::string TEXTURE_FOLDER;
private:
    SDL_Texture *texture;
};

};

#endif // TEXTURE_H
