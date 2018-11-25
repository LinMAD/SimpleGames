#include <iostream>
#include "Board.h"

using namespace component;

Board::Board() : boardMatrix_{{false}} {}

void Board::render(SDL_Renderer *renderer) {
    int figScale = getObjectScale();

    for (auto x = 0; x < setting::FieldWidth; x++) {
        for (auto y = 0; y < setting::FieldHeight; y++) {
            if (boardMatrix_[x][y]) {
                // TODO Get color form tetro
                SDL_SetRenderDrawColor(renderer, 80, 80, 80, 128);
                SDL_Rect rect{
                        x * figScale + RECT_BORDER,
                        y * figScale + RECT_BORDER,
                        figScale - RECT_BORDER,
                        figScale - RECT_BORDER
                };
                SDL_RenderFillRect(renderer, &rect);

                continue;
            }

            // TODO Move rect creation to abstract class
            SDL_SetRenderDrawColor(renderer, 30, 30, 30, 128);
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

bool Board::isColliding(Tetromino &tetromino) {
    for (int x = 0; x < TETROMINO_SIZE; x++) {
        for (int y = 0; y < TETROMINO_SIZE; y++) {
            if (!tetromino.isBlock(x, y)) {
                continue;
            }

            auto boardX = tetromino.getX() + x;
            auto boardY = tetromino.getY() + y;

            if (boardX < 0 || boardX >= setting::FieldWidth || boardY < 0 || boardY >= setting::FieldHeight) {
                return true;
            }

            // Check if future figure will collide with next in matrix
            if (boardMatrix_[boardX][boardY]) {
                std::cout << "In figure Matrix: x -> " << boardX << " y -> " << boardY << std::endl;

                return true;
            }
        }
    }

    return false;
}

void Board::collect(const Tetromino &tetromino) {
    // Fill figure to board matrix
    for (int x = 0; x < TETROMINO_SIZE; x++) {
        for (int y = 0; y < TETROMINO_SIZE; y++) {
            if (tetromino.isBlock(x, y)) {
                boardMatrix_[tetromino.getX() + x][tetromino.getY() + y] = true;
            }
        }
    }
}
