#ifndef SIMPLETETRIS_INPUT_H
#define SIMPLETETRIS_INPUT_H

#include <SDL2/SDL.h>
#include "Component/Figure.h"

namespace engine {
    /**
     * Input handling user interaction with game
     */
    class Input {
    private:
        // SDL wait event timeout
        static const int EVENT_TIMEOUT = 250;
    public:
        /**
         * @param fig
         */
        static void handle(component::Figure *fig);
    };
}

#endif //SIMPLETETRIS_INPUT_H
