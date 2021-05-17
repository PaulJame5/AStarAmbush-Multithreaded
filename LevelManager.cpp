#include "LevelManager.h"


int LevelManager::currentLevelIndex = 0;
Grid LevelManager::tileMap;
std::vector<LevelBase> LevelManager::levels = std::vector<LevelBase>(0);
std::vector<std::string> LevelManager::levelNames = std::vector<std::string>(0);
std::vector<std::pair<int, int>> LevelManager::levelBounds = std::vector<std::pair<int, int>>(0);

LevelManager::LevelManager()
{
	std::cout << "LevelManagerCalled" << std::endl;
}

LevelManager::~LevelManager()
{
}

bool LevelManager::loadNextLevel()
{
	return false;
}

bool LevelManager::loadLevelAtIndex()
{
	return false;
}

bool LevelManager::loadLevelIndex(unsigned int level)
{
	decs::World::destroyAllEntities(true);
	tileMap.clear();
	int x = levelBounds.at(level).first;
	int y = levelBounds.at(level).second;
	tileMap = Grid(x, y, levelNames.at(level));

	return true;
}
