#include <iostream>
#include "Enemy.h"

void Enemy::initAttributes()
{
	_type = 0;
	_hp = 1;
	_hpMax = 10;
	_damage = 1;
	_attackCdMax = 15.f;
	_attackCd = _attackCdMax;
	_movmentSpeed = rand() % 2 + (rand() % 5 * 0.5f);
	_scorePoints = rand() % 5 + 1 + (unsigned)_movmentSpeed;
}

void Enemy::initSprite()
{
	_sprite.setTexture(_texture);
}

void Enemy::initTexture()
{
	bool isLoaded = false;
	//unsigned variant = rand() % 3 + 1;
	unsigned variant = 1;

	switch (variant)
	{
	case 1:
		isLoaded = _texture.loadFromFile("assets/sprites/Enemy_1.png");
		break;
	case 2:
		isLoaded = _texture.loadFromFile("assets/sprites/Enemy_2.png");
		break;
	case 3:
		isLoaded = _texture.loadFromFile("assets/sprites/Enemy_3.png");
		break;
	default:
		std::cout << "Error::Enemy -> Failed to find sprite\n";
		break;
	}

	if (!isLoaded)
		std::cout << "Error::Enemy -> Failed to load sprite\n";
}

Enemy::Enemy()
{
	initTexture();
	initSprite();
	initAttributes();
}

Enemy::Enemy(Vector2f position)
{
	initTexture();
	initSprite();
	initAttributes();

	_sprite.setPosition(position);
}

Enemy::~Enemy()
{
}

const FloatRect Enemy::getBounds() const
{
	return _sprite.getGlobalBounds();
}

const bool Enemy::isCanAttack()
{
	if (_movmentSpeed <= 2.f && _attackCd >= _attackCdMax)
	{
		_attackCd = 0.f;
		return true;
	}

	return false;
}

const unsigned Enemy::getScorePoint()
{
	return _scorePoints;
}

const int Enemy::getDamage() const
{
	return _damage;
}

void Enemy::update()
{
	_sprite.move(0.f, _movmentSpeed);
}

void Enemy::render(RenderTarget* target)
{
	target->draw(_sprite);
}

const Vector2f Enemy::getPosition() const
{
	return _sprite.getPosition();
}

void Enemy::setPosition(const Vector2f position)
{
	_sprite.setPosition(position);
}

