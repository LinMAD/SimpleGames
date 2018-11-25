#ifndef SOVIETTETRIS_TETROMINO_H
#define SOVIETTETRIS_TETROMINO_H

#include "TetrominoType.h"
#include "AbstractVisualObject.h"

namespace component {

    /**
     * Tetromino represent a playable object
     */
    class Tetromino : public AbstractVisualObject {
    private:
        /**
         * Current coordinates in axis
         */
        int cX_, cY_;

        /**
         * Current angele (how it's rotated max 360==0)
         */
        int angle_;

        /**
         * Type of piece
         */
        TetrominoType type_;
    public:
        explicit Tetromino(TetrominoType type);

        /**
         * Render figure
         */
        void render(SDL_Renderer *renderer);

        /**
         * Handle movement on next coordinates
         * @param nextX
         * @param nextY
         */
        void move(int nextX, int nextY);

        /**
         * Handel rotation of figure
         */
        void rotate();

        // Getters of current piece coordinates
        int getX() const;

        int getY() const;

        /**
         * Checking is block exist on
         * coordinates
         * @param x
         * @param y
         *
         * @return bool
         */
        bool isBlock(int x, int y) const;
    };
}

#endif //SOVIETTETRIS_TETROMINO_H
