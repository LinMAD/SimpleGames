#include <SDL2/SDL_types.h>

#ifndef SOVIETTETRIS_COLOR_H
#define SOVIETTETRIS_COLOR_H

namespace model {

    /**
     * SDL Color object
     */
    struct Color {
        Uint8 red = 255;
        Uint8 green = 255;
        Uint8 blue = 255;
        Uint8 alpha = 255;
    };
}

#endif //SOVIETTETRIS_COLOR_H
