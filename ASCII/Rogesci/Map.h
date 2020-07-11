#pragma once
#include <string>

using namespace std;

extern const char mapWallSymbol;
extern int mapHeight;
extern int mapWidth;
extern float mapMaxDepth;

wstring GenerateGameLevel();
