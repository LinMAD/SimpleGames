#include "GameStructure.h"

const int GameStructure::Props::cellASCII[4][1] = {
        00,  // NONE
        219, // SOLID          █
        177, // DESTRUCTIBLE   ▒
        206, // EXPLOSION      ╬
};

const int GameStructure::directions[][2] = {
        {0,  -1},    // NORTH,
        {-1, 0},     // WEST,
        {0,  1},     // SOUTH,
        {1,  0},     // EAST,
};
