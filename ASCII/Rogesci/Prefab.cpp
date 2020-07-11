#include "Prefab.h"
#include "Map.h"

const short PREFAB_EMPTY_SPACE = 0x20;       // ' '
const short PREFAB_CEILING = 0x2E;			 // .

// Wall
const short PREFAB_WALL = 0x2588;			 // █
const short PREFAB_CLOSE_DIST_WALL = 0x2593; // ▓
const short PREFAB_MID_DIST_WALL = 0x2592;   // ▒
const short PREFAB_FAR_DIST_WALL = 0x2591;   // ░

// Floor
const short PREFAB_FLOOR = 0x3D;             // =
const short PREFAB_CLOSE_DIST_FLOOR = 0x2D;  // -
const short PREFAB_MID_DIST_FLOOR = 0x2E;    // .
const short PREFAB_FAR_DIST_FLOOR = 0x2E;    // _

short GetWallPrefab(float distanceToWall)
{
	if (distanceToWall <= mapMaxDepth / 4.0f) {
		return PREFAB_WALL;
	}
	else if (distanceToWall < mapMaxDepth / 3.0f) {
		return PREFAB_CLOSE_DIST_WALL;
	}
	else if (distanceToWall < mapMaxDepth / 2.0f) {
		return PREFAB_MID_DIST_WALL;
	}
	else if (distanceToWall < mapMaxDepth) {
		return PREFAB_FAR_DIST_WALL;
	}
	else {
		return PREFAB_EMPTY_SPACE;
	}
}

short GetFloorPrefab(float viewDistance)
{
	if (viewDistance < 0.25f) {
		return PREFAB_FLOOR;
	} else if (viewDistance < 0.5f) {
		return PREFAB_CLOSE_DIST_FLOOR;
	} else if (viewDistance < 0.75f) {
		return PREFAB_MID_DIST_FLOOR;
	} else if (viewDistance < 0.9f) {
		return PREFAB_FAR_DIST_FLOOR;
	} else {
		return PREFAB_EMPTY_SPACE;
	}
}
