#ifndef PLAINTETRIS_TETROMINOCOMPONENT_H
#define PLAINTETRIS_TETROMINOCOMPONENT_H

namespace component {
    const int TETROMINO_SIZE = 4;

    // All types of figures
    enum TetrominoType {
        I, J, L, O, S, T, Z
    };

    // All figures sprites
    static const char *TetrominoSprite[][4] = {
            {
                    " *  "
                    " *  "
                    " *  "
                    " *  ",
                    "    "
                    "****"
                    "    "
                    "    ",
                    " *  "
                    " *  "
                    " *  "
                    " *  ",
                    "    "
                    "****"
                    "    "
                    "    ",
            },
            {
                    "  * "
                    "  * "
                    " ** "
                    "    ",
                    "    "
                    "*   "
                    "*** "
                    "    ",
                    " ** "
                    " *  "
                    " *  "
                    "    ",
                    "    "
                    "    "
                    "*** "
                    "  * ",
            },
            {
                    " *  "
                    " *  "
                    " ** "
                    "    ",
                    "    "
                    "*** "
                    "*   "
                    "    ",
                    " ** "
                    "  * "
                    "  * "
                    "    ",
                    "  * "
                    "*** "
                    "    "
                    "    ",
            },
            {
                    "    "
                    " ** "
                    " ** "
                    "    ",
                    "    "
                    " ** "
                    " ** "
                    "    ",
                    "    "
                    " ** "
                    " ** "
                    "    ",
                    "    "
                    " ** "
                    " ** "
                    "    ",
            },
            {
                    "  * "
                    " ** "
                    " *  "
                    "    ",
                    "    "
                    "**  "
                    " ** "
                    "    ",
                    "  * "
                    " ** "
                    " *  "
                    "    ",
                    "    "
                    "**  "
                    " ** "
                    "    ",
            },
            {
                    " *  "
                    " ** "
                    " *  "
                    "    ",
                    "    "
                    "*** "
                    " *  "
                    "    ",
                    " *  "
                    "**  "
                    " *  "
                    "    ",
                    " *  "
                    "*** "
                    "    "
                    "    ",
            },
            {
                    " *  "
                    " ** "
                    "  * "
                    "    ",
                    "    "
                    " ** "
                    "**  "
                    "    ",
                    " *  "
                    " ** "
                    "  * "
                    "    ",
                    "    "
                    " ** "
                    "**  "
                    "    ",
            },
    };
}

#endif //PLAINTETRIS_TETROMINOCOMPONENT_H
