#pragma once
#ifndef GRID_H
#define GRID_H
#include "TileSystem.h"
#include "ReadFromCSV.h"
#include "PositionSystem.h"
#include <iostream>

class Grid
{
public:
	Grid();
	Grid(int max_row, int max_col, std::string map);

	TileSystem tileSystem;
	PositionSystem positionSystem;

	void clear();
	int max_row, max_col;
	std::vector<std::vector<TileComponent>> tileMap;
};
#endif