#include <stdlib.h>
#include "GameManager.h"
#include "CollisionHandler.h"

int GameManager::GetCharacter(int x, int y) {
    for (int i = 0; i < GameStructure::Character::MAX_ACTORS; i++) {
        if (characters[i].isDead)
            continue;

        if (characters[i].x == x && characters[i].y == y) {
            return i;
        }
    }

    return -1;
}

Character *GameManager::GetPlayer() {
    return &characters[0];
}

int GameManager::GetFreeBomb() {
    for (int i = 0; i < GameStructure::Bomb::MAX; i++) {
        if (bombs[i].count <= 0)
            return i;
    }

    return -1;
}

int GameManager::GetBomb(int x, int y) {
    for (int i = 0; i < GameStructure::Bomb::MAX; i++) {
        BombWeapon plantedBomb = bombs[i];
        if (plantedBomb.count > 0 && plantedBomb.x == x && plantedBomb.y == y)
            return i;
    }

    return -1;
}

void GameManager::HandleEnemiesMovment() {
    // Enemy AI...
    for (int i = 1; i < GameStructure::Character::MAX_ACTORS; i++) {
        if (characters[i].isDead) continue;

        int x = characters[i].x + GameStructure::directions[characters[i].direction][0];
        int y = characters[i].y + GameStructure::directions[characters[i].direction][1];
        if (CollisionHandler::isCanMove(this, x, y)) {
            characters[i].x = x;
            characters[i].y = y;
        } else {
            characters[i].direction = rand() % GameStructure::Direction::MAX;
        }
    }
}

void GameManager::HandleBombsExplosion() {
    for (int i = 0; i < GameStructure::Bomb::MAX; i++) {
        if (bombs[i].count <= 0) continue;

        bombs[i].count--;

        // Place texture of explosion
        if (bombs[i].count <= 0) {
            field[bombs[i].y][bombs[i].x] = GameStructure::Props::EXPLOSION;

            for (int j = 0; j < GameStructure::Direction::MAX; j++) {
                int x2 = bombs[i].x;
                int y2 = bombs[i].y;
                for (int i = 0; i < 2; i++) {
                    x2 += GameStructure::directions[j][0];
                    y2 += GameStructure::directions[j][1];

                    if (field[y2][x2] == GameStructure::Props::SOLID)
                        break;
                    else if (field[y2][x2] == GameStructure::Props::DESTRUCTIBLE) {
                        field[y2][x2] = GameStructure::Props::EXPLOSION;
                        break;
                    } else {
                        // He's dead Jim
                        int actor = GetCharacter(x2, y2);
                        if (actor >= 0) characters[actor].isDead = true;
                        field[y2][x2] = GameStructure::Props::EXPLOSION;
                    }
                }
            }
        }
    }
}
