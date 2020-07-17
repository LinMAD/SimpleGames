#pragma once
static struct GameStructure {
    static const int MAP_WIDTH = 40;
    static const int MAP_HEIGHT = 15;
    static const int SCREEN_WIDTH = 30;

    enum Direction {
        NORTH,
        WEST,
        SOUTH,
        EAST,
        MAX,
    };

    static const int directions[][2];

    static struct Props {
        enum Cell {
            NONE,
            SOLID,
            DESTRUCTIBLE,
            EXPLOSION,
            MAX
        };

        static const int cellASCII[3][1];
        static const int enemyASCII = 228;      // Σ
        static const int playerASCII = 64;      // @
        static const int bombASCII = 233;       // Θ
        static const int explosionASCII = 206;  // ╬
    };

    static struct Character {
        static const int MAX_ACTORS = 9;
    };

    static struct Bomb {
        static const int MAX = 10;
        static const int COUNT_MAX = 10;
    };
};

