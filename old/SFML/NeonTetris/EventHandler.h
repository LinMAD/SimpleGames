#pragma once

#include <SFML\Graphics\RenderWindow.hpp>

using namespace sf;

class EventHandler
{
protected:
	bool* _inputRotation;
	int* _inputHorizontal; // 0 initial, -1 left, 1 right
	float* _inputVertical;
public:
	EventHandler(int* horizontal, float* vertical, bool* rotation) : 
		_inputHorizontal(horizontal),
		_inputVertical(vertical), 
		_inputRotation(rotation)
	{}

	void Handle(RenderWindow& window);
};
