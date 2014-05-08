/* Background.cpp
Author: Joshua Prendergast */

#include "Background.h"

namespace sight {

Background::Background(Game *game) : Entity(game) {
}

Background::~Background() {
}

void Background::render(SDL_Renderer *renderer) {
    SDL_Rect r;

    SDL_GetRendererOutputSize(renderer, &r.w, &r.h);
    r.x = r.w * 0.05;
    r.y = r.h * 0.05;
    r.w *= 0.90;
    r.h *= 0.90;

    SDL_SetRenderDrawColor(renderer, 245, 245, 245, 255);
    SDL_RenderFillRect(renderer, &r);
}

}
