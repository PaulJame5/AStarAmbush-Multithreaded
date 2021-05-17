#pragma once
#include "Game.h"
#include "AStarAmbushBrain.h"
#include "LevelManager.h"

// Driver program to test above function
int main()
{
	//LevelManager levelManager;
	//// level 1
	//levelManager.levelNames.push_back("30x30.csv");
	//levelManager.levelBounds.push_back(std::pair(30, 30));

	//// Level Manager load first
	//levelManager.loadLevelIndex(0);

	//// Create our brain
	//AStarAmbushBrain brain;
	//brain.grid = &levelManager.tileMap;

	//// Source is the left-most bottom-most corner
	//std::pair<int,int> src = std:: make_pair(2, 1);

	//// Destination is the left-most top-most corner
	//std::pair<int, int> dest = std::make_pair(1, 1);

	//brain.aStarSearch(src, dest);


	Game game;
	game.run();

	system("pause");

	//return (0);
}
