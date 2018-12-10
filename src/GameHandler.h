#ifndef SIMPLETETRIS_GAMEHANDLER_H
#define SIMPLETETRIS_GAMEHANDLER_H

#include <random>
#include <SDL2/SDL.h>
#include "Component/Figure.h"
#include "Component/Board.h"
#include "Component/Score.h"

namespace engine {
    /**
     * Game represent a handler for all workflow of the tetris game
     */
    class GameHandler {
    private:
        SDL_Window *sdlWindow_;
        SDL_Renderer *sdlRenderer_;

        component::Figure currentFigure_;
        component::Board *gameBoard_;
        component::Score *gameScore;

        Uint32 gameSpeed_;
        bool isGameOver_ = false;
    public:
        GameHandler();

        ~GameHandler();

        /**
         * Prepares all game dependencies
         * @return
         */
        void init();

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
            return isGameOver_;
        };
    };
};


#endif //SIMPLETETRIS_GAMEHANDLER_H
