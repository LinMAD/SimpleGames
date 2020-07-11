#include "CollisionHandler.h"
#include "Map.h"

bool IsCollidesWithWall(int x, int y)
{
	wstring gameLevel = GenerateGameLevel();

	return gameLevel[(int)y * mapWidth + (int)x] == mapWallSymbol;
}
