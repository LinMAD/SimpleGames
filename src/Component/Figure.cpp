#include "Figure.h"

using namespace setting;
using namespace component;

/**
 * Public methods
 */

// constructor
Figure::Figure(FigureType type) :
        type_(type), cX_(FieldWidth / 2 - 2), cY_(0), angle_(0) {
}

void Figure::render(SDL_Renderer *renderer) {
    // TODO Define color by tetromino type
    SDL_SetRenderDrawColor(renderer, 0, 100, 200, 100);

    int figScale = getObjectScale();
    // Generate figure in 4 slices
    for (auto x = 0; x < 4; x++) {
        for (auto y = 0; y < 4; y++) {
            if (!isBlock(x, y)) {
                continue;
            }
            SDL_Rect rect{
                    (x + cX_) * figScale + RECT_BORDER,
                    (y + cY_) * figScale + RECT_BORDER,
                    figScale - RECT_BORDER,
                    figScale - RECT_BORDER
            };
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void Figure::move(int nextX, int nextY) {
    cX_ += nextX;
    cY_ += nextY;
}

void Figure::rotate() {
    // Make rotation 90*
    angle_ += 3;
    angle_ %= 4;
}

bool Figure::isBlock(int x, int y) const {
    return FigureSprite[type_][angle_][x + y * 4] == '*';
}
