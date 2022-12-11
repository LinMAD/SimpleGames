#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include "Settings.h"
#include "Render.h"
#include "EventHandler.h"
#include "TetrominoController.h"
#include "Spawner.h"
#include "Validator.h"

using namespace std;
using namespace sf;
using namespace settings;

bool isGameOver = false;
Point currentPoint[FIGURE_SIZE];
Point nextPoint[FIGURE_SIZE];
int gameField[FIELD_HEIGHT][FIELD_WIDTH];

int main()
{
    srand(time(0));
    ScreenConfig sreenCfg;

    RenderWindow window(
        VideoMode(sreenCfg.ScreenWidth, sreenCfg.ScreenHeight),
        "Neon Tetris"
    );

    Render render(window, gameField);
    render.LoadAssets(
        "assets/tetromino_sprite.png",
        "assets/background.png",
        "assets/game_over.png"
    );

    bool moveRotate = 0;
    int moveHorizontal = 0, tetrominoColorNum = 1 + rand() % MAX_COLORS;
    float timer = 0, fallSpeed = 0.3;

    Clock clock;
    EventHandler eventHandler(&moveHorizontal, &fallSpeed, &moveRotate);
    TetrominoController tetrominotController;
    Spawner spawner(&tetrominoColorNum);
    spawner.CreateFigure(currentPoint);

    while (window.isOpen() || !isGameOver)
    {
        // Norm frames for each PC
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        eventHandler.Handle(window);

        tetrominotController.Move(gameField, moveHorizontal, currentPoint, nextPoint);
        tetrominotController.Rotate(gameField, moveRotate, currentPoint, nextPoint);

        // Figures must fall for each frame or must be spawned new one
        if (timer > fallSpeed)
        {
            if (Validator::isBlocked(gameField, currentPoint)) {
                isGameOver = true;
                break;
            }

            for (int i = 0; i < FIGURE_SIZE; i++) {
                nextPoint[i] = currentPoint[i];
                currentPoint[i].y += 1;
            }

            if (Validator::isBlocked(gameField, currentPoint)) {
                spawner.Spawn(gameField, currentPoint, nextPoint);
            }

            timer = 0;
        }

        Validator::checkLines(gameField);

        moveHorizontal = 0;
        moveRotate = 0;
        fallSpeed = 0.3;

        render.Update(tetrominoColorNum, currentPoint);
    }

    if (isGameOver) {
        render.Display(Render::GameOver);
        sleep(milliseconds(2000));
        window.close();
    }

    return 0;
}
