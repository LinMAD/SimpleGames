#include "GameStructure.h"

const int GameStructure::Props::cellASCII[3][1] = {
        00,  // CELL_TYPE_NONE
        178, // CELL_TYPE_HARD_BLOCK    ▓
        176, // CELL_TYPE_SOFTL_BLOCK   ░
};

const int GameStructure::directions[][2] = {
        {0,  -1}, // NORTH,
        {-1, 0}, // WEST,
        {0,  1},     // SOUTH,
        {1,  0},     // EAST,
};
