/* Font.cpp
Author: Joshua Prendergast */

#include "Font.h"

namespace sight {

Font::Font(const std::string &fontName, int ptSize) {
    font = TTF_OpenFont(fontName.c_str(), size = ptSize);
}

Font::~Font() {
    TTF_CloseFont(font);
}

TTF_Font *Font::getSDLFont() {
    return font;
}

}