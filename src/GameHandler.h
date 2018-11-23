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
        SDL_Window *sdlWindow_;
        SDL_Renderer *sdlRenderer_;
        component::Tetromino tetromino_;

        Uint32 gameSpeed_;
        bool isGameOver = false;
    public:
        GameHandler();
        ~GameHandler();

        /**
         * Handle CPU tick
         * to have same speed of the game
         *
         * @return bool
         */
        void tick();

        /**
         * Handle input
         */
        void input();

        /**
         * Update game state
         */
        void update();

        /**
         * Render game objects
         */
        void render();

        /**
         * @return is game ended by game condition
         */
        bool isGameEnd() {
            return isGameOver;
        };
    };
};


#endif //SOVIETTETRIS_GAME_H
