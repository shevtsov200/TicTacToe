#pragma once
#include <SFML\Graphics.hpp>
class Tile : public sf::Drawable, public sf::Transformable
{
public:
	Tile(sf::Vector2f position, int width, int height);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	int m_width, m_height;
	sf::Vector2f m_position;
};