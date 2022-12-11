#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Settings.h"

using namespace sf;
using namespace std;
using namespace settings;

class Render
{
protected:
	RenderWindow& _window;

	Texture _texTetromino;
	Texture _texBackground;
	Texture _texGameOver;

	Sprite _tetromino;
	Sprite _background;
	Sprite _gameOver;

	int (&_gameField)[FIELD_HEIGHT][FIELD_WIDTH];
public:
	static enum Displays { GameOver };

	Render(
		RenderWindow& window,
		int (&gameField)[FIELD_HEIGHT][FIELD_WIDTH]
	) 
		: _window(window), _gameField(gameField)
	{
	}

	void LoadAssets(
		const string& pathToTetromino,
		const string& pathToBackground,
		const string& pathToGameOver
	);

	void Update(int tetrominoColorNum, Point* from);
	void Display(Displays display);
};

