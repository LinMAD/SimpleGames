#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

class AbstractProp
{
protected:
	Sprite _sprite;
	float _movmentSpeed;
public:
	virtual const FloatRect getBounds() const = 0;
	virtual const Vector2f getPosition() const = 0;
	virtual void setPosition(const Vector2f position) = 0;

	virtual void update() = 0;
	virtual void render(RenderTarget* target) = 0;
};

