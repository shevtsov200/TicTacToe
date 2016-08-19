#include "MainGame.h"

MainGame::MainGame() : m_tiles(m_matrixSize, std::vector<Tile>(m_matrixSize))
{
	m_spriteSheet.loadFromFile("resources/spriteSheet.png");
	m_tiles[0][0].setspriteSheet(m_spriteSheet);
}

void MainGame::draw(sf::RenderTarget & target) const
{
	target.draw(m_tiles[0][0]);
}
