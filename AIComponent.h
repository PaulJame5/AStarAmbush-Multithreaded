#pragma once
#include "decs.h"
#include "AStarAmbushBrain.h"
#include "LevelManager.h"
# include "TileCompoent.h"
#include "PositionSystem.h"

class AIComponent : public decs::Component
{
public:
	AIComponent();
	~AIComponent();

	PositionSystem positionSystem;
	float wait = 2;
	AStarAmbushBrain brain;
	LevelManager levelManager;
	std::pair<int, int> currentTargetGrid;
	std::pair<int, int> currentGridPosition;
	sf::Vector2f targetWorldPosition;
	void aStarExecution();
	void update() override;

private:
};