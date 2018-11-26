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
        bool boardMatrix_[setting::FieldWidth][setting::FieldHeight];
        unsigned int boardScore_;

        /**
         * Calculate score price for removed lines
         * Formula:
         * 80 * (removedLines + 1)
         *
         * @param removedLines of figures aka tetromino
         *
         * @return return int
         */
        void calculateScore(int removedLines) {
            boardScore_ += static_cast<unsigned int>(80 * (removedLines + 1));
        }

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

        /**
         * @return int current board score
         */
        int getBoardScore();
    };
}

#endif //SOVIETTETRIS_BOARD_H
