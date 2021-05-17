#pragma once
#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H
#include "decs.h"
#include <SFML/Graphics.hpp>
#include "Constants.h"

class TileComponent : public decs::Component
{
public:
	TileComponent() {};
	~TileComponent() {};

	void initialise() override {};

	sf::Vector2f position;
	int cost = 1;


	sf::RectangleShape sprite = sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));

	int parent_i, parent_j;
	// f = g + h
	double f, g, h;

	bool drawable = false;

	// A structure to hold the neccesary parameters
	struct cell {
		// Row and Column index of its parent
		// Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
		int parent_i, parent_j;
		// f = g + h
		double f, g, h;
	};

};
#endif