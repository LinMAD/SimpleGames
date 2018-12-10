#ifndef SOVIETTETRIS_BOARD_H
#define SOVIETTETRIS_BOARD_H

#include "Setting/Properties.h"
#include "Component/Figure.h"

namespace component {
    /**
     * Game matrix with allocated objects
     */
    struct Matrix {
        bool board_[setting::MaxFieldX][setting::MaxFieldY]{};
    };

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
        // Board total score
        unsigned int boardScore_;
        // Board life it's time life score modification, higher number, more points
        unsigned int boardLife_;

        // Matrix contains board container for locations
        Matrix matrix_;

        // Board will show next figure
        Figure nextFigure_;

        /**
         * Calculate score price for removed lines
         * Formula: 80 * (removedLines + boardLife_)
         *
         * @param removedLines of figures aka tetromino
         *
         * @return return int
         */
        void calculateScore(unsigned int removedLines);

        /**
         * Clears filled figures in line
         *
         * @param board
         * @param clearedCount
         */
        void clearAvailableLines(Matrix *matrix, unsigned int &clearedCount);

    public:
        explicit Board(Figure nextFigure);

        /**
         * Render game field
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
        void handleStore(const Figure &fig);

        /**
         * Show next type of figure
         *
         * @param type
         */
        void setNextFigure(Figure next);

        /**
         * @return pointer to next figure
         */
        Figure getNextFigure();

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
