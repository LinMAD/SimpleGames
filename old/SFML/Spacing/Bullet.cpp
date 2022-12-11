#include "Bullet.h"

Bullet::Bullet()
{
	_isPlayerSource = false;
}

Bullet::Bullet(
	Texture* texture,
	Vector2f pos,
	Vector2f dir,
	float movmentSpeed
)
{
	_isPlayerSource = false;
	_sprite.setTexture(*texture);
	_sprite.setPosition(pos);
	_direction = dir;
	_movmentSpeed = movmentSpeed;
}

void Bullet::setIsPlayerSource(bool isFromPlayer = true)
{
	_isPlayerSource = isFromPlayer;
}

bool Bullet::isSourceFromPlayer()
{
	return _isPlayerSource;
}

const FloatRect Bullet::getBounds() const
{
	return _sprite.getGlobalBounds();
}

const Vector2f Bullet::getPosition() const
{
	return _sprite.getPosition();
}

void Bullet::update()
{
	_sprite.move(_movmentSpeed * _direction);
}

void Bullet::render(RenderTarget* target)
{
	target->draw(_sprite);
}

void Bullet::setPosition(const Vector2f position)
{
	_sprite.setPosition(position);
}
