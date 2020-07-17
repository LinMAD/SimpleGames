#pragma once

#include "GameStructure.h"
#include "GameManager.h"

static class CollisionHandler {
public:

    static bool isCanMove(GameManager *gm, int x, int y);
};

