#include "Tetromino.h"

/**
 * Public methods
 */

// constructor
component::Tetromino::Tetromino(component::TetrominoType type) :
    type_(type), cX_(5), cY_(0), angle_(0) {
}

void component::Tetromino::render(SDL_Renderer *renderer, int screenWidth, int screenHeight) {
    // TODO Define color by tetromino type
    SDL_SetRenderDrawColor(renderer, 0x00, 0x7f, 0x7f, 0xff);

    // Create rectangle with scaling based on screen height
    int figureScale = screenHeight / 15;
    SDL_Rect rect{screenWidth / 2 - cX_, 0 + cY_, figureScale, figureScale};
    SDL_RenderFillRect(renderer, &rect);
}

void component::Tetromino::move(int nextX, int nextY) {
    cX_ += nextX;
    cY_ += nextY;
}

void component::Tetromino::rotate() {
    // Make 90* rotation
    angle_ += 3;
    angle_ %= 4;
}

int component::Tetromino::getX() const {
    return cX_;
}

int component::Tetromino::getY() const {
    return cY_;
}
