#ifndef SOVIETTETRIS_BOARD_H
#define SOVIETTETRIS_BOARD_H

#include "Setting/Properties.h"
#include "Component/AbstractVisualObject.h"
#include "Component/Figure.h"

namespace component {

    /**
     * Board represent a game field
     * Contains game logic:
     * Collision checks, figures collecting, line deliting
     */
    class Board : public AbstractVisualObject {
    private:
        // TODO Add game score
        bool boardMatrix_[setting::FieldWidth][setting::FieldHeight];
    public:
        Board();

        /**
         * Provide game field
         * @param renderer
         */
        void render(SDL_Renderer *renderer) override;

        /**
         * Check whole board matrix on collision
         *
         * @param fig
         * @return is colliding with object
         */
        bool isColliding(Figure &fig);

        /**
         * Collect figure to board
         */
        void collect(const Figure &fig);
    };
}

#endif //SOVIETTETRIS_BOARD_H
