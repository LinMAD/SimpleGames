#include <utility>
#include <iostream>
#include "Board.h"
#include "Model/NumberType.h"

using namespace std;
using namespace component;
using namespace setting;
using namespace model;

/**
 * Public methods
 */

Board::Board(Figure nextFigure) : boardScore_(0), boardLife_(1), nextFigure_(nextFigure) {
    matrix_ = Matrix{};
}

void Board::render(SDL_Renderer *renderer) {
    // Create next figure background shadow
    drawRectangle(renderer, Color{50, 50, 50, 128}, HalfScreen + RECT_BORDER, 0, HalfScreen, ScreenWidth);

    // Render current figure
    nextFigure_.cX_ = MaxFieldX + 4;
    nextFigure_.cY_ = 15;
    nextFigure_.render(renderer);

    // Draw game field and render falling figure
    for (auto x = 0; x < MaxFieldX; x++) {
        for (auto y = 0; y < MaxFieldY; y++) {
            Color *gameBoardCellColor;
            if (matrix_.board_[x][y]) {
                gameBoardCellColor = new Color{150, 150, 150, 128};
            } else {
                gameBoardCellColor = new Color{30, 30, 30, 128};
            }

            drawRectangle(
                    renderer,
                    *gameBoardCellColor,
                    x * getObjectScale() + RECT_BORDER,
                    y * getObjectScale() + RECT_BORDER,
                    getObjectScale() - RECT_BORDER,
                    getObjectScale() - RECT_BORDER
            );
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
            if (boardX < 0 || boardX >= MaxFieldX) {
                return true;
            }

            int boardY = fig.cY_ + y;
            if (boardY < 0 || boardY >= MaxFieldY) {
                return true;
            }

            // Check if future figure will collide with next in matrix
            if (matrix_.board_[boardX][boardY]) {
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
                matrix_.board_[fig.cX_ + x][fig.cY_ + y] = true;
            }
        }
    }


    // Clear all possible lines in matrix
    unsigned int removedLines = 0;

    clearAvailableLines(&matrix_, removedLines);
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
    nextFigure_.cX_ = (MaxFieldX >> 1) - 2;
    nextFigure_.cY_ = 0;

    return nextFigure_;
}

/**
 * Private methods
 */


void Board::clearAvailableLines(Matrix *matrix, unsigned int &clearedCount) {
    for (int line = MaxFieldY - 1; line >= 0; line--) {
        bool isSolidLine = true;

        for (auto &row : matrix->board_) {
            if (!row[line]) {
                isSolidLine = false;

                break;
            }
        }

        if (!isSolidLine) {
            continue;
        }

        clearedCount++;
        for (int y = line - 1; y >= 0; y--) {
            for (auto &x : matrix->board_) {
                x[y + 1] = x[y];
            }
        }

        for (auto &x : matrix->board_) {
            x[0] = false;
        }

        clearAvailableLines(matrix, clearedCount);
    }

    boardLife_++;
}

void Board::calculateScore(unsigned int removedLines) {
    boardScore_ += (boardLife_ + 1) << 1;

    if (removedLines != 0) {
        boardScore_ += 80 * (removedLines + boardLife_);
    }
}
