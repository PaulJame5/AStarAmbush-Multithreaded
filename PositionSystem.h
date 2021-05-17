#pragma once
#ifndef POSITIONSYSTEM_H
#define POSITIONSYSTEM_H
#include "decs.h"
#include "PositionComponent.h"

class PositionSystem : public decs::System<PositionComponent>
{
public:
	PositionSystem() {};
	~PositionSystem() {};
};
#endif