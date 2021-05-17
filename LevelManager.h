#pragma once
#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H
#include "LevelBase.h"
#include "Grid.h"
#include <vector>
#include <string>
#include <algorithm>

class LevelManager
{
public:
	LevelManager();
	~LevelManager();

	bool loadNextLevel();
	bool loadLevelAtIndex();

	bool loadLevelIndex(unsigned int level);


	static std::vector<LevelBase> levels;

	static Grid tileMap;

	static std::vector<std::string> levelNames;
	static std::vector<std::pair<int, int>> levelBounds;
private:
	static int currentLevelIndex;
};
#endif