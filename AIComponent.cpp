#include "AIComponent.h"

AIComponent::AIComponent()
{
	brain.grid = &levelManager.tileMap;
}

AIComponent::~AIComponent()
{
}

void AIComponent::aStarExecution()
{

}

void AIComponent::update()
{
	if (wait > 0)
	{
		wait -= 0.2f;
		return;
	}	
	brain.grid->tileMap[currentGridPosition.first][currentGridPosition.second].cost = 0;

	if (brain.aStarSearch(currentGridPosition, currentTargetGrid))
	{
		TileComponent tc = brain.tracePath(currentTargetGrid);
		sf::Vector2f oldPosition = positionSystem.getComponentWithID(belongsTo).position;
		positionSystem.getComponentWithID(belongsTo).position = sf::Vector2f(tc.parent_i * CELL_SIZE, tc.parent_j * CELL_SIZE);

		currentGridPosition.first = tc.parent_i;
		currentGridPosition.second = tc.parent_j;
	}
	
	wait = 0;
}
