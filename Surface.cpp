/* Surface.cpp
Author: Joshua Prendergast */

#include "Surface.h"

/* SDL interprets each pixel as a 32-bit number, so our masks must depend
on the endianness (byte order) of the machine */
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    #define SURFACE_RMASK 0xFF000000
    #define SURFACE_GMASK 0x00FF0000
    #define SURFACE_BMASK 0x0000FF00
    #define SURFACE_AMASK 0x000000FF
#else
    #define SURFACE_RMASK 0x000000FF
    #define SURFACE_GMASK 0x0000FF00
    #define SURFACE_BMASK 0x00FF0000
    #define SURFACE_AMASK 0xFF000000
#endif

namespace sight {

Surface::Surface(int w, int h) : surface(SDL_CreateRGBSurface(0, w, h, 32, SURFACE_RMASK, SURFACE_GMASK, SURFACE_BMASK, SURFACE_AMASK)) {
}

Surface::~Surface() {
    SDL_FreeSurface(surface);
}

}