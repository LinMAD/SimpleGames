#ifndef SOVIETTETRIS_TETROMINO_H
#define SOVIETTETRIS_TETROMINO_H

#include <SDL2/SDL.h>
#include "TetrominoType.h"

namespace component {
    class Tetromino {
    private:
        /**
         * Current coordinates in axis
         */
        int cX_, cY_;

        /**
         * Current angele (how it's rotated max 360)
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
        void render(SDL_Renderer *renderer, int screenWidth, int screenHeight);

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
    };
}


#endif //SOVIETTETRIS_TETROMINO_H
