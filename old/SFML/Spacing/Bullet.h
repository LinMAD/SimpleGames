#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "AbstractProp.h"

using namespace sf;

class Bullet : public AbstractProp
{
private:
	Vector2f _direction;
	bool _isPlayerSource;
public:
	Bullet();
	Bullet(
		Texture* texture,
		Vector2f pos,
		Vector2f dir,
		float movmentSpeed
	);

	void setIsPlayerSource(bool isFromPlayer);

	bool isSourceFromPlayer();
	virtual const FloatRect getBounds() const override;
	virtual const Vector2f getPosition() const override;

	virtual void update() override;
	virtual void render(RenderTarget* target) override;

	virtual void setPosition(const Vector2f position) override;
};
