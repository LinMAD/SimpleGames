#ifndef SOVIETTETRIS_BOARD_H
#define SOVIETTETRIS_BOARD_H

#include "Setting/Properties.h"
#include "Component/AbstractVisualObject.h"
#include "Component/Figure.h"

namespace component {

    /**
     * Board represent a game field
     * Contains game logic:
     *  - Collision checks
     *  - Figures collecting
     *  - Removing the lines
     *  - Scoring calculating
     */
    class Board : public AbstractVisualObject {
    private:
        // Board container to control stored piece
        bool boardMatrix_[setting::FieldWidth][setting::FieldHeight]{};
        // Board total score
        unsigned int boardScore_;
        // Board life it's time life score modification, higher number, more points
        unsigned int boardLife_ ;

        /**
         * Calculate score price for removed lines
         * Formula: 80 * (removedLines + boardLife_)
         *
         * @param removedLines of figures aka tetromino
         *
         * @return return int
         */
        void calculateScore(int removedLines) {
            boardScore_ += (boardLife_ + 1) * 2;

            if (removedLines != 0) {
                boardScore_ += 80 * (removedLines + boardLife_);
            }
        }
    public:
        Board() {
            boardScore_ = 0;
            boardLife_ = 1;
        }

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
        unsigned int getBoardScore();

        /**
         * @return int how long board exist
         */
        unsigned int getBoardLife();
    };
}

#endif //SOVIETTETRIS_BOARD_H
