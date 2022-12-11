#pragma once

#include "Settings.h"

using namespace settings;

class Spawner
{
protected:
    int* _tetrominoColorNum;
public:
    const int tetromino[7][4] =
    {
        1,3,5,7, // I
        2,4,5,7, // Z
        3,5,4,6, // S
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // L - Reversed
        2,3,4,5, // [] - Cube
    };

    Spawner(int* tetrominoColorNum) : _tetrominoColorNum(tetrominoColorNum) {}
	void Spawn(int gameField[FIELD_HEIGHT][FIELD_WIDTH], Point* from, Point* to);
    void CreateFigure(Point* location);
};

