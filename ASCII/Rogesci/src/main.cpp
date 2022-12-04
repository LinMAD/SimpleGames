// Rogesci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <cstdio>
#include <chrono>
#include "Game/Configuration.h"
#include "Game/Player.h"
#include "Game/Map.h"
#include "Game/Render.h"

using namespace std;
using namespace chrono;

int main()
{
	// Buffer
	auto* screen = new wchar_t[screenResolution];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
    SetConsoleActiveScreenBuffer(hConsole);
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
	DWORD dwBytesWritten = 0;
	wstring gameLevel = GenerateGameLevel();

	// Sync to system time
	auto tp1 = system_clock::now();
	auto tp2 = system_clock::now();

	// Game loop
	while (true) {
		for (int x = 0; x < screenWidth; x++) {
			tp2 = system_clock::now();
			duration<float> systemElapsedTime = tp2 - tp1;
			tp1 = tp2;

			// Normalize game to system time
			float elapsedTime = systemElapsedTime.count();

			HandlePlayerControlls(elapsedTime);

			float rayAngle = (playerAngle - playerFieldOfView / 2.0f) + ((float) x / (float) screenWidth) * playerFieldOfView;
			float rayDistanceToObject = 0.0f;
			bool isRayHitObject = false;

			// Vision
			float eyeX = sinf(rayAngle);
			float eyeY = cosf(rayAngle);

			// TODO Refactor to collision checker ?
			while (!isRayHitObject && rayDistanceToObject < mapMaxDepth) {
				rayDistanceToObject += 0.1f;

				int testX = (int)(playerX + eyeX * rayDistanceToObject);
				int testY = (int)(playerY + eyeY * rayDistanceToObject);

				if (testX < 0 || testX >= mapWidth || testY < 0 || testY >= mapHeight) {
					isRayHitObject = true;
					rayDistanceToObject = mapMaxDepth;
				} else {
					if (gameLevel[testY * mapWidth + testX] == mapWallSymbol) {
						isRayHitObject = true;
					}
				}
			}

			for (int y = 0; y < screenHeight; y++) {
				UpdateScreen(screen, x, y, (float) rayDistanceToObject);
			}
		}


		screen[screenResolution - 1] = '\0';
        WriteConsoleOutputCharacterW(hConsole, screen, screenResolution, { 0, 0 }, &dwBytesWritten);
	}

	return 0;
}

