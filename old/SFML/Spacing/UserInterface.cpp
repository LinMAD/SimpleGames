#include <iostream>
#include <string>
#include <sstream>
#include "UserInterface.h"

void UserInterface::initGUI()
{
	if (!_uiFont.loadFromFile("assets/font/subwt.ttf"))
	{
		std::cout << "Error::UserInterface -> Failed to load font\n";
	}

	_uiPlayerScoreText.setFont(_uiFont);
	_uiPlayerScoreText.setCharacterSize(20);
	_uiPlayerScoreText.setFillColor(Color::White);

	_uiPlayerHpText = _uiPlayerScoreText;
	_uiGameOverText = _uiPlayerScoreText;

	_uiPlayerScoreText.setString("Score: ");
	_uiPlayerScoreText.setFillColor(Color::Blue);
	_uiPlayerScoreText.setPosition(Vector2f(10.f, _screenSize.y - 80.f));

	_uiPlayerHpText.setString("Health");
	_uiPlayerHpText.setPosition(Vector2f(20.f, _screenSize.y - 40.f));

	_uiGameOverText.setString("Game over");
	_uiGameOverText.setCharacterSize(60);
	_uiGameOverText.setFillColor(Color::Red);
	_uiGameOverText.setPosition(Vector2f(100.f, _screenSize.y >> 1));

	_uiPlayerHpBar.setSize(Vector2f(100.f, 20.f));
	_uiPlayerHpBar.setFillColor(Color(220, 20, 60, 150));
	_uiPlayerHpBar.setPosition(Vector2f(0.f, _screenSize.y - 40.f));

	_uiPlayerHpBarBack = _uiPlayerHpBar;
	_uiPlayerHpBarBack.setFillColor(Color(25, 25, 25, 150));
}

UserInterface::UserInterface()
{
	initGUI();
}

UserInterface::UserInterface(Player* player, Vector2u screenSize)
{
	_player = player;
	_screenSize = screenSize;

	initGUI();
}

void UserInterface::showGameOver(RenderTarget* target)
{
	target->draw(_uiGameOverText);
}

void UserInterface::update()
{
	int p = _player->getScorePoint();
	float hpProcent = 100.f / _player->getHpMax() * _player->getHp();
	std::stringstream stream;
	stream << "Score: " << _player->getScorePoint();

	_uiPlayerScoreText.setString(stream.str());
	_uiPlayerHpBar.setSize(Vector2f(hpProcent, 20.f));
}

void UserInterface::render(RenderTarget* target)
{
	target->draw(_uiPlayerScoreText);
	target->draw(_uiPlayerHpBarBack);
	target->draw(_uiPlayerHpBar);
	target->draw(_uiPlayerHpText);
}

const FloatRect UserInterface::getBounds() const
{
	return FloatRect();
}

const Vector2f UserInterface::getPosition() const
{
	return Vector2f();
}

void UserInterface::setPosition(const Vector2f position)
{
}
