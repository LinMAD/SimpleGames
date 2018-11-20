//
// Created by Artjoms-ARNE on 2018-11-19.
//

#ifndef SOVIETTETRIS_GAME_H
#define SOVIETTETRIS_GAME_H

#include <SDL2/SDL.h>

/**
 * Game represent a handler for all workflow of the tetris game
 */
class Game {
private:
    Game(const Game &);
    Game &operator = (const Game &);

    SDL_Window *window_;
    SDL_Renderer *renderer_;

    Uint32 elapsedTime_;

    //void check(const Tetromino &);
public:
    const static int SCREEN_WIDTH = 640;
    const static int SCREEN_HEIGHT = 480;

    const static int SCREEN_RESOLUTION = SCREEN_WIDTH * SCREEN_HEIGHT;
    
    Game();
    ~Game();

    /**
     * Passed time in tick
     *
     * @return bool
     */
    bool tick();
};


#endif //SOVIETTETRIS_GAME_H
