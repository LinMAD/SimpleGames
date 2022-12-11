#ifndef CMAKE_BOMBER_CONSOLE_COLLISION_HANDLER_H
#define CMAKE_BOMBER_CONSOLE_COLLISION_HANDLER_H

#include "GameStructure.h"
#include "GameManager.h"

class CollisionHandler {
public:
    static bool isCanMove(GameManager *gm, int x, int y);
};

#endif //CMAKE_BOMBER_CONSOLE_COLLISION_HANDLER_H
