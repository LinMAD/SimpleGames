#include <utility>

#include <iostream>
#include <string>
#include "Score.h"
#include "Model/NumberType.h"
#include "Model/Color.h"

using namespace std;
using namespace model;

Score::Score(std::string currentScore) {
    score_ = currentScore;
}

void component::Score::render(SDL_Renderer *renderer) {
    int figScale = getObjectScale();

    for (int i = 0; i < score_.length(); i++) {
        for (auto x = 0; x < NUMBER_SIZE; x++) {
            for (auto y = 0; y < NUMBER_SIZE; y++) {
                const char symbol = score_[i];
                if (!isBlock(atoi(&symbol), x, y)) {
                    continue;
                }

                drawRectangle(
                        renderer,
                        Color{},
                        HalfScreen + 15 + x * figScale + RECT_BORDER * (35 * i),
                        (HalfScreen >> 3) + y * figScale + RECT_BORDER,
                        figScale - RECT_BORDER,
                        figScale - RECT_BORDER
                );
            }
        }
    }
}

bool component::Score::isBlock(int number, int x, int y) const {
    return NumberSprite[number][x + y * NUMBER_SIZE] == '*';
}

int Score::getObjectScale() {
    return AbstractVisualObject::getObjectScale() / 5;
}


