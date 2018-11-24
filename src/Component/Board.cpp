#include <iostream>
#include "Board.h"

component::Board::Board() : boardMatrix_{{false}} {}

void component::Board::render(SDL_Renderer *renderer) {
    int figScale = getObjectScale();
    for (auto x = 0; x < setting::FieldWidth; x++) {
        for (auto y = 0; y < setting::FieldHeight; y++) {
            if (!boardMatrix_[x][y]) {
                // TODO Move rect creation to abstract class
                SDL_SetRenderDrawColor(renderer, 30, 30, 30, 128);
                SDL_Rect rect{
                        x * figScale + RECT_BORDER,
                        y * figScale + RECT_BORDER,
                        figScale - RECT_BORDER,
                        figScale - RECT_BORDER
                };
                SDL_RenderFillRect(renderer, &rect);

                continue;
            }

            // TODO Get color form tetro
            SDL_SetRenderDrawColor(renderer, 80, 80, 80, 128);
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
            if (!tetromino.isBlock(x, y)) {
                continue;
            }

            auto boardX = tetromino.getX() + x;
            auto boardY = tetromino.getY() + y;

            if (boardX < 0 || boardY < 0 || boardY >= setting::FieldHeight - 1) {
                return true;
            }

            if (boardMatrix_[boardX][boardY]) {
                return true;
            }
        }
    }

    return false;
}

void component::Board::process(const Tetromino &tetromino) {
    // Fill figure to board matrix
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (tetromino.isBlock(x, y)) {
                boardMatrix_[tetromino.getX() + x][tetromino.getY() + y] = true;
            }
        }
    }
//
//    for (int y = setting::FieldHeight - 1; y >= 0; y--) {
//        bool solid = true;
//        for (auto &x : boardMatrix_)
//            if (!x[y]) {
//                solid = false;
//                break;
//            }
//
//        if (solid) {
//            for (int yy = y - 1; yy >= 0; --yy)
//                for (int x = 0; x < setting::FieldWidth; ++x)
//                    boardMatrix_[x][yy + 1] = boardMatrix_[x][yy];
//            for (int x = 0; x < setting::FieldWidth; ++x)
//                boardMatrix_[x][0] = false;
//        }
//    }
}
