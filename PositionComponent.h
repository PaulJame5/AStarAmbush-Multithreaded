#pragma once
#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H
#include "decs.h"
#include <SFML/Graphics.hpp>

class PositionComponent : public decs::Component
{
public:
	PositionComponent() {  };
	~PositionComponent() {  };

	sf::Vector2f position;

	void initialise() override
	{
		position = { 0, 0 };
	};



};
#endif