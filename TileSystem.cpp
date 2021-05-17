#include "TileSystem.h"
#include <iostream>
TileSystem::TileSystem()
{
}

TileSystem::~TileSystem()
{
}

void TileSystem::draw(sf::RenderTarget& target)
{
	std::vector<TileComponent>& tiles = entityManager.getDenseList();
	for (int i = 0; i < entityManager.getNumberOfActiveComponents(); i++)
	{
		if (tiles[i].drawable)
			target.draw(tiles[i].sprite);
	}
}