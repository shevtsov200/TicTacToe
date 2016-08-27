#pragma once
#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "vector"
#include "Tile.h"

class MainGame : public Screen
{
public:
	MainGame();
	virtual int run(sf::RenderWindow &app);
	void processEvent(sf::Event event, sf::Window &window);
	void update();
	Tile::states checkWinningCondition();
	void draw(sf::RenderTarget & target) const;
	void endGame(Tile::states winner);
	bool getIsGameOver() const;
	std::vector<std::vector<Tile>> & getTilesVector();
private:
	//Tile::states ifCellsEqual(std::vector<std::vector<Tile>> & tiles, sf::Vector2i firstTile, sf::Vector2i secondTile, sf::Vector2i thirdTile);
	bool ifCellsEqual(std::vector<std::vector<Tile>> & tiles, sf::Vector2i firstTile, sf::Vector2i secondTile, sf::Vector2i thirdTile);

	std::vector<std::vector<Tile>> m_tiles;
	sf::Texture m_spriteSheet;
	bool m_isGameOver;
	const static int m_matrixSize = 3;
	const static int m_tileSize = 128;
};