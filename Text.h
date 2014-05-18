/* Text.h
Author: Joshua Prendergast */

#ifndef TEXT_H
#define TEXT_H

#include "Font.h"
#include "Renderable.h"
#include "Texture.h"

/*
#define ALIGNMENT_LEFT 0
#define ALIGNMENT_RIGHT 1
#define ALIGNMENT_CENTER 2
*/

namespace sight {

class Text : public Texture {
public:
    Text(SDL_Renderer *renderer, Font *font);
    Text(SDL_Renderer *renderer, Font *font, const std::string &text);
    Text(SDL_Renderer *renderer, Font *font, const std::string &text, int alignment);
    ~Text();
    void rebuild();
    void setFont(Font *font);
    Font *getFont();
    void setText(const std::string &text);
    std::string &getText();
    void setColor(SDL_Color color);
    SDL_Color &getColor();
private:
    Font *font;
    std::string text;
    SDL_Color color;
};

}

#endif // TEXT_H
