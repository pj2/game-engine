/* Font.h
Author: Joshua Prendergast */

#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL_ttf.h>
#include <string>

namespace sight {

class Font {
public:
    Font(const std::string &fontName, int ptSize);
    ~Font();
    TTF_Font *getSDLFont();
private:
    TTF_Font *font;
    int size; // In points (1/72 inch)
};

}

#endif // FONT_H
