#include "Render.h"

void Render::LoadAssets(
    const string& pathToTetromino,
    const string& pathToBackground,
    const string& pathToGameOver
)
{
    _texTetromino.loadFromFile(pathToTetromino);
    _texBackground.loadFromFile(pathToBackground);
    _texGameOver.loadFromFile(pathToGameOver);

    _tetromino.setTexture(_texTetromino);
    _background.setTexture(_texBackground);
    _gameOver.setTexture(_texGameOver);
}

void Render::Update(int tetrominoColorNum, Point* from)
{
    _window.clear(Color::White);
    _window.draw(_background);

    for (int i = 0; i < FIELD_HEIGHT; i++)
        for (int j = 0; j < FIELD_WIDTH; j++)
        {
            if (_gameField[i][j] == 0)
                continue;

            _tetromino.setTextureRect(
                IntRect(_gameField[i][j] * 18, 0, 18, 18)
            );
            _tetromino.setPosition(j * 18, i * 18);
            _tetromino.move(28, 31);

            _window.draw(_tetromino);
        }

    for (int i = 0; i < FIGURE_SIZE; i++)
    {
        _tetromino.setTextureRect(
            IntRect(tetrominoColorNum * 18, 0, 18, 18)
        );
        _tetromino.setPosition(from[i].x * 18, from[i].y * 18);
        _tetromino.move(28, 31);

        _window.draw(_tetromino);
    }

    _window.display();
}

void Render::Display(Displays display)
{
    _window.clear(Color::White);

    switch (display)
    {
        case GameOver:
            _window.draw(_gameOver);
            break;
        default:
            break;
    }

    _window.display();
}
