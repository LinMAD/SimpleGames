#pragma once
#include "Settings.h"

using namespace settings;

static class Validator
{
public:
	static bool isBlocked(int gameField[FIELD_HEIGHT][FIELD_WIDTH], Point* location);
	static void checkLines(int gameField[FIELD_HEIGHT][FIELD_WIDTH]);
};

