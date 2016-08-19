#include "Tile.h"

// TODO: Get rid of magic numbers.
Tile::Tile() : m_textureRectangle(0, 0, m_tileSize, m_tileSize)
{	
	m_state = EMPTY;
}

void Tile::setspriteSheet(sf::Texture & spriteSheet)
{
	m_spriteSheet = spriteSheet;
	m_sprite.setTexture(m_spriteSheet);
	m_sprite.setTextureRect(m_textureRectangle);
}

void Tile::setPosition(sf::Vector2f position)
{
	m_position = position;
}

void Tile::setState(states state)
{
	m_state = state;
}

void Tile::update()
{
	int spriteNumber;
	m_sprite.setPosition(m_position);
	switch (m_state)
	{
		case EMPTY: spriteNumber = 0;
			break;
		case CROSS: spriteNumber = 1;
			break;
		case ZERO: spriteNumber = 2;
			break;
	}
	m_textureRectangle.left = m_tileSize*spriteNumber;
	m_sprite.setTextureRect(m_textureRectangle);
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}

sf::Sprite Tile::getSprite() const
{
	return m_sprite;
}
