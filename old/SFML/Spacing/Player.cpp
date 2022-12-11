#include <iostream>
#include "Player.h"

void Player::initAttributes()
{
	_isDead = false;
	_scorePoints = 0;
	_hpMax = 10;
	_hp = _hpMax;
	_movmentSpeed = 4.f;
	_attackCdMax = 8.f;
	_attackCd = _attackCdMax;
}

void Player::initSprite()
{
	_sprite.setTexture(_texture);
}

void Player::initTexture()
{
	if (!_texture.loadFromFile("assets/sprites/Player.png"))
	{
		std::cout << "Error::Player -> Failed to load sprite\n";
	}
}

Player::Player()
{
	initAttributes();
	initTexture();
	initSprite();
}

void Player::takeDamage(const int damage)
{
	if (_isDead) return;

	_hp -= damage;
	if (_hp <= 0)
	{
		_hp = 0;
		_isDead = true;
	}
}

void Player::addScorePoints(unsigned point)
{
	_scorePoints += point;
}

int Player::getHp()
{
	return _hp;
}

const int Player::getHpMax() const
{
	return _hpMax;
}

void Player::move(const float dirX, const float dirY)
{
	_sprite.move(_movmentSpeed * dirX, _movmentSpeed * dirY);
}

const bool Player::isCanAttack()
{
	if (_attackCd >= _attackCdMax)
	{
		_attackCd = 0.f;
		return true;
	}

	return false;
}

const bool Player::isDead()
{
	return _isDead;
}

void Player::updateAttack()
{
	if (_attackCd < _attackCdMax)
		_attackCd += 0.5f;
}

void Player::update()
{
	updateAttack();
}

void Player::render(RenderTarget* target)
{
	target->draw(_sprite);
}
