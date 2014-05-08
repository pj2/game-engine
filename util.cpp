/* util.cpp
Author: Joshua Prendergast */

#include "util.h"
#include <SDL2/SDL.h>

namespace sight {

void printSdlError() {
    std::cerr << SDL_GetError() << std::endl;
}

}
