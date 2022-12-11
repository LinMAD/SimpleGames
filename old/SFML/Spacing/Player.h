#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Enemy.h"

using namespace sf;

class Player : public Enemy
{
private:
	void initAttributes();
	void initSprite();
	void initTexture();

	bool _isDead;
public:
	Player();

	void move(const float dirX, const float dirY);
	const bool isCanAttack();
	const bool isDead();

	void updateAttack();

	void takeDamage(const int damage);

	void addScorePoints(unsigned point);

	int getHp();
	const int getHpMax() const;

	virtual void update() override;
	virtual void render(RenderTarget* target) override;
};

