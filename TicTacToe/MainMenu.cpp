#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	m_playing = false;
};
int MainMenu::run(sf::RenderWindow &app)
{
	sf::Event event;
	bool running = true;
	sf::Font font;
	sf::Text playButton;
	sf::Text exitButton;
	int menu = 0;

	font.loadFromFile("resources/verdanab.ttf");

	playButton.setFont(font);
	playButton.setCharacterSize(20);
	playButton.setString("Play");
	playButton.setPosition(0, 20);

	exitButton.setFont(font);
	exitButton.setCharacterSize(20);
	exitButton.setString("Exit");
	exitButton.setPosition(0, 280);

	playButton.setColor(sf::Color::Black);
	exitButton.setColor(sf::Color::Black);
	while (running)
	{
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return(-1);
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return)
				{
					m_playing = true;
					return(1);
				}
			}
		}
	}

	app.clear();

	app.draw(playButton);
	app.draw(exitButton);
	app.display();
}