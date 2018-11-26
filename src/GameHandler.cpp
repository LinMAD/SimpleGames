#include <iostream>
#include "GameHandler.h"
#include "Util/Generator.h"
#include "Setting/Properties.h"
#include "Component/FigureType.h"
#include "Component/Figure.cpp"
#include "Component/Board.cpp"

using namespace util;
using namespace setting;

/**
 * Public methods
 */

// Constructor
engine::GameHandler::GameHandler() :
        gameSpeed_(SDL_GetTicks()),
        currentFigure_(Figure{FigureType(generateRandom(FigureType::I, FigureType::Z))}) {
    gameBoard_ = new Board();

    // TODO give next new figure to game board to be displayed
}

// De-constructor
engine::GameHandler::~GameHandler() {
    SDL_DestroyRenderer(sdlRenderer_);
    SDL_DestroyWindow(sdlWindow_);
    SDL_Quit();
}

void engine::GameHandler::init() {
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
        throw std::runtime_error(SDL_GetError());
    }

    sdlRenderer_ = SDL_CreateRenderer(sdlWindow_, -1, SDL_RENDERER_PRESENTVSYNC);
    if (sdlRenderer_ == nullptr) {
        throw std::runtime_error(SDL_GetError());
    }
}

void engine::GameHandler::input() {
    SDL_Event event;

    if (!SDL_WaitEventTimeout(&event, 250)) {
        return;
    }

    if (event.type == SDL_QUIT) {
        isGameOver_ = true;

        return;
    }

    if (event.type != SDL_KEYDOWN || isUserInputLocked_) {
        return;
    }

    // TODO Split Input to class, add pause if escape pressed

    switch (event.key.keysym.sym) {
        default:
            break;
        case SDLK_DOWN: {
            Figure figureInFuture = currentFigure_;
            figureInFuture.move(0, 1);
            if (!gameBoard_->isColliding(figureInFuture)) {
                currentFigure_ = figureInFuture;
            }
        }
            break;
        case SDLK_RIGHT: {
            Figure figureInFuture = currentFigure_;
            figureInFuture.move(1, 0);
            if (!gameBoard_->isColliding(figureInFuture)) {
                currentFigure_ = figureInFuture;
            }
        }
            break;
        case SDLK_LEFT: {
            Figure figureInFuture = currentFigure_;
            figureInFuture.move(-1, 0);
            if (!gameBoard_->isColliding(figureInFuture)) {
                currentFigure_ = figureInFuture;
            }
        }
            break;
        case SDLK_UP: {
            Figure figureInFuture = currentFigure_;
            figureInFuture.rotate();
            if (!gameBoard_->isColliding(figureInFuture)) {
                currentFigure_ = figureInFuture;
            }
        }
            break;
    }
}

void engine::GameHandler::update() {
    // TODO Check if game ended
    // TODO Add better tick handling, some times games jumping
    if (SDL_GetTicks() < gameSpeed_) {
        return;
    }

    gameSpeed_ += 1000 * gameBoard_->getBoardLife() / 2;
    isUserInputLocked_ = true;

    // Check if game still playable
    Figure figureInFuture = currentFigure_;
    figureInFuture.move(0, 1);
    if (gameBoard_->isColliding(figureInFuture)) {
        gameBoard_->collect(currentFigure_);

        // TODO give new figure to game board to be displayed
        currentFigure_ = Figure{FigureType(
                generateRandom(FigureType::I, FigureType::Z))
        };
    } else {
        currentFigure_ = figureInFuture;
    }

    isUserInputLocked_ = false;

    std::cout << "Game score: " << gameBoard_->getBoardScore() << std::endl;
}

void engine::GameHandler::render() {
    SDL_SetRenderDrawColor(sdlRenderer_, 0, 0, 0, 0xff);
    SDL_RenderClear(sdlRenderer_);

    gameBoard_->render(sdlRenderer_);
    currentFigure_.render(sdlRenderer_);

    SDL_RenderPresent(sdlRenderer_);
}



