#include <cstddef>
#include <stdexcept>
#include "Configuration.h"
#include "Render.h"
#include "Prefab.h"

void UpdateScreen(wchar_t* screen, int x, int y, float rayDistanceToObject)
{
	// TODO Can be done better outside
	float viewDistance = 1.0f - ( ((float) y - screenHeight / 2.0f) / ((float)screenHeight / 2.0f));
	int ceiling = (float)(screenHeight / 2.0f) - screenHeight / (rayDistanceToObject);
	int floor = screenHeight - ceiling;

	short wallTexture = GetWallPrefab(rayDistanceToObject);
	short floorTexture = GetFloorPrefab(viewDistance);

	if (y <= ceiling) {
		screen[y * screenWidth + x] = PREFAB_EMPTY_SPACE;
	}
	else if (y > ceiling&& y <= floor) {
		screen[y * screenWidth + x] = wallTexture;
	}
	else {
		screen[y * screenWidth + x] = floorTexture;
	}
}
