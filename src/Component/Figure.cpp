#include "Figure.h"

using namespace setting;
using namespace component;
using namespace model;

/**
 * Public methods
 */

// constructor
Figure::Figure(FigureType type) :
        type_(type), cX_(FieldWidth / 2 - 2), cY_(0), angle_(0) {

    switch (type_) {
        case FigureType::I:
            color_ = Color{0, 150, 140};
            break;
        case FigureType::J:
            color_ = Color{0, 100, 150};
            break;
        case FigureType::L:
            color_ = Color{200, 120, 20};
            break;
        case FigureType::O:
            color_ = Color{245, 230, 50};
            break;
        case FigureType::S:
            color_ = Color{100, 180, 0};
            break;
        case FigureType::T:
            color_ = Color{120, 11, 160};
            break;
        case FigureType::Z:
            color_ = Color{150, 0, 0};
            break;
        default:
            color_ = Color{};
            break;
    }
}

void Figure::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color_.red, color_.green, color_.blue, 100);

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

model::Color Figure::getFigureColor() {
    return color_;
}
