#pragma once
#ifndef LEVELBASE_H
#define LEVELBASE_H

class LevelBase
{
public:
	LevelBase();
	~LevelBase();

	//virtual void loadLevel() = 0;
	//virtual void desroyLevel() = 0;

	bool isLevelLoaded();

private:
	bool levelLoaded = false;
};
#endif