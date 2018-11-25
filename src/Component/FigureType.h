#ifndef SOVIETTETRIS_FIGURETYPE_H
#define SOVIETTETRIS_FIGURETYPE_H

namespace component {
    const int FIGURE_SIZE = 4;

    // All types of figures
    enum FigureType {
        I, J, L, O, S, T, Z
    };

    // All figures sprites
    static const char *FigureSprite[][4] = {
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

#endif //SOVIETTETRIS_FIGURETYPE_H
