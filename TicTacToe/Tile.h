#pragma once
#include <SFML\Graphics.hpp>
class Tile : public sf::Drawable, public sf::Transformable
{
public:
	enum states { EMPTY, CROSS, ZERO};

	Tile();
	void update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Sprite getSprite() const;
	Tile::states getState() const;
	void setspriteSheet(sf::Texture & spriteSheet);
	void setPosition(sf::Vector2f position);
	void setState(states state);
private:
	sf::Sprite m_sprite;
	sf::Texture m_spriteSheet;
	sf::IntRect m_textureRectangle;
	int m_width, m_height;
	sf::Vector2f m_position;
	states m_state;
	const static int m_tileSize = 128;
};