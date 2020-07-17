#include "CollisionHandler.h"

bool CollisionHandler::isCanMove(GameManager *gm, int x, int y) {
    // Collision check
    switch (gm->field[y][x]) {
        case GameStructure::Props::DESTRUCTIBLE:
        case GameStructure::Props::SOLID:
            return false;
        default:
            break;
    }

    if (gm->GetCharacter(x, y) < 0 && gm->GetBomb(x, y) < 0)
        return true;

    return false;
}
