#include <SDL2/SDL_types.h>

#ifndef SOVIETTETRIS_COLOR_H
#define SOVIETTETRIS_COLOR_H

#endif //SOVIETTETRIS_COLOR_H

namespace model {

    /**
     * SDL Color object
     */
    struct Color {
        Uint8 red   = 0;
        Uint8 green = 0;
        Uint8 blue  = 0;
        Uint8 alpha = 255;
    };
}