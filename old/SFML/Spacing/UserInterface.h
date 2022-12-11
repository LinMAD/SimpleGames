#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "AbstractProp.h"
#include "Player.h"

using namespace sf;


class UserInterface : public AbstractProp
{
private:
	Font _uiFont;
	Text _uiPlayerScoreText;
	Text _uiPlayerHpText;
	Text _uiGameOverText;

	RectangleShape _uiPlayerHpBar;
	RectangleShape _uiPlayerHpBarBack;

	Player* _player;
	Vector2u _screenSize;

	void initGUI();
public:
	UserInterface();
	UserInterface(Player* player, Vector2u screenSize);

	void showGameOver(RenderTarget* target);

	virtual void update() override;
	virtual void render(RenderTarget* target) override;

	virtual const FloatRect getBounds() const override;
	virtual const Vector2f getPosition() const override;

	virtual void setPosition(const Vector2f position) override;
};

