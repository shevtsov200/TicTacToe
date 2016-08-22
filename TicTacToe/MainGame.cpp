#include "MainGame.h"

MainGame::MainGame() : m_tiles(m_matrixSize, std::vector<Tile>(m_matrixSize))
{
	m_isGameOver = false;
	m_spriteSheet.loadFromFile("resources/spriteSheet.png");
	for (int i = 0; i < m_matrixSize; i++)
	{
		for (int j = 0; j < m_matrixSize; j++)
		{
			m_tiles[i][j].setspriteSheet(m_spriteSheet);
			m_tiles[i][j].setPosition(sf::Vector2f(j*m_tileSize, i*m_tileSize));
		}
	}
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
	Tile::states winner = checkWinningCondition();
	if ( winner != Tile::EMPTY)
	{
		endGame(winner);
	}
}

Tile::states MainGame::checkWinningCondition()
{
	Tile::states winner = Tile::EMPTY;
	for (int i = 0; i < m_matrixSize; i++)
	{
		//***
		
		if ((m_tiles[i][0].getState() == m_tiles[i][1].getState()) && (m_tiles[i][0].getState() == m_tiles[i][2].getState()))
		{
			winner = m_tiles[i][0].getState();
			break;
		}
		//*
		//*
		//*
		else if ((m_tiles[0][i].getState() == m_tiles[1][i].getState()) && (m_tiles[0][i].getState() ==  m_tiles[2][i].getState()))
		{
			winner = m_tiles[0][i].getState();
			break;
		}
	}
	//*--
	//-*-
	//--*
	if ((m_tiles[0][0].getState() == m_tiles[1][1].getState()) && (m_tiles[0][0].getState() == m_tiles[2][2].getState()))
	{
		winner = m_tiles[0][0].getState();
	}
	//--*
	//-*-
	//*--
	else if ((m_tiles[0][2].getState() == m_tiles[1][1].getState()) && (m_tiles[0][2].getState() == m_tiles[2][0].getState()))
	{
		winner = m_tiles[0][2].getState();
	}
	return winner;

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
}

void MainGame::endGame(Tile::states winner)
{
	m_isGameOver = true;
}

bool MainGame::getIsGameOver() const
{
	return m_isGameOver;
}
