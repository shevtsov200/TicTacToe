#pragma once
#include "SFML/Graphics.hpp"
class Screen
{
public:
	virtual int run(sf::RenderWindow &App) = 0;
};