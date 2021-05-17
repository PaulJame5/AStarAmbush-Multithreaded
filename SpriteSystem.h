#pragma once
#ifndef SPRITESYSTEM_H
#define SPRITESYSTEM_H
#include "SpriteComponent.h"
#include "PositionSystem.h"
#include "WorkThreads.h"


class SpriteSystem : public decs::System<SpriteComponent>
{
public:
	PositionSystem positionSystem;

	void draw(sf::RenderTarget& target)
	{
		int activeComponents = getNumberOfActiveComponents();
		if (activeComponents == 0)
		{
			return;
		}

		std::vector<SpriteComponent>& list = getDenseList();
		std::vector<PositionComponent>& posList = positionSystem.getDenseList();
		for (int i = 0; i < activeComponents; i++)
		{
			SpriteComponent& spriteComponent = list[i];
			if (spriteComponent.isActive() == false)
			{
				continue;
			}
			// Match our sprite position to position component
			spriteComponent.sprite.setPosition(posList[i].position);
			target.draw(spriteComponent.sprite);
		}
	}
};
#endif
