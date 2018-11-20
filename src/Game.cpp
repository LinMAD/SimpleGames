#include <iostream>
#include "Game.h"

using namespace std;

Game::Game() : elapsedTime_(SDL_GetTicks()) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw runtime_error("Unable to initialize SDL lib");
    }

    window_ = SDL_CreateWindow(
            "SovietTetris",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
    );
    if (window_ == nullptr) {
        throw runtime_error("Unable to initialize window");
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer_ == nullptr) {
        throw runtime_error("Unable to initialize renderer");
    }
}

Game::~Game() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

bool Game::tick() {
    SDL_Event event;

    if (SDL_WaitEventTimeout(&event, 250)) {
        switch (event.type) {
            case SDL_QUIT:
                return false;
            default:
                break;
        }
    }

    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0xff);

    SDL_RenderPresent(renderer_);

    return true;
}

