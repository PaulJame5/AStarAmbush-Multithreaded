#include "Game.h"
Game::Game()
{
	// level 1
	//levelManager.levelNames.push_back("30x30.csv");
	//levelManager.levelBounds.push_back(std::pair(30, 30));
	// level2
	levelManager.levelNames.push_back("100x100.csv");
	levelManager.levelBounds.push_back(std::pair<int,int>(100, 100));

	// Level Manager load first
	levelManager.loadLevelIndex(0);
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			int id = decs::World::createNewID();
			enemySystem.addComponentWithID(id);
			aiSystem.getComponentWithID(id).currentGridPosition = std::make_pair(1 + x, 5 + y);
			aiSystem.getComponentWithID(id).currentTargetGrid = std::make_pair(96, 96);
		}
	}

}

Game::~Game()
{
}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "A*mbush");

	while (window.isOpen())
	{
		inputSystem.update(window);
		aiSystem.update();

		WorkThread::subsystemPool.finishExectuion();
		window.clear();
		render(window);
		window.display();
	}
}

void Game::render(sf::RenderWindow& target)
{
	tileSystem.draw(target);
	spriteSystem.draw(target);
}
