#pragma once

#include "GameManager.h"

class ScreenRender {
private:
    GameManager *_gm;
public:
    ScreenRender(GameManager *gm) : _gm(gm) {};

    void Init();

    void Update();
};

