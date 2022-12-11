#include "Validator.h"

bool Validator::isBlocked(int gameField[FIELD_HEIGHT][FIELD_WIDTH], Point* location)
{
    for (int i = 0; i < FIGURE_SIZE; i++)
        if (location[i].x < 0 || location[i].x >= FIELD_WIDTH || location[i].y >= FIELD_HEIGHT)
            return true;
        else if (gameField[location[i].y][location[i].x])
            return true;

    return false;
}

void Validator::checkLines(int gameField[FIELD_HEIGHT][FIELD_WIDTH])
{
    int yComplited = FIELD_HEIGHT - 1;

    for (int y = FIELD_HEIGHT - 1; y > 0; y--)
    {
        int count = 0;
        for (int x = 0; x < FIELD_WIDTH; x++)
        {
            if (gameField[y][x])
                count++;

            gameField[yComplited][x] = gameField[y][x];
        }

        if (count < FIELD_WIDTH)
            yComplited--;
    }
}
