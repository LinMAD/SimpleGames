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
        component::Tetromino tetromino_;
        SDL_Window *window_;
        SDL_Renderer *renderer_;
        Uint32 speed_;

        const int screenWidth_;
        const int screenHeight_;
    public:
        GameHandler(int screenWidth, int screenHeight);
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
