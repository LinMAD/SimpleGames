#pragma once
#include "Map.h"

extern const short PREFAB_EMPTY_SPACE;
extern const short PREFAB_CEILING;
extern const short PREFAB_FLOOR;

extern const short PREFAB_WALL;
extern const short PREFAB_CLOSE_DIST_WALL;
extern const short PREFAB_MID_DIST_WALL;
extern const short PREFAB_FAR_DIST_WALL;

extern const short PREFAB_FLOOR;
extern const short PREFAB_CLOSE_DIST_FLOOR;
extern const short PREFAB_MID_DIST_FLOOR;
extern const short PREFAB_FAR_DIST_FLOOR;

short GetWallPrefab(float distanceToWall);
short GetFloorPrefab(float viewDistance);
