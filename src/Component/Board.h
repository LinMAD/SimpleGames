#ifndef SOVIETTETRIS_BOARD_H
#define SOVIETTETRIS_BOARD_H

#include "AbstractVisualObject.h"
#include "Setting/Properties.h"
#include "Component/Tetromino.h"

namespace component {

    /**
     * Board represent a game field
     * Contains game logic:
     * Collision checks, figures collecting, line deliting
     */
    class Board : public AbstractVisualObject {
    private:
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
         * @param tetromino
         * @return is colliding with object
         */
        bool isColliding(Tetromino &tetromino);

        /**
         * Collect figure to board
         */
        void collect(const Tetromino &tetromino);
    };
}

#endif //SOVIETTETRIS_BOARD_H
