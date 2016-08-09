#include "Tile.h"

Tile::Tile()
{

}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
