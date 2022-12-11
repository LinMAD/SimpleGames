#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Game/GameStructure.h"
#include "Game/Character.h"
#include "Game/BombWeapon.h"
#include "Game/InputController.h"
#include "Game/GameManager.h"
#include "Game/ScreenRender.h"

using namespace std;

bool isGameOver = false;

// gameField[y][x] == 0 will be on the left top corner. 
int gameField[GameStructure::MAP_HEIGHT][GameStructure::MAP_WIDTH];
Character gameCharacters[GameStructure::Character::MAX_ACTORS];
BombWeapon gameBombs[GameStructure::Bomb::MAX];

HANDLE PrepareConsole() {
    // Set code page 437 - OEM United States
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    // Move window to required position
    HWND console = GetConsoleWindow();

    // TODO Fix w and h to dynamic it's always now 1
    MoveWindow(console, 50, 50, 72, 16, TRUE);

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Remove scroll bar
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = {
            static_cast<SHORT>(info.srWindow.Right - info.srWindow.Left + 1),
            static_cast<SHORT>(info.srWindow.Bottom - info.srWindow.Top + 1)
    };
    SetConsoleScreenBufferSize(handle, new_size);

    return handle;
}

void FindFreeLocation(GameManager *gm, int *x, int *y) {
    while (true) {
        int randX = rand() % GameStructure::MAP_WIDTH;
        int randY = rand() % GameStructure::MAP_HEIGHT;

        switch (gameField[randY][randX]) {
            case GameStructure::Props::DESTRUCTIBLE:
            case GameStructure::Props::SOLID:
                break;
            default:
                int foe = gm->GetCharacter(randX, randY);

                if (foe < 0) {
                    *x = randX;
                    *y = randY;

                    return;
                }

                break;
        }
    }
}

int main() {
    srand((unsigned int) time(nullptr));

    HANDLE console = PrepareConsole();
    CONSOLE_SCREEN_BUFFER_INFO csbi = {0};
    GetConsoleScreenBufferInfo(console, &csbi);
    COORD coordCur = csbi.dwCursorPosition;

    GameManager gm(gameField, gameCharacters, gameBombs);
    InputController inputController(&gm);
    ScreenRender render(&gm);

    render.Init();

    // Spawn player
    gameCharacters[0].x = gameCharacters[0].y = 1;
    // Clean area around
    gameField[1][1] = gameField[2][1] = gameField[1][2] = GameStructure::Props::NONE;

    // Spawn enemies
    for (int i = 1; i < GameStructure::Character::MAX_ACTORS; i++)
        FindFreeLocation(&gm, &gameCharacters[i].x, &gameCharacters[i].y);

    // Game loop
    while (!isGameOver) {
        // Set console cursor back to refresh screen
        coordCur.X = coordCur.Y = 0;
        SetConsoleCursorPosition(console, coordCur);
        render.Update();

        // Keyboard inputs
        inputController.HandlePlayerInput();

        gm.HandleBombsExplosion();
        gm.HandleEnemiesMovment();

        isGameOver = gm.GetPlayer()->isDead;
        if (!isGameOver) {
            for (int i = 1; i < GameStructure::Character::MAX_ACTORS; i++) {
                isGameOver = gameCharacters[i].isDead;
            }
        }
    }

    printf("Game over!\n");
    exit(0);
}
