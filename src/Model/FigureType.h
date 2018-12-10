#ifndef SOVIETTETRIS_FIGURETYPE_H
#define SOVIETTETRIS_FIGURETYPE_H

namespace model {
    const int FIGURE_SIZE = 4;

    // All types of figures
    enum FigureType {
        I, J, L, O, S, T, Z
    };

    // FigureSprite stores all variations of figures
    static const char *FigureSprite[][model::FIGURE_SIZE] = {
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
