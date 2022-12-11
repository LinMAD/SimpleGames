#include <iostream>
#include "Spawner.h"
#include "Validator.h"

void Spawner::Spawn(int gameField[FIELD_HEIGHT][FIELD_WIDTH], Point* from, Point* to)
{
    for (int i = 0; i < FIGURE_SIZE; i++)
        gameField[to[i].y][to[i].x] = *_tetrominoColorNum;

    *_tetrominoColorNum = 1 + rand() % MAX_COLORS;

    CreateFigure(from);
}

void Spawner::CreateFigure(Point* location)
{
    int n = rand() % MAX_COLORS;
    for (int i = 0; i < FIGURE_SIZE; i++)
    {
        location[i].x = tetromino[n][i] % 2;
        location[i].y = tetromino[n][i] / 2;
    }
}
