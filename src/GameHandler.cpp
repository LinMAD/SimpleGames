#include <iostream>
#include "GameHandler.h"
#include "Component/TetrominoType.h"
#include "Component/Generator.h"
#include "Component/Tetromino.cpp"

using namespace component;

/**
 * Public methods
 */

// Constructor
engine::GameHandler::GameHandler(int screenWidth, int screenHeight) :
    screenWidth_(screenWidth),
    screenHeight_(screenHeight),

    elapsedTickTime_(SDL_GetTicks()),
    tetromino_ (Tetromino{TetrominoType(generateRandom(TetrominoType::C, TetrominoType::T))}) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("Unable to initialize SDL lib");
    }

    window_ = SDL_CreateWindow(
            "SovietTetris",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            screenWidth_,
            screenHeight_,
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
                    tetromino_.move(0, 1);
                }
                    break;
                case SDLK_RIGHT: {
                    std::cout << "Key right" << std::endl;
                    tetromino_.move(-1, 0);
                }
                    break;
                case SDLK_LEFT: {
                    std::cout << "Key left" << std::endl;
                    tetromino_.move(1, 0);
                }
                    break;
                case SDLK_UP: {
                    std::cout << "Key up" << std::endl;
                    tetromino_.rotate();
                }
                    break;
            }
        }
    }

    // TODO Render shapes in class render
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0xff);
    SDL_RenderClear(renderer_);
    tetromino_.render(renderer_, screenWidth_, screenHeight_);

    // Force piece move down per each tick
    if (SDL_GetTicks() > elapsedTickTime_) {
        elapsedTickTime_ += 1000;
        tetromino_.move(0, 1);
    }

    SDL_RenderPresent(renderer_);
    return true;
}


