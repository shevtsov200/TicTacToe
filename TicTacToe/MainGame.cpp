#include "MainGame.h"

MainGame::MainGame() : m_tile(sf::Vector2f(100, 100), 128, 128)
{
	
}

void MainGame::draw(sf::RenderTarget & target)
{
	target.draw(m_tile);
}
