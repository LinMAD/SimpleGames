#include <iostream>
#include "GameHandler.h"

/**
 * Private methods
 */

int engine::GameHandler::genRandomFrom(int from, int to) {
    std::random_device randD;
    std::mt19937 generator(randD());
    std::uniform_int_distribution<> distribute(from, to);

    return distribute(generator);
}

/**
 * Public methods
 */

// Constructor
engine::GameHandler::GameHandler() : elapsedTickTime_(SDL_GetTicks()) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("Unable to initialize SDL lib");
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
        throw std::runtime_error("Unable to initialize window");
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer_ == nullptr) {
        throw std::runtime_error("Unable to initialize renderer");
    }
}

// De-constructor
engine::GameHandler::~GameHandler() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

// tick cycle
bool engine::GameHandler::tick() {
    // TODO Handle user input in different class
    SDL_Event event;

    if (SDL_WaitEventTimeout(&event, 250)) {
        if (event.type == SDL_QUIT) {
            return false;
        }

        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                default:
                    break;
                case SDLK_DOWN: {
                    std::cout << "Key down" << std::endl;
                }
                    break;
                case SDLK_RIGHT: {
                    std::cout << "Key right" << std::endl;
                }
                    break;
                case SDLK_LEFT: {
                    std::cout << "Key left" << std::endl;
                }
                    break;
                case SDLK_UP: {
                    std::cout << "Key up" << std::endl;
                }
                    break;
            }
        }
    }

    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0xff);

    // TODO Render shapes in class render
    SDL_RenderClear(renderer_);
    SDL_SetRenderDrawColor(renderer_, 0xff, 0xff, 0xff, 0xff);
    SDL_Rect rect{
            SCREEN_WIDTH / 2,
            0,
            OBJECT_SCALE,
            OBJECT_SCALE
    };
    SDL_RenderFillRect(renderer_, &rect);

    SDL_RenderPresent(renderer_);

    return true;
}


