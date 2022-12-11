#pragma once

#include <SFML/Graphics.hpp>

const int DEFAULT_GROUND_Y = 208;
const int DEFAULT_TILE_SIZE = 16;

const unsigned int LEVEL_MAP_HEIGHT = 17;
const unsigned int LEVEL_MAP_WIDTH = 125;

const Color LEVEL_BG_COLOR = Color(102, 153, 255);

// TODO Refactor level to have mutations
const sf::String LEVEL_MAP[LEVEL_MAP_HEIGHT] = {
        "|                                                                                                                           |",
        "|                                                                                                                           |",
        "|                                                             c                             ccc                             |",
        "|                  c                                                                                                        |",
        "|                                ccc                                                                    cc                  |",
        "|                                                                              c                                            |",
        "|     c                                                                                       ^                             |",
        "|                    s                                                                      wwwwwwww     wwws               |",
        "|                                                                                          ^                                |",
        "|                     ^                                                   w                                                 |",
        "|              s   wswsw                                                                wsw                 w       ws      |",
        "|                                                   p|            p|                                                        |",
        "|  $                           p|           p|      ||            ||                                                        |",
        "|   h         bbb   h     b    ||        ^  || ^bb  ||    h ^  ^  ||  b bb h         b             b         ^ ^ h          |",
        "ggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
        "ggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
        "ggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
};
