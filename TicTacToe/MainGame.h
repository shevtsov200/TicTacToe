#pragma once
#include <SFML\Graphics.hpp>
#include "vector"
#include "Tile.h"

class MainGame
{
public:
	MainGame();
	void processEvent(sf::Event event, sf::Window &window);
	void update(sf::Clock clock);
	void draw(sf::RenderTarget & target) const;
private:
	std::vector<std::vector<Tile>> m_tiles;
	sf::Texture m_spriteSheet;

	const static int m_matrixSize = 3;
	const static int m_tileSize = 128;
};