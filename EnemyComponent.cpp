#include "EnemyComponent.h"

EnemyComponent::EnemyComponent()
{
}

EnemyComponent::~EnemyComponent()
{
}

void EnemyComponent::initialise()
{
	aiSystem.addComponentWithID(belongsTo);
	aiSystem.getComponentWithID(belongsTo).brain.grid = &LevelManager::tileMap;


	spriteSystem.addComponentWithID(belongsTo);
	spriteSystem.getComponentWithID(belongsTo).sprite.setPosition(
		aiSystem.getComponentWithID(belongsTo).brain.grid->tileMap[5][5].sprite.getPosition());

	positionSystem.addComponentWithID(belongsTo);
	positionSystem.getComponentWithID(belongsTo).position =
		spriteSystem.getComponentWithID(belongsTo).sprite.getPosition();

}

void EnemyComponent::update()
{
	
}
