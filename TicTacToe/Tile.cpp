#include "Tile.h"

Tile::Tile(sf::Vector2f position, int width, int height)
{
	m_texture.loadFromFile("resources/tile.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
