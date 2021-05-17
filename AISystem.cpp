#include "AISystem.h"

AISystem::AISystem()
{
}

AISystem::~AISystem()
{
}

void AISystem::update()
{
	std::vector<AIComponent>& list = getDenseList();
	int size = getNumberOfActiveComponents();
	for (int i = 0; i < size; i++)
	{
		//list[i].update();
		WorkThread::subsystemPool.addJob(&AIComponent::update, &list[i]);
	}
}
