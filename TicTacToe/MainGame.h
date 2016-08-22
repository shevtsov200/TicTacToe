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
	Tile::states checkWinningCondition();
	void draw(sf::RenderTarget & target) const;
	void endGame(Tile::states winner);
	bool getIsGameOver() const;
private:
	std::vector<std::vector<Tile>> m_tiles;
	sf::Texture m_spriteSheet;
	bool m_isGameOver;
	const static int m_matrixSize = 3;
	const static int m_tileSize = 128;
};