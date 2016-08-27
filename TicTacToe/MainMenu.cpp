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

	//TODO: Replace this horrible button system with a list.

	playButton.setFont(font);
	playButton.setCharacterSize(20);
	playButton.setString("Play");
	playButton.setPosition(0, 20);

	exitButton.setFont(font);
	exitButton.setCharacterSize(20);
	exitButton.setString("Exit");
	exitButton.setPosition(0, 280);

	playButton.setColor(sf::Color::White);
	exitButton.setColor(sf::Color::White);
	while (running)
	{
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return(-1);
			}
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (menu > 0)
					menu -= 1;
				else
					menu = 2;
				break;
			case sf::Keyboard::Down:
				if (menu < 2)
					menu += 1;
				else
					menu = 0;
				break;
			case sf::Keyboard::Return:
				if (menu == 0)
				{
					m_playing = true;
					return(1);
				}
				else
				{
					return (-1);
				}
				break;
			default:
				break;
			}
		}
		if (menu == 0)
		{
			playButton.setColor(sf::Color::Red);
			exitButton.setColor(sf::Color::White);
		}
		else if (menu == 1)
		{
			playButton.setColor(sf::Color::White);
			exitButton.setColor(sf::Color::Red);
		}
		app.clear();
		app.draw(playButton);
		app.draw(exitButton);
		app.display();
	}
	return(-1);
}