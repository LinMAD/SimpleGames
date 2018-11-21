#include "Tetromino.h"

using namespace component;

/**
 * Public methods
 */

// constructor
Tetromino::Tetromino(TetrominoType type) :
    type_(type), cX_(0), cY_(0), angle_(0) {
}

void Tetromino::render(SDL_Renderer *renderer, int screenWidth, int screenHeight) {
    // TODO Define color by tetromino type
    SDL_SetRenderDrawColor(renderer, 0x00, 0x7f, 0x7f, 0xff);

    // Create rectangle with scaling based on screen
    int figScale = screenWidth / 2 / 20;

    // Generate figure in 4 slices
    for (auto x = 0; x < 4; x++) {
        for (auto y = 0; y < 4; y++) {
            if (!isBlock(x, y)) {
                continue;
            }

            SDL_Rect rect{
                (x + cX_) * figScale + 1,
                (y + cY_) * figScale + 1,
                figScale - 1,
                figScale - 1
            };
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void Tetromino::move(int nextX, int nextY) {
    cX_ += nextX;
    cY_ += nextY;
}

void Tetromino::rotate() {
    // Make rotation 90*
    angle_ += 3;
    angle_ %= 4;
}

int Tetromino::getX() const {
    return cX_;
}

int Tetromino::getY() const {
    return cY_;
}

bool Tetromino::isBlock(int x, int y) const
{
    return TetrominoSprite[type_][angle_][x + y * 4] == '*';
}