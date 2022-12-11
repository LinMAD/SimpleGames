#ifndef CMAKE_BOMBER_CONSOLE_GAME_STRUCTURE_H
#define CMAKE_BOMBER_CONSOLE_GAME_STRUCTURE_H

struct GameStructure {
    static const int MAP_WIDTH = 100;
    static const int MAP_HEIGHT = 15;
    static const int SCREEN_WIDTH = 60;
    static const int SCREEN_HEIGHT = 40;

    enum Direction {
        NORTH,
        WEST,
        SOUTH,
        EAST,
        MAX,
    };

    static const int directions[][2];

    struct Props {
        enum Cell {
            NONE,
            SOLID,
            DESTRUCTIBLE,
            EXPLOSION,
            MAX
        };

        static const int cellASCII[4][1];
        static const int enemyASCII = 228;      // Σ
        static const int playerASCII = 64;      // @
        static const int bombASCII = 233;       // Θ
    };

    struct Character {
        static const int MAX_ACTORS = 9;
    };

    struct Bomb {
        static const int MAX = 10;
        static const int COUNT_MAX = 10;
    };
};

#endif //CMAKE_BOMBER_CONSOLE_GAME_STRUCTURE_H
