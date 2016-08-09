#pragma once
#include <SFML\Graphics.hpp>
class Tile : public sf::Drawable, public sf::Transformable
{
public:
	Tile();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	sf::Sprite m_sprite;
	int m_width, m_height;
	sf::Vector2f m_position;
};