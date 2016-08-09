#pragma once
#include <SFML\Graphics.hpp>
#include "Tile.h"

class MainGame
{
public:
	MainGame();
	void draw(sf::RenderTarget & target);
private:
	Tile m_tile;
};