#include <SFML\Graphics.hpp>
#include "MainGame.h"

int main()
{
	const int TILE_SIZE = 128;
	const int TILES_NUMBER = 3;
	const int WINDOW_WIDTH = TILE_SIZE*TILES_NUMBER;
	const int WINDOW_HEIGHT = WINDOW_WIDTH;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic Tac Toe");

	MainGame game;

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			game.processEvent(event, window);
		}
		game.update(clock);
		game.draw(window);

		if (game.getIsGameOver())
		{
			window.close();
		}
		window.display();
	}

	return 0;
};