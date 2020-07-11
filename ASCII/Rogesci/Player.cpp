#include <Windows.h>
#include <math.h>
#include "Player.h"
#include "CollisionHandler.h"

float playerX = 8.0f;
float playerY = 8.0f;

float playerAngle = 0.0f;
float playerFieldOfView = 3.14159f / 4.0f;

float playerRotationSpeed = 1.0f;
float playerMovementSpeed = 1.0f;

void HandlePlayerControlls(float elapsedTime)
{
	// Rotate left
	if (GetAsyncKeyState((unsigned short) 'A') & 0x8000) {
		playerAngle -= playerRotationSpeed * elapsedTime;
	}

	// Rotate right
	if (GetAsyncKeyState((unsigned short) 'D') & 0x8000) {
		playerAngle += playerRotationSpeed * elapsedTime;
	}

	// Forward
	if (GetAsyncKeyState((unsigned short) 'W') & 0x8000) {
		float tmpX = playerX + sinf(playerAngle) * playerMovementSpeed * elapsedTime;
		float tmpY = playerY + cosf(playerAngle) * playerMovementSpeed * elapsedTime;
		if (!IsCollidesWithWall(playerX, playerY)) {
			playerX = tmpX;
			playerY = tmpY;
		}
	}

	// Backword
	if (GetAsyncKeyState((unsigned short) 'S') & 0x8000) {
		float tmpX = playerX - sinf(playerAngle) * 5.0f * elapsedTime;
		float tmpY = playerY - cosf(playerAngle) * 5.0f * elapsedTime;
		if (!IsCollidesWithWall(playerX, playerY)) {
			playerX = tmpX;
			playerY = tmpY;
		}
	}
}
