/* Renderable.cpp
Author: Joshua Prendergast */

#include "Renderable.h"

namespace sight {

Renderable::Renderable(SDL_Renderer *renderer) : renderer(renderer), wholeTexture(true) {
    dstR.x = dstR.y = dstR.w = dstR.h = 0;
}

Renderable::~Renderable() {
}

Vector2f Renderable::getPosition() {
    return pos;
}

void Renderable::setPosition(Vector2f &pos) {
    setPosition(pos.x, pos.y);
}

void Renderable::setPosition(float x, float y) {
    this->dstR.x = x;
    this->dstR.y = y;

    this->pos.x = x;
    this->pos.y = y;
}

void Renderable::setWidth(int w) {
    this->dstR.w = w;
}

void Renderable::setHeight(int h) {
    this->dstR.h = h;
}

void Renderable::setSrcRect(SDL_Rect *srcR) {
    if (!srcR)
        wholeTexture = true; // Passing in null disables the sub-rect
    else
        memcpy(&this->srcR, srcR, sizeof(SDL_Rect));
}

void Renderable::setSrcRect(int x, int y, int w, int h) {
    wholeTexture = false;
    this->srcR.x = x;
    this->srcR.y = y;
    this->srcR.w = w;
    this->srcR.h = h;
}

SDL_Rect *Renderable::getSrcRect() {
    return wholeTexture ? NULL : &srcR;
}

SDL_Rect &Renderable::getDstRect() {
    return dstR;
}

int Renderable::getWidth() {
    return dstR.w;
}

int Renderable::getHeight() {
    return dstR.h;
}

SDL_Renderer *Renderable::getRenderer() {
    return renderer;
}

}