#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "AbstractProp.h"

using namespace sf;

class Enemy : public AbstractProp
{
protected:
	Texture _texture;

	int _type;
	int _hp, _hpMax;
	int _damage;
	unsigned _scorePoints;
	float _attackCd, _attackCdMax;

	void initAttributes();
	void initSprite();
	void initTexture();
public:
	Enemy();
	Enemy(Vector2f position);
	~Enemy();

	const bool isCanAttack();
	const unsigned getScorePoint();
	const int getDamage() const;

	virtual void update() override;
	virtual void render(RenderTarget* target) override;
	virtual const FloatRect getBounds() const override;
	virtual const Vector2f getPosition() const override;
	virtual void setPosition(const Vector2f position) override;
};

