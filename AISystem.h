#pragma once
#ifndef AI_SYSTEM_H
#define AI_SYSTEM_H
#include "AIComponent.h"
#include "WorkThreads.h"
class AISystem : public decs::System<AIComponent>
{
public:
	AISystem();
	~AISystem();

	void update() override;
};

#endif
