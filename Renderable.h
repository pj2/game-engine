/* Renderable.h
Author: Joshua Prendergast */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <SDL2/SDL.h>
#include "Vector.h"

namespace sight {

class Renderable {
public:
    Renderable(SDL_Renderer *renderer);
    virtual void render(Vector2f pos) = 0;
    virtual ~Renderable();
    Vector2f getPosition();
    void setPosition(Vector2f &pos);
    void setPosition(float x, float y);
    void setWidth(int w);
    void setHeight(int h);
    void setSrcRect(SDL_Rect *srcR);
    void setSrcRect(int x, int y, int w, int h);
    SDL_Rect *getSrcRect();
    SDL_Rect &getDstRect();
    int getWidth();
    int getHeight();
    SDL_Renderer *getRenderer();
private:
    SDL_Rect srcR, dstR;
    SDL_Renderer *renderer;
    bool wholeTexture; // If true, ignore the sub-rect and use the whole source texture
    Vector2f pos;
};

}

#endif // RENDERABLE_H
