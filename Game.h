#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "InputSystem.h"
#include "TileSystem.h"
#include "LevelManager.h"
#include "EnemySystem.h"
#include "SpriteSystem.h"
#include "AISystem.h"
#include "WorkThreads.h"

class Game
{
public :
	Game();
	~Game();

	void run();
private:
	InputSystem inputSystem;
	TileSystem tileSystem;
	LevelManager levelManager;
	EnemySystem enemySystem;
	SpriteSystem spriteSystem;
	AISystem aiSystem;

	void render(sf::RenderWindow& target);
};
#endif // GAME_H