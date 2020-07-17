#include <iostream>
#include <stdlib.h>
#include "ScreenRender.h"
#include "GameStructure.h"

using namespace std;

void ScreenRender::Init() {
    // Draw top and bottom border
    for (int y = 0; y < GameStructure::MAP_HEIGHT; y += GameStructure::MAP_HEIGHT - 1) {
        for (int x = 0; x < GameStructure::MAP_WIDTH; x++) {
            _gm->field[y][x] = GameStructure::Props::SOLID;
        }
    }

    // Draw left and right border
    for (int y = 0; y < GameStructure::MAP_HEIGHT; y++) {
        for (int x = 0; x < GameStructure::MAP_WIDTH; x += GameStructure::MAP_WIDTH - 1) {
            _gm->field[y][x] = GameStructure::Props::SOLID;
        }
    }

    // Place randomly blocks
    for (int y = 1; y < GameStructure::MAP_HEIGHT - 1; y++) {
        for (int x = 1; x < GameStructure::MAP_WIDTH - 1; x++) {
            if (x % 2 == 0 && y % 2 == 0) {
                _gm->field[y][x] = GameStructure::Props::SOLID;
            } else if (rand() % 2) {
                _gm->field[y][x] = GameStructure::Props::DESTRUCTIBLE;
            }
        }
    }
}

void ScreenRender::Update() {
    for (int l = 0; l < GameStructure::MAP_HEIGHT * GameStructure::SCREEN_WIDTH; l++)
        cout << "\b";

    // Scroll screen
    int left = _gm->GetPlayer()->x - GameStructure::SCREEN_WIDTH / 2;
    if (left < 0) {
        left = 0;
    }
    if (left > GameStructure::MAP_WIDTH - GameStructure::SCREEN_WIDTH) {
        left = GameStructure::MAP_WIDTH - GameStructure::SCREEN_WIDTH;
    }

    // Draw textures
    for (int y = 0; y < GameStructure::MAP_HEIGHT; y++) {
        for (int x = left; x < left + GameStructure::SCREEN_WIDTH; x++) {
            int bomb = _gm->GetBomb(x, y);
            int actor = _gm->GetCharacter(x, y);

            if (_gm->field[y][x] == GameStructure::Props::EXPLOSION) {
                cout << (char)*GameStructure::Props::cellASCII[_gm->field[y][x]];
            } else if (actor > 0) {
                cout << (char) GameStructure::Props::enemyASCII;
            } else if (actor == 0) {
                cout << (char) GameStructure::Props::playerASCII;
            } else if (bomb >= 0) {
                cout << (char) GameStructure::Props::bombASCII;
            } else {
                cout << (char) *GameStructure::Props::cellASCII[_gm->field[y][x]];
            }
        }
        cout << "\n";
    }


    // Remove bomb explosion effect
    for (int y = 1; y < GameStructure::MAP_HEIGHT - 1; y++)
        for (int x = 1; x < GameStructure::MAP_WIDTH - 1; x++)
            if (_gm->field[y][x] == GameStructure::Props::EXPLOSION)
                _gm->field[y][x] = GameStructure::Props::NONE;
}
