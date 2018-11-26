#include <utility>

#include <iostream>
#include "Board.h"

using namespace component;
using namespace setting;

Board::Board(Figure nextFigure) : boardScore_(0),  boardLife_(1), nextFigure_(nextFigure) {}

void Board::render(SDL_Renderer *renderer) {
    int figScale = getObjectScale();
    // TODO Add score on right screen

    // Create next figure background shadow
    SDL_SetRenderDrawColor(renderer, 30, 10, 10, 30);
    SDL_Rect nextFigBorderBg{
            ScreenWidth / 2 + RECT_BORDER * 50,
            FieldHeight + setting::FieldHeight + RECT_BORDER,
            400,
            300
    };
    SDL_RenderFillRect(renderer, &nextFigBorderBg);

    // Create next figure background shadow
    SDL_SetRenderDrawColor(renderer, 60, 10, 10, 30);
    SDL_Rect nextFigBorder{
            ScreenWidth / 2 + RECT_BORDER * 100,
            FieldHeight + setting::FieldHeight + RECT_BORDER,
            350,
            250
    };
    SDL_RenderFillRect(renderer, &nextFigBorder);

    // Render current figure
    nextFigure_.cX_ = FieldWidth + 5;
    nextFigure_.cY_ = 2;
    nextFigure_.render(renderer);

    // Draw game field and render falling figure
    for (auto x = 0; x < FieldWidth; x++) {
        for (auto y = 0; y < FieldHeight; y++) {
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
            int boardX = fig.cX_ + x;
            if (boardX < 0 || boardX >= FieldWidth) {
                return true;
            }

            int boardY = fig.cY_ + y;
            if (boardY < 0 || boardY >= FieldHeight) {
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

void Board::handleStore(const Figure &fig) {
    // Fill figure to board matrix
    for (int x = 0; x < FIGURE_SIZE; x++) {
        for (int y = 0; y < FIGURE_SIZE; y++) {
            if (fig.isBlock(x, y)) {
                boardMatrix_[fig.cX_ + x][fig.cY_ + y] = true;
            }
        }
    }

    unsigned int removedLines = 0;

    // TODO Find bug related of deleting more than 1 line (if need remove 2, will be removed 1)
    // Check all lines
    for (int line = FieldHeight - 1; line >= 0; line--) {
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

void Board::setNextFigure(Figure next) {
    nextFigure_ = next;
}

Figure Board::getNextFigure() {
    nextFigure_.cX_ = FieldWidth / 2 - 2;
    nextFigure_.cY_ = 0;

    return nextFigure_;
}
