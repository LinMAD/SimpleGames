#include <iostream>
#include <string>
#include "GameHandler.h"
#include "Util/Generator.h"
#include "Setting/Properties.h"
#include "Model/FigureType.h"
#include "Component/Figure.cpp"
#include "Component/Board.cpp"
#include "Component/Score.cpp"
#include "Input.cpp"

using namespace util;
using namespace setting;

/**
 * Public methods
 */

// Constructor
engine::GameHandler::GameHandler() :
        gameSpeed_(SDL_GetTicks()),
        currentFigure_(Figure{FigureType(generateRandom(FigureType::I, FigureType::Z))}) {
    gameBoard_ = new Board(Figure{FigureType(generateRandom(FigureType::I, FigureType::Z))});
    gameScore = new Score("0");
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
    Figure figureInFuture = currentFigure_;

    try {
        engine::Input::handle(&figureInFuture);
    } catch (std::runtime_error &e) {
        isGameOver_ = true;

        return;
    }

    if (!gameBoard_->isColliding(figureInFuture)) {
        currentFigure_ = figureInFuture;
    }
}

void engine::GameHandler::update() {
    if (SDL_GetTicks() < gameSpeed_) {
        return;
    }

    gameSpeed_ += 500 - (gameBoard_->getBoardLife() << 1);

    // Check if current falling figure must be stored
    Figure figureInFuture = currentFigure_;
    figureInFuture.move(0, 1);
    if (!gameBoard_->isColliding(figureInFuture)) {
        currentFigure_ = figureInFuture;

        return;
    }

    // Store figure in game board and generate new if can
    gameBoard_->handleStore(currentFigure_);

    currentFigure_ = gameBoard_->getNextFigure();
    if (gameBoard_->isColliding(currentFigure_)) {
        isGameOver_ = true;
        return;
    }

    gameBoard_->setNextFigure(Figure{FigureType(generateRandom(FigureType::I, FigureType::Z))});
}

void engine::GameHandler::render() {
    SDL_SetRenderDrawColor(sdlRenderer_, 0, 0, 0, 0xff);
    SDL_RenderClear(sdlRenderer_);

    gameBoard_->render(sdlRenderer_);
    gameScore->score_ = std::to_string(gameBoard_->getBoardScore());
    gameScore->render(sdlRenderer_);
    currentFigure_.render(sdlRenderer_);

    SDL_RenderPresent(sdlRenderer_);
}
