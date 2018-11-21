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

    // Create rectangle with scaling based on screen
    int figureScale = screenHeight / 20 + 5;
    int coordinateCenter = screenWidth / 2;

    // Generate figure in 4 slices
    for (auto x = 0; x < 4; x++) {
        for (auto y = 0; y < 4; y++) {
            // TODO Fix coordinates
            // TODO Fix figure scale
            SDL_Rect rect{
                (x + cX_) * coordinateCenter / 10,
                (y + cY_) * coordinateCenter / 10,
                figureScale,
                figureScale
            };
            SDL_RenderFillRect(renderer, &rect);
        }
    }
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
