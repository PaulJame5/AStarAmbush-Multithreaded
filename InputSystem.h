#pragma once
#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include <SFML/Graphics.hpp>
#include <iostream>

class InputSystem
{
public:
	InputSystem();
	~InputSystem();

	void update(sf::RenderWindow& window);

private:
	bool upPressed = false;
	bool upPressedLastFrame = false;
	bool upHeld = false;

	bool downPressed = false;
	bool downPressedLastFrame = false;
	bool downHeld = false;

	bool leftPressed = false;
	bool leftPressedLastFrame = false;
	bool leftHeld = false;

	bool rightPressed = false;
	bool rightPressedLastFrame = false;
	bool rightHeld = false;

};
#endif
