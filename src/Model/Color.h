#include <SDL2/SDL_types.h>

#ifndef SIMPLETETRIS_COLOR_H
#define SIMPLETETRIS_COLOR_H

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

#endif //SIMPLETETRIS_COLOR_H
