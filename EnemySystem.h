#pragma once
#ifndef EN_SYSTEM_H
#define EN_SYSTEM_H
#include "EnemyComponent.h"


class EnemySystem : public decs::System<EnemyComponent>
{
public:
	EnemySystem();
	~EnemySystem();

	void update() override;
private:

};
#endif