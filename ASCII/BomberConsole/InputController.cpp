#include <Windows.h>
#include "InputController.h"
#include "Character.h"
#include "CollisionHandler.h"

void InputController::HandlePlayerInput() {
    Character *player = _gm->GetPlayer();

    // Bomb planting
    if (GetAsyncKeyState((unsigned short) ' ') & 0x8000) {
        int bomb = _gm->GetFreeBomb();
        if (bomb >= 0) {
            _gm->bombs[bomb].x = player->x;
            _gm->bombs[bomb].y = player->y;
            _gm->bombs[bomb].count = GameStructure::Bomb::COUNT_MAX;
        }
    }

    int x = player->x;
    int y = player->y;

    // Rotate left
    if (GetAsyncKeyState((unsigned short) 'A') & 0x8000) x -= 1;
    // Rotate right
    if (GetAsyncKeyState((unsigned short) 'D') & 0x8000) x += 1;
    // Backword
    if (GetAsyncKeyState((unsigned short) 'W') & 0x8000) y -= 1;
    // Forward
    if (GetAsyncKeyState((unsigned short) 'S') & 0x8000) y += 1;

    if (CollisionHandler::isCanMove(_gm, x, y)) {
        player->x = x;
        player->y = y;
    }
}
