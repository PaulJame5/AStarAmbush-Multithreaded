#include "Grid.h"

Grid::Grid()
{
}

Grid::Grid(int max_row, int max_col, std::string map)
{
	tileSystem.reserveComponentCapacity(max_row * max_col);
	tileSystem.reserveIDCapacity(max_row * max_col);
	this->max_col = max_col;
	this->max_row = max_row;
	std::vector<int> mapRead = std::vector<int>(0);
	ReadFromCSV::readTileMapIntoVector(mapRead, map);
	for (int x = 0; x < max_row; x++)
	{
		tileMap.push_back(std::vector<TileComponent>(0));

		for (int y = 0; y < max_col; y++)
		{
			int id = decs::World::createNewID();
			tileSystem.addComponentWithID(id);
			positionSystem.addComponentWithID(id);
			TileComponent& tc = tileSystem.getComponentWithID(id);
			if (mapRead.at((y * max_col) + x) == -1)
			{
				tc.cost = 0;
				tc.drawable = false;
			}
			else
			{
				tc.cost = 5;
				tc.drawable = true;
			}
			tc.parent_i = x;
			tc.parent_j = y;
			tc.sprite.setPosition(sf::Vector2f(CELL_SIZE * x, CELL_SIZE * y));
			positionSystem.getComponentWithID(id).position = tc.sprite.getPosition();
			tileMap[x].push_back(tc);

		}
	}
}
void Grid::clear()
{
	tileMap.clear();
}
