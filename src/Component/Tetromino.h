#ifndef PLAINTETRIS_TETROMINO_H
#define PLAINTETRIS_TETROMINO_H

#include "Block.h"

/**
 * Tetromino responsible to provide pieces of different type
 *
 * For details of class idea can be used:
 * @link https://en.wikipedia.org/wiki/Tetris#Tetromino_colors
 */
class Tetromino {
public:
    /**
     * @param type of tetromino
     * @param rotation of tetromino
     * @param x horizontal position
     * @param y vertical position
     *
     * @return Tetromino piece
     */
    int GetBlock(TetrominoType type, TetrominoRotation rotation, int x, int y);

    /**
     * @param type of tetromino
     * @param rotation of tetromino
     *
     * @return Tetromino piece
     */
    int GetXInitPos(TetrominoType type, TetrominoRotation rotation);

    /**
     * @param type of tetromino
     * @param rotation of tetromino
     *
     * @return Tetromino piece
     */
    int GetYInitPos(TetrominoType type, TetrominoRotation rotation);
};

#endif //PLAINTETRIS_TETROMINO_H
