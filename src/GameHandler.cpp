#include <iostream>
#include "GameHandler.h"
#include "Util/Generator.h"
#include "Setting/Properties.h"
#include "Component/TetrominoType.h"
#include "Component/Tetromino.cpp"
#include "Component/Board.cpp"

using namespace util;
using namespace setting;

/**
 * Public methods
 */

// Constructor
engine::GameHandler::GameHandler() :
        gameSpeed_(SDL_GetTicks()),
        tetromino_(Tetromino{TetrominoType(generateRandom(TetrominoType::C, TetrominoType::T))}) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("Unable to initialize SDL lib");
    }

    sdlWindow_ = SDL_CreateWindow(
            "SovietTetris",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            ScreenWidth,
            ScreenHeight,
            SDL_WINDOW_SHOWN
    );
    if (sdlWindow_ == nullptr) {
        throw std::runtime_error("Unable to initialize window");
    }

    sdlRenderer_ = SDL_CreateRenderer(sdlWindow_, -1, SDL_RENDERER_PRESENTVSYNC);
    if (sdlRenderer_ == nullptr) {
        throw std::runtime_error("Unable to initialize renderer");
    }

    board_ = Board();
}

// De-constructor
engine::GameHandler::~GameHandler() {
    SDL_DestroyRenderer(sdlRenderer_);
    SDL_DestroyWindow(sdlWindow_);
    SDL_Quit();
}

// tick cycle
void engine::GameHandler::tick() {
    if (SDL_GetTicks() > gameSpeed_) {
        gameSpeed_ += 1000;
        tetromino_.move(0, 1);
    }
}

void engine::GameHandler::input() {
    SDL_Event event;

    if (!SDL_WaitEventTimeout(&event, 250)) {
        return;
    }

    if (event.type == SDL_QUIT) {
        isGameOver = true;

        return;
    }

    if (event.type != SDL_KEYDOWN) {
        return;
    }

    switch (event.key.keysym.sym) {
        default:
            break;
        case SDLK_DOWN: {
            std::cout << "Key down" << std::endl;
            if (!board_.isColliding(tetromino_)) {
                tetromino_.move(0, 1);
            }
        }
            break;
        case SDLK_RIGHT: {
            std::cout << "Key right" << std::endl;
            if (tetromino_.getX() <= FieldWidth) {
                tetromino_.move(1, 0);
            }
        }
            break;
        case SDLK_LEFT: {
            std::cout << "Key left" << std::endl;
            if (tetromino_.getX() >= 0) {
                tetromino_.move(-1, 0);
            }
        }
            break;
        case SDLK_UP: {
            std::cout << "Key up" << std::endl;
            tetromino_.rotate();
        }
            break;
    }
}

void engine::GameHandler::update() {
    SDL_SetRenderDrawColor(sdlRenderer_, 0, 0, 0, 0xff);
    SDL_RenderClear(sdlRenderer_);

    board_.render(sdlRenderer_);
    tetromino_.render(sdlRenderer_);

    std::cout << "Current figure X: " << tetromino_.getX() << " Y: " << tetromino_.getY() << std::endl;
    if (board_.isColliding(tetromino_)) {
        board_.process(tetromino_);
        std::cout << "Spawned new figure" << std::endl;
        tetromino_ = Tetromino{
                TetrominoType(generateRandom(TetrominoType::C, TetrominoType::T))
        };
    }
}

void engine::GameHandler::render() {
    SDL_RenderPresent(sdlRenderer_);
}


