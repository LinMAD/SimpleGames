#include "Tetromino.h"

int Tetromino::GetBlock(TetrominoType type, TetrominoRotation rotation, int x, int y) {
    return blocks[type][rotation][x][y];
}

int Tetromino::GetXInitPos(TetrominoType type, TetrominoRotation rotation) {
    return blocksInitialPosition[type][rotation][0];
}

int Tetromino::GetYInitPos(TetrominoType type, TetrominoRotation rotation) {
    return blocksInitialPosition[type][rotation][1];
}

