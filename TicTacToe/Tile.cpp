#include "Tile.h"

// TODO: Get rid of magic numbers.
Tile::Tile() : m_textureRectangle(0, 0, 128, 128)
{	
	
}

void Tile::setspriteSheet(sf::Texture & spriteSheet)
{
	m_spriteSheet = spriteSheet;
	m_sprite.setTexture(m_spriteSheet);
	m_sprite.setTextureRect(m_textureRectangle);
	m_sprite.setPosition(50, 50);
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
