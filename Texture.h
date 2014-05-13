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
    Texture(SDL_Renderer *renderer, const std::string &filename);
    ~Texture();
    int load(SDL_Renderer *renderer, const std::string &filename);
    virtual void render(SDL_Renderer *renderer, Vector2f &pos);
    SDL_Rect &getOriginalDimensions();
    void setSrcSubRect(SDL_Rect &srcR);
    void setDstSubRect(SDL_Rect &dstR);
    SDL_Rect &getSrcSubRect();
    SDL_Rect &getDstSubRect();
    void setOffset(Vector2f &offset);
    void setOffset(float x, float y);
    Vector2f &getOffset();
    void setBlendMode(SDL_BlendMode blendMode);
    SDL_BlendMode getBlendMode();
    static const std::string TEXTURE_FOLDER;
private:
    SDL_Texture *texture;
    SDL_Rect srcR, dstR;
    SDL_Rect originalDimensions;
    Vector2f offset;
};

};

#endif // TEXTURE_H
