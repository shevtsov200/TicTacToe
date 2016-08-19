#include "MainGame.h"

MainGame::MainGame() : m_tiles(m_matrixSize, std::vector<Tile>(m_matrixSize))
{
	m_spriteSheet.loadFromFile("resources/spriteSheet.png");
	for (int i = 0; i < m_matrixSize; i++)
	{
		for (int j = 0; j < m_matrixSize; j++)
		{
			m_tiles[i][j].setspriteSheet(m_spriteSheet);
			m_tiles[i][j].setPosition(sf::Vector2f(j*m_tileSize, i*m_tileSize));
		}
	}
	//m_tiles[0][0].setspriteSheet(m_spriteSheet);
}

void MainGame::update()
{
	for (int i = 0; i < m_matrixSize; i++)
	{
		for (int j = 0; j < m_matrixSize; j++)
		{
			m_tiles[i][j].update();
		}
	}
}

void MainGame::draw(sf::RenderTarget & target) const
{
	for (int i = 0; i < m_matrixSize; i++)
	{
		for (int j = 0; j < m_matrixSize; j++)
		{
			target.draw(m_tiles[i][j]);
		}
	}
	//target.draw(m_tiles[0][0]);
}
