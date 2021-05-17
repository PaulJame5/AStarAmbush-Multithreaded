#pragma once
#ifndef TILESYSTEM_H
#define TILESYSTEM_H
#include "TileCompoent.h"

class TileSystem : public decs::System<TileComponent>
{
public:
	TileSystem();
	~TileSystem();
	void draw(sf::RenderTarget& target);
};
#endif