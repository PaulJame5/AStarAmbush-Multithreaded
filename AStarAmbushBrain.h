#pragma once
#ifndef ASTAR_BRAIN_H
#define ASTAR_BRAIN_H

#include "SFML/Graphics.hpp"
#include <algorithm>
#include <stack>
#include <set>
#include "decs.h"
#include "Grid.h"
#include "PositionSystem.h"

class AStarAmbushBrain
{
public:
	AStarAmbushBrain();
	~AStarAmbushBrain();

	PositionSystem positionSystem;

	static Grid* grid;
	std::vector<std::vector<TileComponent>> cellDetails;

	// A Utility Function to check whether given cell (row, col)
	// is a valid cell or not.
	bool isValid(int row, int col);

	// A Utility Function to check whether the given cell is
	// blocked or not
	bool isUnBlocked(int row, int col);

	// A Utility Function to check whether destination cell has
	// been reached or not
	bool isDestination(int row, int col, std::pair<int, int> dest);

	// A Utility Function to calculate the 'h' heuristics.
	double calculateHValue(int row, int col, std::pair<int, int> dest);

	// A Utility Function to trace the path from the source
	// to destination
	TileComponent tracePath(std::pair<int, int> dest);

	// A Function to find the shortest path between
	// a given source cell to a destination cell according
	// to A* Search Algorithm
	bool aStarSearch(std::pair<int, int> src, std::pair<int, int> dest);
};
#endif