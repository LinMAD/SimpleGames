#include <iostream>
#include "Board.h"

using namespace component;

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

bool Board::isColliding(Figure &fig) {
    for (int x = 0; x < FIGURE_SIZE; x++) {
        for (int y = 0; y < FIGURE_SIZE; y++) {
            if (!fig.isBlock(x, y)) {
                continue;
            }

            // Check if figure collides with game board
            int boardX = fig.getX() + x;
            if (boardX < 0 || boardX >= setting::FieldWidth) {
                return true;
            }

            int boardY = fig.getY() + y;
            if (boardY < 0 || boardY >= setting::FieldHeight) {
                return true;
            }

            // Check if future figure will collide with next in matrix
            if (boardMatrix_[boardX][boardY]) {
                return true;
            }
        }
    }

    return false;
}

void Board::collect(const Figure &fig) {
    // Fill figure to board matrix
    for (int x = 0; x < FIGURE_SIZE; x++) {
        for (int y = 0; y < FIGURE_SIZE; y++) {
            if (fig.isBlock(x, y)) {
                boardMatrix_[fig.getX() + x][fig.getY() + y] = true;
            }
        }
    }

    unsigned int removedLines = 0;

    // Check all lines
    for (int line = setting::FieldHeight - 1; line >= 0; line--) {
        bool isSolidLine = true;
        for (auto &row : boardMatrix_) {
            if (!row[line]) {
                isSolidLine = false;

                break;
            }
        }

        if (!isSolidLine) {
            continue;
        }

        removedLines++;
        for (int y = line - 1; y >= 0; y--) {
            for (auto &x : boardMatrix_) {
                x[y + 1] = x[y];
            }
        }

        for (auto &x : boardMatrix_) {
            x[0] = false;
        }
    }

    calculateScore(removedLines);
}

unsigned int Board::getBoardScore() {
    return boardScore_;
}

unsigned int Board::getBoardLife() {
    return boardLife_;
}
