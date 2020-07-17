#pragma once

#include "GameManager.h"

class InputController {
    GameManager *_gm;
public:
    InputController(GameManager *gm) : _gm(gm) {}

    void HandlePlayerInput();
};

