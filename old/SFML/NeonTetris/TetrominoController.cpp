#include "TetrominoController.h"
#include "Validator.h"

void TetrominoController::Rotate(int gameField[FIELD_HEIGHT][FIELD_WIDTH], bool isRotating, Point* from, Point* to)
{
	if (!isRotating)
		return;

    Point p = from[1]; //center of rotation

    for (int i = 0; i < settings::FIGURE_SIZE; i++)
    {
        int x = from[i].y - p.y;
        int y = from[i].x - p.x;

        from[i].x = p.x - x; 
        from[i].y = p.y + y;
    }

    if (Validator::isBlocked(gameField, from))
        for (int i = 0; i < FIGURE_SIZE; i++)
            from[i] = to[i];
}

void TetrominoController::Move(int gameField[FIELD_HEIGHT][FIELD_WIDTH], int moveVertical, Point* from, Point* to)
{
    for (int i = 0; i < FIGURE_SIZE; i++) {
        to[i] = from[i]; 
        from[i].x += moveVertical;
    }

    if (Validator::isBlocked(gameField, from))
        for (int i = 0; i < FIGURE_SIZE; i++)
            from[i] = to[i];
}
