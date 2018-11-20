#ifndef SOVIETTETRIS_GAME_H
#define SOVIETTETRIS_GAME_H

#include <random>
#include <SDL2/SDL.h>

namespace engine {
    /**
     * Game represent a handler for all workflow of the tetris game
     */
    class GameHandler {
    private:
        SDL_Window *window_;
        SDL_Renderer *renderer_;
        Uint32 elapsedTickTime_;

        /**
         * Generates random int in given range
         * @param from
         * @param to
         * @return int
         */
        int genRandomFrom(int from, int to);

        //void check(const Tetromino &);
    public:
        const static int SCREEN_WIDTH = 640;
        const static int SCREEN_HEIGHT = 480;
        const static int SCREEN_RESOLUTION = SCREEN_WIDTH * SCREEN_HEIGHT;
        const static int OBJECT_SCALE = SCREEN_WIDTH / 30;

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
