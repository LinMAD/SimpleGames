#pragma once

namespace settings {
	const int MAX_COLORS = 3;
	const int FIGURE_SIZE = 4;
	const int FIELD_WIDTH = 10;
	const int FIELD_HEIGHT = 20;

	struct ScreenConfig
	{
		const unsigned int ScreenWidth = 320;
		const unsigned int ScreenHeight = 480;
	};

	struct Point
	{
		int x, y;
	};

	struct Field
	{
		int field[FIELD_HEIGHT][FIELD_WIDTH] = { 0 };
	};
}


