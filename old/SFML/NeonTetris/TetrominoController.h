#pragma once
#include "Settings.h"

using namespace settings;

class TetrominoController
{
	
public:
	void Rotate(int gameField[FIELD_HEIGHT][FIELD_WIDTH], bool isRotating, Point* to, Point* from);
	void Move(int gameField[FIELD_HEIGHT][FIELD_WIDTH], int moveVertical, Point* to, Point* from);
};

