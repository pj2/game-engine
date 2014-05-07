/* util.cpp
Author: Joshua Prendergast */

#include "util.h"

namespace sight {

void printSdlError() {
    std::cerr << SDL_GetError() << std::endl;
}

}
