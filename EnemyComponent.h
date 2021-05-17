#pragma once
#ifndef EN_COMPONENT_H
#define EN_COMPONENT_H
#include "decs.h"
#include "PositionSystem.h"
#include "SpriteSystem.h"
#include "AISystem.h"
#include "LevelManager.h"

class EnemyComponent : public decs::Component
{
public:
	SpriteSystem spriteSystem;
	PositionSystem positionSystem;
	AISystem aiSystem;
	
	EnemyComponent();
	~EnemyComponent();

	void initialise() override;

	void update() override;
};
#endif