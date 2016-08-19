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

void MainGame::processEvent(sf::Event event, sf::Window &window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		for (int i = 0; i < m_matrixSize; i++)
		{
			for (int j = 0; j < m_matrixSize; j++)
			{
				if (m_tiles[i][j].getSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))))//(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						m_tiles[i][j].setState(Tile::CROSS);
					}
					else if (event.mouseButton.button == sf::Mouse::Right)
					{
						m_tiles[i][j].setState(Tile::ZERO);
					}
				}
			}
		}
	}
}

void MainGame::update(sf::Clock clock)
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
