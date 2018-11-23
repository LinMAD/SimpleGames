#include "Board.h"

component::Board::Board() : boardMatrix{{false}} {}

void component::Board::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 128);

    int figScale = getObjectScale();
    for (auto x = 0; x < setting::FieldWidth; x++) {
        for (auto y = 0; y < setting::FieldHeight; y++) {
            if (boardMatrix[x][y]) {
                continue;
            }

            SDL_Rect rect{
                    x * figScale + RECT_BORDER,
                    y * figScale + RECT_BORDER,
                    figScale - RECT_BORDER,
                    figScale - RECT_BORDER
            };

            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

bool component::Board::isColliding(Tetromino &tetromino) {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (tetromino.isBlock(x, y)) {
                auto boardX = tetromino.getX() + x;
                auto boardY = tetromino.getY() + y;

                if (boardX < 0 || boardX >= setting::FieldWidth ||
                    boardY < 0 || boardY >= setting::FieldHeight)
                {
                    return true;
                }

                if (boardMatrix[boardX][boardY]) {
                    return true;
                }
            }
        }
    }

    return false;
}
