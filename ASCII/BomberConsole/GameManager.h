#pragma once

#include "GameStructure.h"
#include "Character.h"
#include "BombWeapon.h"

class GameManager {
public:
    int(&field)[GameStructure::MAP_HEIGHT][GameStructure::MAP_WIDTH];
    Character(&characters)[GameStructure::Character::MAX_ACTORS];
    BombWeapon(&bombs)[GameStructure::Bomb::MAX];

    GameManager(
            int (&gameField)[GameStructure::MAP_HEIGHT][GameStructure::MAP_WIDTH],
            Character(&actors)[GameStructure::Character::MAX_ACTORS],
            BombWeapon(&allBombs)[GameStructure::Bomb::MAX]
    )
            :
            field(gameField),
            characters(actors),
            bombs(allBombs) {
    }

    int GetCharacter(int x, int y);

    Character *GetPlayer();

    int GetFreeBomb();

    int GetBomb(int x, int y);

    void HandleEnemiesMovment();

    void HandleBombsExplosion();
};

