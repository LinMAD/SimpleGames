#ifndef SOVIETTETRIS_GAME_H
#define SOVIETTETRIS_GAME_H

#include <random>
#include <SDL2/SDL.h>
#include "Component/Tetromino.h"

namespace engine {
    /**
     * Game represent a handler for all workflow of the tetris game
     */
    class GameHandler {
    private:
        util::Tetromino tetromino_;
        SDL_Window *sdlWindow_;
        SDL_Renderer *sdlRenderer_;
        Uint32 speed_;
    public:
        GameHandler();
        ~GameHandler();

        /**
         * Handle CPU tick
         * to handle speed of the game
         *
         * @return bool
         */
        bool tick();
    };
};


#endif //SOVIETTETRIS_GAME_H
