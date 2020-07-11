#include "Map.h"

const char mapWallSymbol = '#';
int mapHeight = 16;
int mapWidth = 16;
float mapMaxDepth = 16.0f;

wstring GenerateGameLevel()
{
	wstring map;

	map += L"################";
	map += L"#..............#";
	map += L"#....##........#";
	map += L"#..............#";
	map += L"#...########...#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..#...........#";
	map += L"#..#.....###...#";
	map += L"#..#......#....#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#...########	#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"################";

	return map;
}
