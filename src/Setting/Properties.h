#ifndef SIMPLETETRIS_SCREEN_H
#define SIMPLETETRIS_SCREEN_H

namespace setting {
    const char *WINDOW_NAME = "Simple Tetris";

    enum Screen {
        ScreenWidth = 800, ScreenHeight = 800, HalfScreen = 400
    };
    enum GameField {
        MaxFieldX = 10, MaxFieldY = 20
    };
}

#endif //SIMPLETETRIS_SCREEN_H
