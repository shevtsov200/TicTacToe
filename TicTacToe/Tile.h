#pragma once
#include <SFML\Graphics.hpp>
class Tile : public sf::Drawable, public sf::Transformable
{
public:
	Tile();
	void setspriteSheet(sf::Texture & spriteSheet);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	sf::Sprite m_sprite;
	sf::Texture m_spriteSheet;
	sf::IntRect m_textureRectangle;
	int m_width, m_height, m_tileSize;
	sf::Vector2f m_position;
};